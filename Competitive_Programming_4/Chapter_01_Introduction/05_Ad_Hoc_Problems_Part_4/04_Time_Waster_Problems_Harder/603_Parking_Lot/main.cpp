#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    for (int i = 0; i < testCases; ++i) {
        if (i > 0) {
            output << "\n";
        }
        int p;
        std::vector<std::pair<int, int>> position;
        std::vector<int> waitingCar;

        // Read initial positions of waiting cars until 99
        while (std::cin >> p && p != 99) {
            waitingCar.push_back(p);
            position.push_back(std::pair<int, int>(
                p, p)); // pair of (current_position, original_position)
        }

        sort(position.begin(), position.end());

        int parkingPlaceCar[21];
        memset(parkingPlaceCar, -1, sizeof(parkingPlaceCar));

        std::string line;
        std::cin.ignore();

        while (std::getline(std::cin, line) && line.length() > 0) {
            int parkingPlace;
            std::istringstream in(line);
            in >> parkingPlace;

            int closestPosition{-1};
            for (size_t i{}; i < position.size(); ++i) {
                if (position[i].first > parkingPlace) {
                    if (i == 0) {
                        closestPosition = position.size() - 1;
                    } else {
                        closestPosition = i - 1;
                    }
                    break;
                }
                if (i + 1 == position.size())
                    closestPosition = position.size() - 1;
            }

            parkingPlaceCar[position[closestPosition].second] = parkingPlace;

            int parkingPlaceDist{};
            if (position[closestPosition].first <= parkingPlace) {
                parkingPlaceDist =
                    parkingPlace - position[closestPosition].first;
            } else {
                parkingPlaceDist =
                    parkingPlace + 20 - position[closestPosition].first;
            }

            position.erase(position.begin() + closestPosition);

            for (size_t j = 0; j < position.size(); ++j) {
                position[j].first += parkingPlaceDist;
                if (position[j].first > 20) {
                    position[j].first %= 20;
                }
            }
            sort(position.begin(), position.end());
        }

        for (size_t i{}; i < waitingCar.size(); ++i) {
            output << "Original position " << waitingCar[i];
            if (parkingPlaceCar[waitingCar[i]] == -1) {
                output << " did not park\n";
            } else {
                output << " parked in " << parkingPlaceCar[waitingCar[i]]
                       << "\n";
            }
        }
    }
    std::cout << output.str();
}
