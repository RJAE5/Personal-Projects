## SFML Knucklebones
### Rykir Evans
### Description:

This project originally started out as coursework for C++ Object-Oriented Programming. After the semester ended, I wished to further expand upon the project and make it better and smoother to play. Subsequently, I added several features which can be found below in the `Implemented` section. There is also an `In Progress` section which describes new ideas that I've brainstormed to implement into the game but have yet to get around to implementing them.

This Knucklebones game is the culmination of all that we had learned in SFML and emphasizing heavy use of the principles and concepts of OOP. It is a paradoy of the real minigame `KnuckleBones` from the game `Cult of the Lamb`. This program aims to create a simplified, but accurate, version of the Knucklebones game, which involves rolling a die and placing values within a grid to get a high score. There is a strategy to gathering points, utilizing the following rules:

* Two of the same number in one **column** doubles the value of those two numbers added.
     * i.e. 5 and 5 makes 20.
* Three of the same number in one **column** triples the value of those three numbers added.
     * i.e. 3, 3, and 3 makes 27

Ultimately, Knucklebones attempted and succeeded to solidify the numerous OOP concepts, as well as taught us a gaming library to add to our arsenal.

### Files

|   #   | File                                     | Description                                  |
| :---: | ---------------------------------------- | -------------------------------------------- |
|   1   | [button.hpp](./button.hpp)               | Class for drawing and using a button         |
|   1   | [dice.hpp](./dice.hpp)                   | Class for making dice and animations         |
|   2   | [game.hpp](./game.cpp)                   | Class for handling game info                 |
|   3   | [grid.hpp](./grid.hpp)                   | Class for handling grid info                 | 
|   4   | [main.cpp](./main.hpp)                   | Main game driver and initialization          |
|   5   | [player.hpp](./player.hpp)               | Class for handling player info               |
|   6   | [uname_input.hpp](./uname_input.hpp)     | Class for handling username input game state |

### Instructions

**Setup**
- Make sure you install SFML by using apt: 
     - `sudo apt-get install libsfml-dev`(for Linux)
     - `brew install sfml` (for Mac)
- Compile the program and link it to SFML libraies: 
```
g++ -o main main.cpp -Ipath/to/sfml/include -Lpath/to/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system
```
- Alternatively, if applicable, use your own SFML compiler
- Run the compiled program: `./main`

**Gameplay**
- You will be prompted to enter a username, once you have input your username, press enter and the game will begin
- To interact with the game, you will need to press the spacebar to execute a die roll or press the green `Roll` button
- Once the die has finished rolling, you will need to click a column of the grid to place the number
     - Using the rules from `Description`, try to get the highest score possible
- Repeat the above steps until the grid is full
- Your game will be complete once the grid is full and it will display `GAME OVER` as well as your final score
- To Restart, press the red `Restart` button

### In Progress
Currently, there are several features that are not in the game which are intended to be implemented at a later date
- Game Initializer class/function
     - As a helper class/function for the restart functionality and cleaning up `main.cpp`, a simple initializing class or function shall be implemented which handles simple function calls to get the game ready to play.

### Implemented
These features were added after the semester ended to improve playability of the game. These were not required by our professor, but I took it upon myself to make the game better.
- Restart functionality
     - Previously, there was no way to restart the game other than restarting the whole application. That only allowed for a single run of the game and a relatively lengthy process to restart. This functionality was implemented with a few additional flags and conditional statements.
- High Score
     - With no restart functionality, there was no way to save nor show a high score other than the final score obtained. A high score in the game class was subsequently implemented to handle the saving and showing of a user's high score within a gaming session.
- Roll Button
     - The only way to interact with the die initially, was to use the spacebar, a specific roll button to be clicked by mouse input was then added to improve intuitivity. This button additionally acts as a status indicator for when the die is rolling and when the user needs to place the value.