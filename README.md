# CPPND: Capstone Mason Game

A mason has to build a wall by "firing" flying blocks, which come to build a brick layer. This layer dissapears as soon as it is "full"
and a new randomly incomplete layer shows up to keep the mason busy. Every completed layer increases the score.
<img src="mason_game.jpg"/>

You can move the mason laterally using the numPad:
4 and 6 respectively for left and right.
When pressing 8 a block will fly and go to the
Layer.
For firing a new block, the current flying block
must have already arrived to the layer.

NOTE: if the mason seems not to move try
locking/unlocking the NumPad by pressing
the NmLk key on the keyboard.


## Rubric Points
* Instructions:
1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./MasonGame`.

* Dependencies (same as SnakeGame)

* Description of the project

The project chosen is a game based on the SnakeGame. Instead of the Snake object two new objects are now created inside the Game object: Wall and Mason, which in turn contains the object FlyingBlock.
The main creates the three main objects and then calls the Game::Run for the loop.
//.jpg
The class GameObject is defined as the base class for mason and wall.
In this way, the common properties and methods like position and state are grouped.
//.jpg
Mason:
When the mason is created its position is set around the middle at the bottom of the screen.
The bool variable blockFlies is used to indicates when the block "fired" by the mason starts to fly and at the end comes to the wall.
The Update function changes the state of the mason, so that it only moves after the corresponding key has been pressed.
The flyingBlock object is created inside mason and appears whenever the key 8 in the numPad has been pressed. Besides its normal position, an initial position is defined for taking the position of the mason when it starts to fly.
In the function PropelBlock the completeness of the wall layer is checked, by counting the number of blocks present in the vector wall.presence. If the last flying block has completed the layer, by arriving to the layer, then the score increases and a new wall layer is created.

Wall:
The wall object includes a vector of bool values for indicating the presence of blocks in the wall layer.
The function new wall will place blocks in random positions of the vector presence.

Game:
The game object includes the mason, the wall and the score, which can be set and read through
public functions.
The function Run starts creating a new wall layer and then the while loop begins, where besides the main thread, two additional threads run calling respectively the functions Update from Mason and PropelBlock from FlyingBlock.

Renderer:
The render function inside the Renderer object takes now the mason and the wall as arguments, so that they can be displayed.
The FlyingBlock is displayed only if the respective flag is active.
The wall layer is filled up according to the presence of blocks.

Controller:
The controller makes available the function HandleInput, which now receives the input from the keys 4, 6 and 8 from the numPad for the movement to the left, right and firing the block, respectively.


* Information about the addressed rubric points:
- switch case, for and while loops have been used.
- The classes mason, flyingBlock and wall include functions, which group the sequences of tasks steps related to the respective object.
- Inheritance is implemented through the class GameObject.
- Use of references inside thread functions: game.cp::33
- The project uses multiple threads inside the function Game::Run



## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./MasonGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
