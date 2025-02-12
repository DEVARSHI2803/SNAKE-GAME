#include <iostream>
#include <queue>
#include <conio.h>  
#include <windows.h> 
using namespace std;

bool gameOver,onSnake;
int snakex, snakey, fruitx, fruity, score = 0;
int height = 20, width = 40;
int gameSpeed=100;
queue<pair<int, int>> snakeBody; 
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
    cursorInfo.dwSize = 1;  
    cursorInfo.bVisible = FALSE;  
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
    system("cls");  
    setColor(14);   

    cout << "========================================\n";
    cout << "          SERPENT QUEST \n";
    cout << "========================================\n";
    cout << "  1. Press ENTER to Start\n";
    cout << "  2. Press X to Exit\n";
    cout << "========================================\n";

    while (true)
    {
        if (_kbhit())  
        {
            char key = _getch();  
            if (key == 13) break; 
            if (key == 'x' || key == 'X') exit(0); 
        }
    }
}
void Instructions()
{
    system("cls");
    cout << "========================================\n";
    cout << "          Instructions \n";
    cout << "========================================\n";
    cout<<  " Press 'W' or 'Up' arrow key to move up.\n";
    cout<<  " Press 'A' or 'Left' arrow key to move left.\n";
    cout<<  " Press 'S' or 'Down' arrow key to move down.\n";
    cout<<  " Press 'D' or 'Right' arrow key to move right.\n";
    cout << "        Press ENTER to Start\n";
    cout << "========================================\n";
    while (true)
    {
        if (_kbhit())  
        {
            char key = _getch();  
            if (key == 13) break; 
            
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
    setColor(12);  

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
            if (key == 'r' || key == 'R') return true; 
            if (key == 'x' || key == 'X') return false; 
        }
    }
}
void Setup()
{
    gameOver = false;
    snakex = width / 2;
    snakey = height / 2;
    do {
        fruitx = rand() % (width - 2) + 1;
        fruity = rand() % (height - 2) + 1;
        
        
        bool onSnake = false;
        queue<pair<int, int>> tempSnake = snakeBody;
        while (!tempSnake.empty()) {
            auto segment = tempSnake.front();
            tempSnake.pop();
            if (segment.first == fruitx && segment.second == fruity) {
                onSnake = true;
                break;
            }
        }
    } while (onSnake);
    
    score = 0;
    dir = STOP;
    
   
    while (!snakeBody.empty()) snakeBody.pop();
    snakeBody.push({snakex-2,snakey});
    snakeBody.push({snakex-1,snakey});
    snakeBody.push({snakex,snakey});
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
                    cout << "O";  
                }
            else if (j == fruitx && i == fruity)
                {
                    setColor(12);
                    cout <<"*";  
                }
            else
            {
                bool print = false;
                queue<pair<int, int>> tempSnake = snakeBody; 

                    while (!tempSnake.empty())
                    {
                        auto segment = tempSnake.front();
                        tempSnake.pop();
                        if (segment.first == j && segment.second == i)
                        {
                            setColor(11);
                            cout << "o"; 
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
        
        
        if (key == -32)  
        {
            key = _getch(); 
            switch (key)
            {
            case 75: if (dir != RIGHT) dir = LEFT; break;  
            case 80: if (dir != UP) dir = DOWN; break;    
            case 72: if (dir != DOWN) dir = UP; break;    
            case 77: if (dir != LEFT) dir = RIGHT; break;  
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

    switch (dir)
    {
    case LEFT:  snakex--; break;
    case RIGHT: snakex++; break;
    case UP:    snakey--; break;
    case DOWN:  snakey++; break;
    default:    return; 
    }

    
    if (snakex >= width-1  || snakex <= 0 || snakey >= height || snakey < 0)
    {
        gameOver = true;
        return;
    }

    
    queue<pair<int, int>> tempSnake = snakeBody; 

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


    
    snakeBody.push({ snakex, snakey });

   
    if (snakex == fruitx && snakey == fruity)
    {
        score++;
        do {
            fruitx = rand() % (width - 2) + 1;
            fruity = rand() % (height - 2) + 1;
            
            
            bool onSnake = false;
            queue<pair<int, int>> tempSnake = snakeBody;
            while (!tempSnake.empty()) {
                auto segment = tempSnake.front();
                tempSnake.pop();
                if (segment.first == fruitx && segment.second == fruity) {
                    onSnake = true;
                    break;
                }
            }
        } while (onSnake);
        
    }
    else
    {
        
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
    Instructions();
    system("cls");
    while (true)  
    {
        Start();  

        if (!RestartMenu()) 
            break;
    }
    return 0;
}
