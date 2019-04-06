/*
 * Cetvrta
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int x[3];
    int y[3];
    for (int i {}; i < 3; ++i) {
        std::cin >> x[i] >> y[i];
    }
    int xCoord {x[0]};
    if (x[0] == x[1]) {
        xCoord = x[2];
    } else if (x[0] == x[2]) {
        xCoord = x[1];
    }
    int yCoord {y[0]};
    if (y[0] == y[1]) {
        yCoord = y[2];
    } else if (y[0] == y[2]) {
        yCoord = y[1];
    }
    std::cout << xCoord << " " << yCoord << '\n';
}
