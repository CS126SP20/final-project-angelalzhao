# Final Project

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![docs](https://img.shields.io/badge/docs-yes-brightgreen)](docs/README.md)

Read [this document](https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html) to understand the project
layout.

**Author**: Angela Zhao - [`alz3@illinois.edu`](mailto:alz3@illinois.edu)

## Build

Disclaimer: This project has only been tested on Windows

### CLion
Install CLion. Windows users will also need to install [MSBuild Tools](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=BuildTools&rel=16)
and follow [these](https://www.jetbrains.com/help/clion/quick-tutorial-on-configuring-clion-on-windows.html#msvc-compiler) instructions.

### Cinder
Instructions for setting up [Cinder]() can be found [here](https://courses.grainger.illinois.edu/cs126/sp2020/assignments/snake/).
Inside `~Cinder/my-projects`, create a new directory and clone the project into that directory.

### CMake

This project uses [SQLiteModernCpp](https://github.com/SqliteModernCpp/sqlite_modern_cpp.git) + [SQLite3](https://github.com/alex85k/sqlite3-cmake.git)
for database queries, as well as [Catch2](https://github.com/catchorg/Catch2) for testing. Check to make sure that these libraries are included in the root `CMakeLists.txt`
file. Also, make sure that `catch2` is included in the `LIBRARIES` argument under `ci_make_app` in `tests/CMakeLists.txt`, and that `sqlite-modern-cpp` and `sqlite3` are
included in `LIBRARIES` under `ci_make_library` in `src/CMakeLists.txt`.

You should now be able to play the game by running `cinder-myapp`!

## Gameplay

Select a level by pressing the corresponding number on the keyboard. Once you have selected a level, press `s` to start the game.

Click on a tile to select it. When you select two tiles, those tiles will switch places. The only tiles that can't be selected/swapped
are the corner tiles, which are fixed in place.

Continue swapping tiles until the tiles are arranged in a gradient. When the board is solved, a sound effect will play and your
score, the average score, and the top scores will be displayed on screen.

Solved board examples: 

![Medium](resources/medium.PNG?raw=true "Medium")

![Hard](resources/hard.PNG?raw=true "Hard")
