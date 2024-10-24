What does Hello World look like?
-
![hello](/images/helloworld.png)

How to use?
-
Begin by cloning the repo. Make sure to have ninja, clang and re2c installed on your computer.
```
git clone https://github.com/galileolajara/glc.git
cd glc
ninja
```
Then checkout the examples:
```
cd examples/02-methods
ninja
out/methods
```

GLC is a programming language for people who love the simplicity of C language and are looking for a language that can take advantage of C's features.
-
The main goal of GLC is to provide a good programming experience:
- With very fast compilation speed and very fast incremental compilation
- That will help them use C in simplistic and concise way
- That will help them organize and shorten thier codes using namespaces
- That gives them an ability to use methods on structs, unions and typedefs
- You can build tools that easily parses GLC codes because GLC have tools-friendly syntax
- and still be able to use C's features and tools because GLC outputs C source files

GLC compared to Zig, Odin, V, C3, Rust, Cppfront
-
- Strings are just array of chars, just like C.
- No templates, no compile-time execution, just like C. But hey, you can do metaprogramming with scripts, aren't ya?
- No safety features, just like C. But you can use AddressSanitizer and the likes of it, just like in C.
- No built-in memory management, just like C. But feel free to use Boehm GC, just like in C.
- No defer, no inheritance, no run-time polymorphism, just like C. But we have a different kind of polymorphism! Just read more.
- If you think GLC have very few features unlike the other languages, it is because GLC is trying to be fast and simple, just like C!

Primary Objective of GLC
-
The development of GLC started in 2012 when I'm involved in programming mobile games and needed a language that have fast incremental compilation speed.
During that time, I was a fan of mobile CPUs such as Intel Atom hence GLC was born out of a necessity to really have fast compilation speeds.
If you are searching for a language that compilation speed is #1 problem that's being solved, you might want to try GLC.

How old is GLC?
-
GLC have been around more than a decade but I didn't share it to public because its codebase was written in a very quick and dirty way.
GLC is self-hosted, meaning GLC is written in GLC since 2012. I rewrote GLC with (hopefully) a cleaner codebase around September - October 2024,
and started uploading it here on Github once I got it to self-host for the second time.
