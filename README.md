#SNAKE

Another version of the well known SNAKE game written in C++.
The project aims to satisfy the principals of the mvc architecture.

##Requirements
To build the project, [CMake](https://cmake.org) needs to be installed.
The game model is tested with unit tests, using the [GTest](https://github.com/google/googletest) framework.
If CMake does not find the GTest library, unit test will not be built/ran;

##Build & Run
    * mkdir build
    * cd build
    * cmake ..
    * make -j
    * ./Snake

##Known issues
    * ...

##TODO
    * Implement HighScore persistence in a modular way
    * Ncurses UI improvements
