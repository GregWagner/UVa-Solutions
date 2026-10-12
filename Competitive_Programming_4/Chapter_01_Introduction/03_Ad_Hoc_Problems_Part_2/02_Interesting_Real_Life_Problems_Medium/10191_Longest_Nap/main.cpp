// 10191 Longest Nap
// notes: no nap can start before 10:00 or end after 18:00
// appointments can occur in any order
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <utility>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int day{1};
    int n;
    while (std::cin >> n) {
        std::vector<std::pair<int, int>> times;
        int startHour, startMinute, endHour, endMinute;
        char colon;
        while (n--) {
            std::cin >> startHour >> colon >> startMinute >> endHour >> colon >>
                endMinute;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            int normalizedStartTime{(startHour - 10) * 60 + startMinute};
            int normalizedEndTime{(endHour - 10) * 60 + endMinute};
            times.emplace_back(normalizedStartTime, normalizedEndTime);
        }

        std::sort(times.begin(), times.end());

        int currentTime{};  // minutes since 10:00
        int maxNapLength{};
        int bestStartTime{};

        for (const auto& appointment : times) {
            int gap = appointment.first - currentTime;
            if (gap > maxNapLength) {
                maxNapLength = gap;
                bestStartTime = currentTime;
            }
            currentTime = std::max(currentTime, appointment.second);
        }

        int tailGap{480 - currentTime};  // 18:00 is 480 minutes after 10:00
        if (tailGap > maxNapLength) {
            maxNapLength = tailGap;
            bestStartTime = currentTime;
        }

        int napHour{10 + bestStartTime / 60};
        int napMinute{bestStartTime % 60};

        output << "Day #" << day++ << ": the longest nap starts at "
               << std::setfill('0') << std::setw(2) << napHour << ':'
               << std::setw(2) << napMinute << " and will last for ";
        if (maxNapLength >= 60) {
            output << maxNapLength / 60 << " hours and " << maxNapLength % 60
                   << " minutes.\n";
        } else {
            output << maxNapLength << " minutes.\n";
        }
    }

    std::cout << output.str();
}
