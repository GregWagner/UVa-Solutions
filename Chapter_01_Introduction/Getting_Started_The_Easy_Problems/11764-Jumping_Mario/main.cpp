/*
 * Jumping Mario
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCase {};

    int testCases {};
    std::cin >> testCases;
    while (testCases-- != 0) {
        int numberOfWalls {};
        int highJumps {};
        int lowJumps {};
        std::cin >> numberOfWalls;
        int previousWall {};
        std::cin >> previousWall;
        while (--numberOfWalls != 0) {
            int currentWall {};
            std::cin >> currentWall;
            if (currentWall != previousWall) {
                currentWall > previousWall ? ++highJumps : ++lowJumps;
            }
            previousWall = currentWall;
        }
        output << "Case " << ++testCase << ": " <<
            highJumps << " " << lowJumps << '\n';
    }
    std::cout << output.str();
}
