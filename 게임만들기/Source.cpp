#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<vector>
#include<string>
#pragma comment(lib, "winmm.lib")

using namespace std;

#define MAGIC_KEY 224
#define SPACE 32
#define KEY_NUM 3
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
    gotoxy(5, 3);
    cout << "******************************";
    gotoxy(5, 4); 
    cout << "*     화살표 맞추기 게임     *";
    gotoxy(5, 5);
    cout << "******************************";
    gotoxy(10, 9);
    cout << "게임 시작";
    gotoxy(10, 10);
    cout << "끝내기" << endl;
    gotoxy(8, 14);
    cout << "SPACE를 누르세요!" << endl;
}

void DrawStartGame(const int life, const int score, const int time, const string questionStr, const string answerStr)
{
    system("cls");
    gotoxy(2, 1);
    cout << "□□□□□□□□□□□□□□□□□□□□□";
    gotoxy(4, 3);
    cout << "목숨 : " << life;
    gotoxy(4, 4);
    cout << "점수 : " << score;
    gotoxy(4, 5);
    cout << "경과시간 : " << time;
    gotoxy(4, 8);
    cout << "Q : " << questionStr;
    gotoxy(4, 10);
    cout << "A : " << answerStr;
    gotoxy(4, 14);
    cout << "SPACE를 누르세요!";
    gotoxy(2, 18);
    cout << "□□□□□□□□□□□□□□□□□□□□□";
}

void DrawGameOver(const int score)
{
    system("cls");
    gotoxy(8, 7);
    cout << "-------------------";
    gotoxy(8, 8);
    cout << "| G A M E O V E R |";
    gotoxy(8, 9);
    cout << "-------------------";
    gotoxy(10, 11);
    cout << " 점수 : " << score;
    gotoxy(8, 14);
    if (score <= 50)
    {
        
        cout << "      아이언";
    }
    else if (50 < score && score <= 100)
    {
        cout << "      브론즈";
    }
    else if (100 < score && score <= 150)
    {
        cout << "        실버";  
    }
    else if (150 < score && score <= 200)
    {
        cout << "        골드";
    }
    else if (200 < score && score <= 300)
    {
        cout << "      플래티넘";
    }
    else if (300 < score && score <= 600)
    {
        cout << "      다이아";
    }
    else if (600 < score && score <= 800)
    {
        cout << "      마스터";
    }
    else if (800 < score && score <= 1000)
    {
        cout << "    그랜드마스터";
    }
    else if (1000 < score)
    {
        cout << "     ★챌린저★";
    }
    
    system("pause>null");
}

void DrawUserCursor(int& y)
{
    if (y <= 0)
    {
        y = 0;
    }
    else if (y >= 1)
    {
        y = 1;
    }

    gotoxy(9, 8 + y + 1);
    cout << ">" << endl;
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
    int time = 0;

    vector<int> questionVec;
    string questionStr = "";
    vector<int> answerVec;
    string answerStr = "";
    clock_t start = clock();

    int firstInput = 0;
    int secondInput = 0;

    while (true)
    {
        int level = (score / 30) + 1;
        SetQuestion(questionVec, level);
        VectorToString(questionVec, questionStr);

        while (true)
        {
            DrawStartGame(life, score, time, questionStr, answerStr);

            //  for (;;) {
            //      clock_t end = clock();
            //      int time = int(end - start) / CLOCKS_PER_SEC;
            //      gotoxy(4, 5);
            //      cout << "경과시간 : " << time;
            //  
            //  }

            if (life == 0)
            {
                DrawGameOver(score);
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