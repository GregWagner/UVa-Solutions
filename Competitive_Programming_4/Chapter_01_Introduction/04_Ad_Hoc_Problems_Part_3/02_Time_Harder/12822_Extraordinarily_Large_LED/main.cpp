#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

const int segCount[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

// Helper function to get total segments for a given score number
auto getSegments(int score) -> int {
    if (score == 0) {
        return segCount[0];
    }
    int total{};
    while (score > 0) {
        total += segCount[score % 10];
        score /= 10;
    }
    return total;
}

auto timeToSeconds(std::string timeStr) -> int {
    int h = stoi(timeStr.substr(0, 2));
    int m = stoi(timeStr.substr(3, 2));
    int s = stoi(timeStr.substr(6, 2));
    return h * 3600 + m * 60 + s;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string type;
    int caseNum = 1;

    while (std::cin >> type) {
        if (type == "END") {
            break;
        }

        int prevTime{};
        int homeScore{};
        int guestScore{};
        long long totalCost{};

        std::string timeStr;
        int points;

        std::cin >> timeStr;
        prevTime = timeToSeconds(timeStr);

        std::string command;
        while (std::cin >> command) {
            if (command == "END") {
                std::string endTime;
                std::cin >> endTime;
                int currTime{timeToSeconds(endTime)};
                int dt{currTime - prevTime};

                totalCost +=
                    dt * (getSegments(homeScore) + getSegments(guestScore));
                prevTime = currTime;
                break;
            }

            if (command == "SCORE") {
                std::string team;
                std::cin >> timeStr >> team >> points;
                int currTime{timeToSeconds(timeStr)};
                int dt{currTime - prevTime};

                totalCost +=
                    dt * (getSegments(homeScore) + getSegments(guestScore));

                if (team == "home") {
                    homeScore += points;
                } else {
                    guestScore += points;
                }
                prevTime = currTime;
            }
        }

        output << "Case " << caseNum++ << ": " << totalCost << "\n";
    }
    std::cout << output.str();
}