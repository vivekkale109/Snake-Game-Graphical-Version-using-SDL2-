========================================
            SNAKE GAME (SDL2)
========================================

Description:
------------
This is a graphical Snake Game developed in C language
using the SDL2 library. It runs in a windowed graphical
interface instead of the terminal.

----------------------------------------
Features:
----------------------------------------
- Graphical window interface
- Smooth snake movement
- Arrow key controls
- Random fruit spawning
- Score increases when fruit is eaten
- Snake grows after eating fruit
- Collision detection (wall and self)
- Game over when collision occurs

----------------------------------------
Requirements:
----------------------------------------
- Linux OS (Tested on Arch Linux)
- GCC Compiler
- SDL2 Library

----------------------------------------
Installation (Arch Linux):
----------------------------------------
Install SDL2 using:

sudo pacman -S sdl2

----------------------------------------
Compilation:
----------------------------------------
Compile the program using:

gcc snake_gui.c -o snake_gui -lSDL2

----------------------------------------
Run the Game:
----------------------------------------
Execute:

./snake_gui

----------------------------------------
Controls:
----------------------------------------
LEFT ARROW   - Move Left
RIGHT ARROW  - Move Right
UP ARROW     - Move Up
DOWN ARROW   - Move Down
Close Window - Exit Game

----------------------------------------
How the Game Works:
----------------------------------------
1. The snake starts from the center.
2. A fruit appears randomly on the screen.
3. When the snake eats the fruit:
   - Score increases by 10
   - Snake length increases
   - A new fruit appears randomly
4. Game ends if:
   - Snake hits the wall
   - Snake hits its own body

----------------------------------------
Future Improvements (Optional):
----------------------------------------
- Add restart option
- Add sound effects
- Display score inside window
- Add difficulty levels
- Save high score to file

----------------------------------------
Author:
----------------------------------------
Developed as a C programming project
to demonstrate basic game development
using SDL2 in Linux.

========================================
