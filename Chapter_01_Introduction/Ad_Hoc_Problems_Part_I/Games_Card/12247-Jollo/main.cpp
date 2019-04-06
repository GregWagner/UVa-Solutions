/*
 * Problem 12247 - Jollo
 */
#include <iostream>
#include <sstream>

int princess[3];
int prince[2];

bool cantWin {};

bool check_win(int a, int b, int c, int x, int y, int &nextCard) {
    int wins {};

    if (princess[a - 1] < prince[x]) {
        ++wins;
    }
    if (princess[b - 1] < prince[y]) {
        ++wins;
    }
    switch (wins) {
        case 0:         
            cantWin = true;
            return false;
        case 1:
            nextCard = princess[c - 1] + 1;
            break;
        case 2:
            nextCard = 0;
    }
    return true;
}

bool valid_lowest(int lowest) {
    for (int i = 0; i < 3; ++i) {
        if (lowest == princess[i]) {
            return true;
        }
    }
    for (int i = 0; i < 2; ++i) {
        if (lowest == prince[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    while (true) {
        cantWin = false;
        std::cin >> princess[0] >> princess[1] >> princess[2];
        if (princess[0] == 0) {
            break;
        }
        std::cin >> prince[0] >> prince[1];
        int lowest {};

        int card;
        if (check_win(1, 2, 3, 0, 1, card)) {
            lowest = std::max(lowest, card);
        } if (check_win(1, 2, 3, 1, 0, card)) {
            lowest = std::max(lowest, card);
        } if (check_win(1, 3, 2, 0, 1, card)) {
            lowest = std::max(lowest, card);
        } if (check_win(1, 3, 2, 1, 0, card)) {
            lowest = std::max(lowest, card);
        } if (check_win(2, 1, 3, 1, 0, card)) {
            lowest = std::max(lowest, card);
        } if (check_win(2, 1, 3, 0, 1, card)) {
            lowest = std::max(lowest, card);
        } if (check_win(2, 3, 1, 1, 0, card)) {
            lowest = std::max(lowest, card);
        } if (check_win(2, 3, 1, 0, 1, card)) {
            lowest = std::max(lowest, card);
        } if (check_win(3, 1, 2, 1, 0, card)) {
            lowest = std::max(lowest, card);
        } if (check_win(3, 1, 2, 0, 1, card)) {
            lowest = std::max(lowest, card);
        } if (check_win(3, 2, 1, 1, 0, card)) {
            lowest = std::max(lowest, card);
        } if (check_win(3, 2, 1, 0, 1, card)) {
            lowest = std::max(lowest, card);
        }

        if (!cantWin) {
            lowest = (lowest == 0 ? 1 : lowest);
            while (valid_lowest(lowest)) {
                ++lowest;
                if (lowest > 52) {
                    cantWin = true;
                    break;
                }
            }
        }

        output << (cantWin ? -1 : lowest) << '\n';
    }
    std::cout << output.str();
}
