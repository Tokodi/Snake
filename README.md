# SNAKE
Another version of the well known SNAKE game written in C++.
The project aims to satisfy the principals of the mvc architecture.

## Requirements
To build the project, [CMake](https://cmake.org) V3.10 or later needs to be installed.
The game model is tested with unit tests, using the [GTest](https://github.com/google/googletest) framework.
If CMake does not find the GTest library, unit test will not be built/ran;

The current solution uses [Ncurses](https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/) to visualize the game.
Ncurses is a created to write text-based user interfaces, and it comes pre-installed with the most linux distributions.

## Build & Run
    * mkdir build
    * cd build
    * cmake ..
    * make -j
    * ./Snake

The project was built and tested on the latest Raspbian release with gcc version 8.3.0
and MacOS Catalina(V10.15.3) with AppleClang 11.0.3;

## Controls
### Menu
Navigate with the arrow keys, select with enter.

### Game
The first arrow key hit will be the start diretion of the snake. Use the arrow keys to navigate.

## Known issues
    * ...

## TODO
    * Print "width" and "height" when asking for table size
    * Implement HighScore persistence in a modular way
    * Ncurses UI improvements
