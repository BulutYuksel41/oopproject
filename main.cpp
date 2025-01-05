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
    }}