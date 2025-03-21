/*
 * Problem 10409 - Die Game
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int moves;
    while (std::cin >> moves && moves != 0) {
        int top {1};
        int north {2};
        int west {3};
        int east {4};
        int south {5};
        int bottom {6};
        for (int i {}; i < moves; ++i) {
            std::string move;
            std::cin >> move;
            int oldTop = top;
            if (move == "north") {
                top = south;
                south = bottom;
                bottom = north;
                north = oldTop;
            } else if (move == "south") {
                top = north;
                north = bottom;
                bottom = south;
                south = oldTop;
            } else if (move == "east") {
                top = west;
                west = bottom;
                bottom = east;
                east = oldTop;
            } else {
                top = east;
                east = bottom;
                bottom = west;
                west = oldTop;
            }
        }
        output << top << '\n';
    }
    std::cout << output.str();
}
