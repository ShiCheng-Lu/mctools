
run `cmake -S . -B build` to build the makefile

then `mingw32-make -C build`

then `mt.exe -manifest mcTools.manifest -outputresource:build/mcTools.exe;1`

run with `build/mcTools`
