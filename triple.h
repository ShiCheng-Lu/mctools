

template <class T>
class triple {
   public:
    T x, y, z;
    triple(T x, T y, T z);
    
    triple<T> operator+(triple<T> &other);
};
