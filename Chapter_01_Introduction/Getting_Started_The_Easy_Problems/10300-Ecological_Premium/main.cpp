/*
 * Ecological Premium
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int testCases {};
    std::cin >> testCases;
    while (testCases-- != 0) {
        int numberOfFarmers {};
        std::cin >> numberOfFarmers;
        int budget {};
        for (int i {}; i < numberOfFarmers; ++i) {
            int size {};
            int numberOfAnimals {};
            int friendliness {};
            std::cin >> size >> numberOfAnimals >> friendliness;
            budget += friendliness * size;
        }
        output << budget << '\n';
    }

    std::cout << output.str();
}
