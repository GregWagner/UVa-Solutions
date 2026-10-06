#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int windSpeed, numOfRoads;
    std::cin >> windSpeed >> numOfRoads;

    for (int i = 0; i < numOfRoads; ++i) {
        std::string roadName;
        int roadSpeed;
        std::cin >> roadName >> roadSpeed;

        std::cout << roadName
            << (roadSpeed < windSpeed ? " lokud\n" : " opin\n");
    }
}