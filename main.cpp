#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

class SnakeGame {
private:
    int difficulty;
    int diffinput;
    const int width;
    const int height;
    bool gameOver;
    int score;
    eDirection dir;
    pair<int, int> fruit;
    vector<pair<int, int>> snake;

    void GenerateFruit() {
        fruit.first = rand() % width;
        fruit.second = rand() % height;
    }
    void Draw() {
        COORD coord = {0, 0};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0) cout << "#";
                if (make_pair(j, i) == snake[0])
                    cout << "O";
                else if (make_pair(j, i) == fruit)
                    cout << "F";
                else {
                    bool isTail = false;
                    for (int k = 1; k < snake.size(); k++) {
                        if (snake[k] == make_pair(j, i)) {
                            cout << "o";
                            isTail = true;
                            break;
                        }
                    }
                    if (!isTail)
                        cout << " ";
                }
                if (j == width - 1) cout << "#";
            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;
        cout << "Score: " << score << endl;
    }};