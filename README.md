# link_test
Testing linkage of function local statics

Answer to the question:

I have a `inline` function with a function local static defined in a header like so:

```///< singleton.hpp

inline int& instance(){
   static int v;
   return v;
}```

I include `header.hpp` into two, independent shared objects `A.so` and `B.so`. 
I link both `A.so` and `B.so` against my executable `main`. 
Do `A.so` and `B.so` see the same function local static object? 
In other words, if I modify `v` from `A.so` like `fls() = 42`, is that visible from `B.so`?

Answer: Yes! A.so and B.so see the same object. 
