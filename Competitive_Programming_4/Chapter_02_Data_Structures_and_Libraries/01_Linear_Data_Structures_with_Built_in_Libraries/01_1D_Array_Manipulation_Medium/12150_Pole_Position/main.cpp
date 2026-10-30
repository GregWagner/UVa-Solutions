#include <iostream>
#include <sstream>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int numberOfCars;
    while (std::cin >> numberOfCars && numberOfCars != 0) {
        std::vector<int> startingPositions(numberOfCars + 1, 0);
        bool possible{true};

        for (int i{1}; i <= numberOfCars; ++i) {
            int carNumber, position;
            std::cin >> carNumber >> position;
            int startPos = i + position;
            if (startPos < 1 || startPos > numberOfCars ||
                startingPositions[startPos] != 0) {
                possible = false;
            } else {
                startingPositions[startPos] = carNumber;
            }
        }

        if (possible) {
            for (int i{1}; i <= numberOfCars; ++i) {
                if (i > 1) {
                    output << ' ';
                }
                output << startingPositions[i];
            }
            output << '\n';
        } else {
            output << "-1\n";
        }
    }
    std::cout << output.str();
}
