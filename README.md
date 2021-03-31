# link_test
Testing linkage of function local statics

Answer to the question:

I have a `inline` function with a function local static defined in a header like so:

```
///< singleton.hpp

inline int& instance(){
   static int v;
   return v;
}
```

I include `header.hpp` into two, independent shared objects `A.so` and `B.so`. 
I link both `A.so` and `B.so` against my executable `main`. 

**Question**: Do `A.so` and `B.so` see the same function local static object? 
In other words, if I modify `v` from `A.so` like `instance() = 42`, is that visible from `B.so`?

**Answer**: Yes! A.so and B.so see the same object. 

Further Info:

As further evidence, one can inspect the produced binaries with `nm` to see the symbol table.

```
jhemstad@jh-ws:~/link_test/build$ nm -C ./libA.so 
0000000000201020 B __bss_start
...
0000000000000610 T A::get()
0000000000000600 T A::set(int)
0000000000201024 u instance()::v
```

We see that the function local static, `instance()::v` is marked with the `u` symbol. This symbol means:

>  "u" The symbol is a unique global symbol.  This is a GNU extension to the standard set of ELF
>               symbol bindings.  For such a symbol the dynamic linker will make sure that in the entire
>               process there is just one symbol with this name and type in use.

Note that this is unique to Linux. On Windows, the functional local static will be unique to each dll. 

StackOverflow Question: https://stackoverflow.com/questions/62336104/are-function-local-static-objects-of-inline-functions-shared-across-shared-objec
