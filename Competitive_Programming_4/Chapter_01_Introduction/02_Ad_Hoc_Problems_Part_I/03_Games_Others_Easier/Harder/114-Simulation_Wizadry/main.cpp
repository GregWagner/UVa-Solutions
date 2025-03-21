/*
 * Problem 114 - Simulation Wizardy
 */
#include <iostream>
#include <sstream>

int value[60][60];
int cost[60][60];

void print(int m, int n, int x, int y) {
    for (int i {0}; i < m; ++i) {
        for (int j {0}; j < n; ++j) {
            if (i == 0 || i == m - 1) {
                std::cout << 'W';
            } else if (i == x && j == y) {
                std::cout << 'O';
            } else if (j == 0 || j == n - 1) {
                std::cout << 'W';
            } else if (value[i][j] == 0 && cost[i][j] == 0) {
                std::cout << '.';
            } else {
                std::cout << 'B';
            }
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}


// 0 Right, 1 up, 2 left, 3 down
bool hitWall(int x, int y, int direction) {
    if (direction == 0) {
    } else if (direction == 1) {
    } else if (direction == 2) {
    } else if (direction == 3) {
    }
    return x + y == direction;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    for (int i = 0; i < 60; ++i) {
        for (int j = 0; j < 60; ++j) {
            value[i][j] = 0;
            cost[i][j] = 0;
        }
    }

    std::ostringstream output;
    int m, n;
    std::cin >> m >> n;
    int wallCost;
    int numberOfBumpers;
    std::cin >> wallCost >> numberOfBumpers;
    for (int i {}; i < numberOfBumpers; ++i) {
        int x, y, bumperValue, bumperCost;
        std::cin >> x >> y >> bumperValue >> bumperCost;
        std::cout << "Setting [" << 4-x << "][" << y-1 << "]\n";
        value[4-x][y-1] = bumperValue;
        cost[4-x][y-1] = bumperCost;
    }
    int x, y, direction, lifetime;
    int totalScore {};
    while (std::cin >> x >> y >> direction >> lifetime) {
        print(m, n, 4-x, y-1);
        int score {};
        while (--lifetime > 0) {
        }
        output << score << '\n';

        direction = (direction + 3) % 4;
    }
    std::cout << output.str() << totalScore << '\n';
}
