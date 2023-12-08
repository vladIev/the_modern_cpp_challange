# The modern C++ challange

This repository contains my solutions for tasks from the book ["The modern C++ Challenge" by Marius Bancila](https://www.packtpub.com/product/the-modern-c-challenge/9781788993869)

* [Chapter 1. Math problems](https://github.com/vladIev/the_modern_cpp_challange/tree/main/src/math_problems)
* [Chapter 2. Language features](https://github.com/vladIev/the_modern_cpp_challange/tree/main/src/language_features)
* [Chapter 3. Strings and regexps](https://github.com/vladIev/the_modern_cpp_challange/tree/main/src/strings_and_regexps)
* [Chapter 4. Streams and filesystem](https://github.com/vladIev/the_modern_cpp_challange/tree/main/src/streams_and_filesystem)
* [Chapter 5. Date and time](https://github.com/vladIev/the_modern_cpp_challange/tree/main/src/date_and_time)
* [Chapter 6. Algorithms and data structures](https://github.com/vladIev/the_modern_cpp_challange/tree/main/src/algorithms_and_data_structures)
* [Chapter 7. Concurrency](https://github.com/vladIev/the_modern_cpp_challange/tree/main/src/concurrency)
* [Chapter 8. Design patterns](https://github.com/vladIev/the_modern_cpp_challange/tree/main/src/design_patterns)
* [Chapter 9. Data serialization](https://github.com/vladIev/the_modern_cpp_challange/tree/main/src/data_serialization)

## How to build

```
cd ${WorkspaceFolder}
conan install . --build=missing -of=build
cd build
cmake --preset=conan-default ..
cmake --build . --config Release
```