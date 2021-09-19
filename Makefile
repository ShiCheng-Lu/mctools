CXX=g++ 
CXXFLAGS=-std=c++14 -Wall -O -g -MMD -Werror=vla # use -MMD to generate dependencies

INCLUDE=-I./features
SOURCES=$(wildcard */src/*.cc) $(wildcard src/*.cc) # list of all .cc files in the current directory
OBJECTS=${SOURCES:.cc=.o}  # .o files depend upon .cc files with same names
DEPENDS=${OBJECTS:.o=.d}   # .d file is list of dependencies for corresponding .cc file
EXEC=mctools

LDLIBS= -lgdi32

# First target in the makefile is the default target.
# Note that the LIBFLAGS must come last in the command
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC) $(LDLIBS) $(INCLUDE)

-include ${DEPENDS}

.PHONY: clean
clean:
	del $(subst /,\,$(OBJECTS)) $(subst /,\,$(DEPENDS))
