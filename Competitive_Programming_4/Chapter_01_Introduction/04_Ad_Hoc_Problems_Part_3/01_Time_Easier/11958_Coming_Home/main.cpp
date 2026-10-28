#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int caseNumber{1};
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int numberOfBuses;
        int currentHour, currentMinute;
        char colon;
        std::cin >> numberOfBuses >> currentHour >> colon >> currentMinute;
        int currentTimeInMinutes = (currentHour * 60) + currentMinute;

        int minimumTotalTime{-1};
        for (int bus{}; bus < numberOfBuses; ++bus) {
            int hour, minute, travelTime;
            std::cin >> hour >> colon >> minute >> travelTime;
            int busStartTimeInMinutes = (hour * 60) + minute;

            int waitTime;
            if (busStartTimeInMinutes >= currentTimeInMinutes) {
                waitTime = busStartTimeInMinutes - currentTimeInMinutes;
            } else {
                waitTime =
                    (busStartTimeInMinutes + 1440) - currentTimeInMinutes;
            }
            int totalTime = waitTime + travelTime;
            if (minimumTotalTime == -1 || totalTime < minimumTotalTime) {
                minimumTotalTime = totalTime;
            }
        }
        output << "Case " << caseNumber++ << ": " << minimumTotalTime
               << std::endl;
    }
    std::cout << output.str();
}
