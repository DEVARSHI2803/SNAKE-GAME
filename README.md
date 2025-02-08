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
  
2)Draw()  Working:  

* Clears The screen.
* Prints boundries.
* Draws food,snakebody.
  
3)input()   Working:  

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
1)Queue: A queue in c++ is FIFO(First in,First Out)data structure that allows elements to be added at the back and removed from the front.
Here in this game queue is used to represent snake's body.  

Syntax:  queue<pair<int,int>>snakebody  
--->  QUEUE IS THE MOST PREFERABLE DATA STRUCTURE BECAUSE THE PUSH() AND POP() FUNCTIONS CAN DIRECTLY BE IMPLEMENTED TO ADD NEW HEAD POSITION OF SNAKE AND POP THE LAST ELEMENT OF THE BODY.  
✔ This behavior matches the way a snake moves in real life.  

✔ Arrays would require shifting elements when removing the tail, which is inefficient.  

2)ENUM:  
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };: Represents the possible movement directions of the snake.  
3)Variables  
int snakex, snakey: Stores the snake's head position.
int fruitx, fruity: Stores the food's position.
int score: Keeps track of the player's score.
bool gameOver: Controls the main game loop.  
## Major Highlights
* The user can choose the difficulty level on basis of his skills in this game.
* Game can be restarted infinitely many times based on user's choice.
* Snake's skin is given a cool colour combination along with boundaries and fruit








## Future Improvements  
* Implementing a high-score tracking system.
* Having a better U/I and graphics to make game look realistic.
* Adding custom gameplay option for user's favourite variety of other snake games.
* Multiplayer can be introduced for fascinating experience.
  







