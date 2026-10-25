// 11650 Mirror Clock
#include <iomanip>
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int hour, minute;
        char delimiter;
        std::cin >> hour >> delimiter >> minute;

        if (minute == 0) {
            hour = 12 - hour;
            if (hour == 0) {
                hour = 12;
            }
        } else {
            hour = (11 - hour + 12) % 12;
            if (hour == 0) {
                hour = 12;
            }
            minute = 60 - minute;
        }
        output << std::setfill('0') << std::setw(2) << hour << ":"
               << std::setw(2) << minute << '\n';
    }

    std::cout << output.str();
}
