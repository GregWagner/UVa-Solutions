// 145 Goodwanalandd Telcom
#include <iomanip>
#include <iostream>
#include <sstream>

struct Rates {
    double day, evening, night;
};

auto getRates(char step) -> Rates {
    switch (step) {
        case 'A':
            return {0.10, 0.06, 0.02};
        case 'B':
            return {0.25, 0.15, 0.05};
        case 'C':
            return {0.53, 0.33, 0.13};
        case 'D':
            return {0.87, 0.47, 0.17};
        case 'E':
            return {1.44, 0.80, 0.30};
        default:
            return {0.0, 0.0, 0.0};
    }
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    char step;
    while (std::cin >> step && step != '#') {
        std::string phoneNumber;
        int startHour, startMinute, endHour, endMinute;
        std::cin >> phoneNumber >> startHour >> startMinute >> endHour >>
            endMinute;

        // convert times to toal minutes since midnight
        int startTime = startHour * 60 + startMinute;
        int endTime = endHour * 60 + endMinute;

        // step minutes by minute from start to end
        int dayMin{}, eveningMin{}, nightMin{};
        int currentTime = startTime;
        bool first{true};
        while (first || currentTime != endTime) {
            first = false;
            int min = currentTime % 1440;
            if (min >= 480 && min < 1080) {
                dayMin++;
            } else if (min >= 1080 && min < 1320) {
                eveningMin++;
            } else {
                nightMin++;
            }
            currentTime = (currentTime + 1) % 1440;
        }

        Rates r = getRates(step);
        double totalCost =
            (dayMin * r.day) + (eveningMin * r.evening) + (nightMin * r.night);
        output << std::setw(10) << phoneNumber << std::setw(6) << dayMin
               << std::setw(6) << eveningMin << std::setw(6) << nightMin
               << std::setw(3) << step << std::setw(8) << std::fixed
               << std::setprecision(2) << totalCost << '\n';
    }
    std::cout << output.str();
}
