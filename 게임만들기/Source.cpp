#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<vector>
#include<string>
#include<ctime>
#pragma comment(lib, "winmm.lib")
using namespace std;

#define MAGIC_KEY 224
#define SPACE 32
#define KEY_NUM 4
#define LIFE 3
#define MAX_LEVEL 11

enum MENU
{
    GAMESTART = 0,    
    QUIT
};

enum KEYBOARD
{
    UP = 72,
    LEFT = 75,
    RIGHT = 77,
    DOWN = 80
};

void gotoxy(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void SetConsoleView()
{
    system("mode con:cols=50 lines=20");
    system("title DanceDance");
}

void DrawReadyGame()
{
    system("cls");
    gotoxy(5, 2);
    printf("******************************");
    gotoxy(5, 3);
    printf("*        Dance Dance         *");
    gotoxy(5, 4);
    printf("******************************");
    gotoxy(10, 8);
    printf("게임 시작");
    gotoxy(10, 9);
    printf("끝내기\n");
}

void DrawStartGame(const int life, const int score, const string questionStr, const string answerStr)
{
    system("cls");
    gotoxy(2, 1);
    printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
    gotoxy(4, 3);
    printf("목숨 : ", life);
    gotoxy(4, 4);
    printf("점수 : ", score);
    gotoxy(4, 8);
    printf("Q : ", questionStr);
    gotoxy(4, 10);
    printf("A : ", answerStr);
    gotoxy(4, 12);
    printf("SPACE를 누르세요!");
    gotoxy(2, 18);
    printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
}

void DrawGameOver(const int playTime)
{
    gotoxy(8, 8);
    printf("-------------------");
    gotoxy(8, 9);
    printf("| G A M E O V E R |");
    gotoxy(8, 10);
    printf("-------------------");
    system("pause>null");
}

void DrawUserCursor(int& y)
{
    if (y <= 0)
    {
        y = 0;
    }
    else if (y >= 2)
    {
        y = 2;
    }

    gotoxy(9, 8 + y);
    printf(">\n");
}

MENU ReadyGame()
{
    int y = 0;
    int input = 0;
    while (true)
    {
        DrawReadyGame();
        DrawUserCursor(y);
        input = _getch();

        if (input == MAGIC_KEY)
        {
            switch (_getch())
            {
            case UP:
                --y;
                break;
            case DOWN:
                ++y;
                break;
            }
        }
        else if (input == SPACE)
        {
            switch (y)
            {
            case 0:
                return GAMESTART;
            case 1:
                return QUIT;
            }
        }
    }
}

void SetQuestion(vector<int>& questionVec, int level)
{
    if (level > MAX_LEVEL)
    {
        level = MAX_LEVEL;
    }

    int num = 0;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < level; ++i)
    {
        num = rand() % KEY_NUM;
        switch (num)
        {
        case 0:
            questionVec.push_back(UP);
            break;
        case 1:
            questionVec.push_back(RIGHT);
            break;
        case 2:
            questionVec.push_back(LEFT);
            break;
        case 3:
            questionVec.push_back(DOWN);
            break;
        }
    }
}

void VectorToString(const vector<int> v, string& str)
{
    for (int i = 0; i < static_cast<int>(v.size()); ++i)
    {
        switch (v[i])
        {
        case UP:
            str += "↑ ";
            break;
        case DOWN:
            str += "↓ ";
            break;
        case LEFT:
            str += "← ";
            break;
        case RIGHT:
            str += "→ ";
            break;
        }
    }
}

bool CheckAnswer(const vector<int> questionVec, const vector<int> answerVec)
{
    if (questionVec.size() != answerVec.size())
    {
        return false;
    }

    for (int i = 0; i < static_cast<int>(questionVec.size()); ++i)
    {
        if (questionVec[i] != answerVec[i])
        {
            return false;
        }
    }
    return true;
}

void StartGame()
{
    int life = LIFE;
    int score = 0;

    clock_t startTime, endTime;
    startTime = clock();

    vector<int> questionVec;
    string questionStr = "";
    vector<int> answerVec;
    string answerStr = "";

    int firstInput = 0;
    int secondInput = 0;
    while (true)
    {
        int level = (score / 30) + 1;
        SetQuestion(questionVec, level);
        VectorToString(questionVec, questionStr);
        while (true)
        {
            DrawStartGame(life, score, questionStr, answerStr);

            if (life == 0)
            {
                endTime = clock();
                int playTime = static_cast<int>((endTime - startTime) / CLOCKS_PER_SEC);

                DrawGameOver(playTime);
                PlaySound(NULL, NULL, 0);
                return;
            }
            firstInput = _getch();
            if (firstInput == MAGIC_KEY)
            {
                secondInput = _getch();
                answerVec.push_back(secondInput);
                switch (secondInput)
                {
                case UP:
                    answerStr += "↑ ";
                    break;
                case DOWN:
                    answerStr += "↓ ";
                    break;
                case LEFT:
                    answerStr += "← ";
                    break;
                case RIGHT:
                    answerStr += "→ ";
                    break;
                }
            }
            else if (firstInput == SPACE)
            {
                if (CheckAnswer(questionVec, answerVec))
                {
                    score += 10;
                }
                else
                {
                    --life;
                    score -= 5;
                    if (score < 0)
                    {
                        score = 0;
                    }
                }

                questionVec.clear();
                questionStr = "";
                answerVec.clear();
                answerStr = "";
                break;
            }
        }
    }
}

int main(void)
{
    SetConsoleView();
    while (true)
    {
        switch (ReadyGame())
        {
        case GAMESTART:
            StartGame();
            break;
        case QUIT:
            return 0;
        }
    }
    return 0;
}