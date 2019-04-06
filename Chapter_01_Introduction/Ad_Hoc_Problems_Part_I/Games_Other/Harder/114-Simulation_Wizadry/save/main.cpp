/*
 * Problem 114 - Simulation Wizardy
 */
#include <iostream>
#include <sstream>

// 0 Right, 1 up, 2 left, 3 right

int values[60][60] = {{0}};
int costs[60][60] = {{0}};

int wallCost;
int maxX, maxY;
int score;
int totalScore = 0;

void moveBall(int &x, int &y, int direction)
{
    if (direction == 0) {           // right
        ++x;
    } else if (direction == 1) {    // up
        ++y;
    } else if (direction == 2) {    // left
        --x;
    } else {
        --y;
    }
}

int detectHit(int x, int y, int &dir)
{
    if (x == 0) {
        if (dir == 1 || dir == 3) {
            return 0;
        } else {
            dir = 1;
            return wallCost;
        }
    } else if (x == maxX) {
        if (dir == 1 || dir == 3) {
            return 0;
        } else {
            dir = 3;
            return wallCost;
        }
    }
    if (y == 0) {
        if (dir == 0 || dir == 2) {
            return 0;
        } else {
            dir = 0;
            return wallCost;
        }
    } else if (y == maxY) {
        if (dir == 0 || dir == 2) {
            return 0;
        } else {
            dir = 2;
            return wallCost;
        }
    }

    // handle any bumper hits
    if (values[x][y] || costs[x][y]) {
        score += values[x][y];
        return costs[x][y];
    }
    return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::ostringstream output;
#if 0
    int maxX, maxY, numberOfBumpers;
    std::cin >> maxX >> maxY >> wallCost >> numberOfBumpers;


    while (numberOfBumpers--) {
        int x, y, value, cost;
        std::cin >> x >> y >> value >> cost;

        values[x][y] = value;
        costs[x][y] = cost;
    }

    int x, y, direction, lifetime;
    while (std::cin >> x >> y >> direction >> lifetime) {
        score = 0;
        while (lifetime--) {
            moveBall(x, y, direction);
            lifetime += detectHit(x, y, direction);
        }
        output << score << '\n';
        totalScore += score;
    }
#endif
    maxX = 4; maxY = 4;
    values[2][2] = 1;
    costs[2][2] = 0;
    values[3][3] = 1;
    costs[3][3] = 0;

    int x = 2;
    int y = 3;
    int direction = 1;
    int lifetime = 3;

    score = 0;
    while (--lifetime) {
        moveBall(x, y, direction);
        lifetime += detectHit(x, y, direction);
    }
    output << score << '\n';
    totalScore += score;


    std::cout << output.str() << totalScore << '\n';
}
