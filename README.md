# Learn C
A personal compiler on reviewing C basics.

## Tests
(Based on [this GoogleTest guide](https://google.github.io/googletest/quickstart-cmake.html)). To build and run the tests, use the following:  
```
$ cmake -S . -B build
$ cmake --build build
$ cd build && ctest
```

## Done
- Linked List
- Producer Consumer/Bounded Blocking Queue. A thread safe queue using mutexes and conditions.
- Shared Memory example

## Todo
- write a shared memory program that spawns processes itself rather than making the user manually do it in terminal
- finish writing the linked list test cases
- write a test for producer consumer. it uses pthreads so idk if this is possible with GoogleTest
