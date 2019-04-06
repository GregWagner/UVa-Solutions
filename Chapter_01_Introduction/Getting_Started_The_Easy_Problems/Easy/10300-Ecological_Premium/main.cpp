/*
 * Problem 10300 - Ecological Premium
 *
 * space per animal * environment_friendliness * number of animals
 * note: number of animals factors out
 *
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int burden {};
        int numberOfFarmers;
        std::cin >> numberOfFarmers;
        for (int i {}; i < numberOfFarmers; ++i) {
            int size;
            int numberOfAnimals;
            int environmentFriendliness;
            std::cin >> size >> numberOfAnimals >> environmentFriendliness;
            burden += (size * environmentFriendliness);
        }
        output << burden << '\n';
    }
    std::cout << output.str();
}
