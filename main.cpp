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
    }

    void Input() {
        if (_kbhit()) {
            switch (_getch()) {
                case 'a': dir = LEFT; break;
                case 'd': dir = RIGHT; break;
                case 'w': dir = UP; break;
                case 's': dir = DOWN; break;
                case 'x': gameOver = true; break;
            }
        }
    }

    void Logic() {
        pair<int, int> prev = snake[0];
        pair<int, int> prev2;

        for (int i = 1; i < snake.size(); i++) {
            prev2 = snake[i];
            snake[i] = prev;
            prev = prev2;
        }

        switch (dir) {
            case LEFT: snake[0].first--; break;
            case RIGHT: snake[0].first++; break;
            case UP: snake[0].second--; break;
            case DOWN: snake[0].second++; break;
            default: break;
        }

        if (snake[0].first >= width) snake[0].first = 0; 
        else if (snake[0].first < 0) snake[0].first = width - 1;
        
        if (snake[0].second >= height) snake[0].second = 0; 
        else if (snake[0].second < 0) snake[0].second = height - 1;

        for (int i = 1; i < snake.size(); i++){
            if (snake[0] == snake[i]){
                gameOver = true;}}

        if (snake[0] == fruit) {
            score += 10;
            snake.push_back({0, 0});
            GenerateFruit();
        }
    }};
public:
    SnakeGame(int w, int h) : width(w), height(h), gameOver(false), score(0), dir(STOP) {
        snake.push_back({width / 2, height / 2});
        GenerateFruit();
    }

    int Difficulty(int b) {
        if (b == 1) {
            return 250;
        } else if (b == 2) {
            return 175;
        } else if (b == 3) {
            return 100;
        }
        return 250; // Default
    }

    void Run() {
        while (true) {
            cout << "Select difficulty (1~3): ";
            cin >> diffinput;
            if (diffinput >= 1 && diffinput <= 3) break;
            cout << "Unknown parameter given. Please try again." << endl;
            system("cls");
        }

        int delay = Difficulty(diffinput);

        while (!gameOver) {
            Draw();
            Input();
            Logic();
            Sleep(delay);
        }
        cout << "Game Over!" << endl;
    }
};
int main() {
    SnakeGame game(20, 20);
    game.Run();
    system("cls");
    cout<<"Game Over";
    getch();
    return 0;
}

