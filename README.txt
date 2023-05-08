ICP Pacman

Authors:
    Jan Kalenda (xkalen07)
    Tereza Kubincová (xkubin27)

Project implementing a subset of the standard old-school game Pacman. The game is implemented in C++ using the Qt framework.
The goal of the game is to avoid ghosts, pickup the map's key and open the lock, leading to the victory.
Heart icon in the top left corner represents the number of lives left. The game is over when the player loses all of his lives and touches a ghost.
The game is also over when the player wins the game by opening the lock with the key.
The player can move using the WADZ keys or by clicking on the desired location on the map.

The game can be restarted, quit and resumed by clicking on the desired button in the Pause menu accessed by pressing ESC.

Pacman does not move only on block edges, but also in the middle of the block. This is to make the game more enjoyable and easier to play.

The game is built utilizing CMake. The following commands are available in the root directory of the project:
- make run (to build and run the game)
- make clean (to clean the build, doc directories and the executable)
- make doxygen (to generate documentation)
- make pack (to generate a .zip archive of the project)
- make (to build the game)


How to play:
- run the game using the make run command
- click on the New Game button
- choose one of the maps in the examples folder
- click on the open button
- the game will start
- use the WADZ keys or mouse clicks to move
- press ESC to pause the game
- click on the Resume button to resume the game
- click on the Restart button to restart the game
- click on the Quit button to quit the game

How to replay:
- run the game using the make run command
- click on the Replay button
- choose one of the logs in the examples folder (or root directory after running the game)
- click on the open button
- the replay will start
- A button moves back in time, D button moves forward in time
- press ESC to pause the replay
- click on the Resume button to resume the replay
- click on the Restart button to restart the replay
- click on the Quit button to quit the replay


IMPLEMENTED:
- Standard playthrough
- A* algorithm for ghosts
- 2D graphics
- multiple lives (2 in this version) for player
- invincibility frames for player after being hit by a ghost
- 3 different levels
- Replay function
- Start page
- Step counter
- Navigation through the game using keyboard
- Navigation through the game using mouse
- Restarting the game
- Quitting the game
- Pausing the game
- Resuming the game
- Logging (in root of the project after running the game, format: log_unixtimestamp.txt)

NOT IMPLEMENTED (TODO):
- Replay from end of the game
- Pacman and ghosts animations (mouth opening and closing, turning around, etc.)
- Ghosts running away from pacman after eating a superfood
- Additional levels
- Additional game modes (e.g. time trial)
- High score table
- Sound effects
- Multi-level continuity
- Window resizing
