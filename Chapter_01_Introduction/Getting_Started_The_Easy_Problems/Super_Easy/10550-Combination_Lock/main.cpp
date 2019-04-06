/*
 * Problem 10550 - Combination Lock
 */
#include <iostream>
#include <sstream>

int countTicks(int a, int b) {
    int ticks {a - b};
    return (ticks < 0 ? ticks + 40 : ticks);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    constexpr int DEGREES_PER_TICK {9};
    constexpr int EXTRA_TURNS {1080};

    std::ostringstream output;
    while (true) {
        int start, a, b, c;
        std::cin >> start >> a >> b >> c;
        if (start == 0 && a == 0 && b == 0 && c == 0) {
            break;
        }

        // first turn counterclockwis
        int totalTicks {countTicks(start, a)};

        // second turn clockwise
        totalTicks += countTicks(b, a);

        // thrid turn counterclockwise
        totalTicks += countTicks(b, c);

        // convert ticks to degrees and add in the constant extra turns
        output << (EXTRA_TURNS + (DEGREES_PER_TICK * totalTicks)) << '\n';
    }
    std::cout << output.str();
}
