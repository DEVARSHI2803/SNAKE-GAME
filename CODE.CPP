#include <iostream>
#include <queue>
#include <conio.h>  // For _kbhit() and _getch()
#include <windows.h> // For Sleep()
using namespace std;

bool gameOver;
int snakex, snakey, fruitx, fruity, score = 0;
int height = 20, width = 40;
int gameSpeed=100;
queue<pair<int, int>> snakeBody; // Queue to store snake's body segments
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);
void ClearScreen()
{
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(console, cursorPosition);
}

void HideCursor()
{
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;  // Small size
    cursorInfo.bVisible = FALSE;  // Hide cursor
    SetConsoleCursorInfo(console, &cursorInfo);
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void StartMenu()
{
    system("cls");  // Clear screen
    setColor(14);   // Yellow color for text

    cout << "========================================\n";
    cout << "          SERPENT QUEST \n";
    cout << "========================================\n";
    cout << "  1. Press ENTER to Start\n";
    cout << "  2. Press X to Exit\n";
    cout << "========================================\n";

    while (true)
    {
        if (_kbhit())  // If a key is pressed
        {
            char key = _getch();  // Get key press
            if (key == 13) break; // Enter key starts the game
            if (key == 'x' || key == 'X') exit(0); // 'X' exits
        }
    }
}
void SelectDifficulty()
{
    system("cls");
    setColor(14);
    cout << "========================================\n";
    cout << "        SELECT DIFFICULTY \n";
    cout << "========================================\n";
    cout << "  1. Easy (Slow) \n";
    cout << "  2. Medium (Normal) \n";
    cout << "  3. Hard (Fast) \n";
    cout << "========================================\n";
    cout << "  Choose (1-3): ";

    char choice = _getch();
    if (choice == '1') gameSpeed = 150;
    else if (choice == '2') gameSpeed = 100;
    else if (choice == '3') gameSpeed = 50;
}
bool RestartMenu()
{
    system("cls");
    setColor(12);  // Red color for game over text

    cout << "========================================\n";
    cout << "           GAME OVER \n";
    cout << "========================================\n";
    cout << "  Your Final Score: " << score << endl;
    cout << "========================================\n";
    cout << "  1. Press R to Restart\n";
    cout << "  2. Press X to Exit\n";
    cout << "========================================\n";

    while (true)
    {
        if (kbhit())
        {
            char key = getch();
            if (key == 'r' || key == 'R') return true; // Restart game
            if (key == 'x' || key == 'X') return false; // Exit game
        }
    }
}
void Setup()
{
    gameOver = false;
    snakex = width / 2;
    snakey = height / 2;
    fruitx = rand() % (width - 2) + 1;
    fruity = rand() % (height - 2) + 1;
    score = 0;
    dir = STOP;
    
    // Clear the queue and start with a single snake segment
    while (!snakeBody.empty()) snakeBody.pop();
    snakeBody.push({ snakex, snakey });
    HideCursor();
}

void Draw()
{
    ClearScreen();
    gotoxy(0,0);
    setColor(14);
    for (int i = 0; i < width; i++) cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1)
                {
                    setColor(14);
                    cout << "#";
                }
            else if (j == snakex && i == snakey)
                {
                    setColor(10);
                    cout << "O";  // Snake head
                }
            else if (j == fruitx && i == fruity)
                {
                    setColor(12);
                    cout <<"*";  // Fruit
                }
            else
            {
                bool print = false;
                queue<pair<int, int>> tempSnake = snakeBody; // Copy queue

                    while (!tempSnake.empty())
                    {
                        auto segment = tempSnake.front();
                        tempSnake.pop();
                        if (segment.first == j && segment.second == i)
                        {
                            setColor(11);
                            cout << "o"; // Snake body
                            print = true;
                            break;
                        }   
                    }

                if (!print) 
                {
                    setColor(2);
                    cout << " ";
                }
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width; i++) cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;
}

void Input()
{
    if (_kbhit())
    {
        char key = _getch();
        
        // Check if arrow key was pressed
        if (key == -32)  // Special key prefix for arrow keys
        {
            key = _getch(); // Get actual arrow key code
            switch (key)
            {
            case 75: if (dir != RIGHT) dir = LEFT; break;  // Left arrow
            case 80: if (dir != UP) dir = DOWN; break;    // Down arrow
            case 72: if (dir != DOWN) dir = UP; break;    // Up arrow
            case 77: if (dir != LEFT) dir = RIGHT; break;  // Right arrow
            }
        }
        else
        {
            switch (key)
            {
            case 'a': if (dir != RIGHT) dir = LEFT; break;
            case 's': if (dir != UP) dir = DOWN; break;
            case 'w': if (dir != DOWN) dir = UP; break;
            case 'd': if (dir != LEFT) dir = RIGHT; break;
            case 'x': gameOver = true; break;
            }
        }
    }
}

void Logic()
{
    int prevX = snakex;
    int prevY = snakey;

    switch (dir)
    {
    case LEFT:  snakex--; break;
    case RIGHT: snakex++; break;
    case UP:    snakey--; break;
    case DOWN:  snakey++; break;
    default:    return; // If STOP, do nothing
    }

    // Check if snake hits the wall
    if (snakex >= width - 1 || snakex <= 0 || snakey >= height || snakey < 0)
    {
        gameOver = true;
        return;
    }

    // Check if snake collides with itself
    queue<pair<int, int>> tempSnake = snakeBody; // Copy queue

    while (!tempSnake.empty())
    {
        auto segment = tempSnake.front();
        tempSnake.pop();
        if (segment.first == snakex && segment.second == snakey)
        {
            gameOver = true;
            return;
        }
    }


    // Add new head position to the queue
    snakeBody.push({ snakex, snakey });

    // If the snake eats the fruit
    if (snakex == fruitx && snakey == fruity)
    {
        score++;
        fruitx = rand() % (width - 2) + 1;
        fruity = rand() % (height - 2) + 1;
    }
    else
    {
        // Remove the last segment to maintain snake length
        snakeBody.pop();
    }
}

void Start()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(gameSpeed);
    }
}

int main()
{
    StartMenu();
    SelectDifficulty();
    while (true)  // Loop to restart the game if needed
    {
        Start();  // Play the game

        if (!RestartMenu()) // If the user chooses to exit
            break;
    }
    return 0;
}
