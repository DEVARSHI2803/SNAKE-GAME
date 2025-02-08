# SERPENT QUEST
Snake game was one of the very first games played in our mobile.Here we Binary Bandits have created a simpler version of it using our knowledge on data structures and some libraries
# Authors
Team: Binary Bandits  

Names: Student Id:  

Vatsal Mori 202401436   

Devarshi Patel 202401445   

Shrey Patel 202401449   

Vedant Shah 202401475  
## How to start
Requirements: ->Windows OS ->C++ Compiler Steps to Compile & Run

1)Open a terminal (or Command Prompt in Windows).

2)Navigate to the folder containing snake_q.cpp.  
  
3)Compile using G++: g++ snake_q.cpp -o snake_game

4)Run the executable: ./snake_game
## WORKING
Simple keyboard keys are taken into account to operate through the game.   

'A' or '<':   Move left  

'D' or '>' :  Move right  

'W' or '^' :  Move up  

'S' or 'v' : Move down  

Rules are as simple as it gets ,eat as many fruit as you can without letting your serpent slide into the walls or itself.The more you eat the longer you get .
Compete with your friends showing off your highest score.    

## Code Structure
1)Setup():
Working:  
* Spawn food randomly
* Resets all variables when the game starts.
* Snake starts at the centre of the screen.
  
2)Draw()
Working:
* Clears The screen.
* Prints boundries.
* Draws food,snakebody.
3)input()
  Working:
  * Checks if a key is pressed.
  * Supports arrow keys and WASD.
4)Logic()
Working:
* Moves the snake based on direction
* Checks for wall collision
* Checks for self collision
* Whenever food eaten increases the score and grows the snake
  
5)Start()
Working:
* Start menu appears first
* Player selects difficulty
* Game starts and loops until player quits
6)Main()
  It calls the above all functions while game is running.





## Data Structure Analysis


## Future Improvements  
* Implementing a high-score tracking system.
* Having a better U/I and graphics to make game look realistic.
* Adding custom gameplay option for user's favourite variety of other snake games.
* Multiplayer can be introduced for fascinating experience.
  







