// 11677 Alarm Clock
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int currentHour, currentMinute, alarmHour, alarmMinute;
    while (true) {
        std::cin >> currentHour >> currentMinute >> alarmHour >> alarmMinute;
        if (currentHour == 0 && currentMinute == 0 && alarmHour == 0 &&
            alarmMinute == 0) {
            break;
        }
        int timeDiff =
            (alarmHour - currentHour) * 60 + (alarmMinute - currentMinute);
        if (timeDiff < 0) {
            timeDiff += 24 * 60;
        }
        output << timeDiff << '\n';
    }
    std::cout << output.str();
}
