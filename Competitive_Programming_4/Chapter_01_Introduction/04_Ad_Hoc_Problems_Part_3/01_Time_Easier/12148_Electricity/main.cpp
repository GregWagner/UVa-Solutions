#include <iostream>
#include <sstream>

auto isLeapYear(int y) -> bool {
    return (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0);
}
auto daysInMonth(int m, int y) -> int {
    if (m == 2) {
        return isLeapYear(y) ? 29 : 28;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    }
    return 31;
}

auto isNextDay(int d1, int m1, int y1, int d2, int m2, int y2) -> bool {
    // same month and year
    if (y1 == y2 && m1 == m2 && d2 == d1 + 1) {
        return true;
    }
    // Month roll-over within same year
    if (y1 == y2 && m2 == m1 + 1 && d1 == daysInMonth(m1, y1) && d2 == 1) {
        return true;
    }
    // Year roll-over (Dec 31 -> Jan 1)
    if (y2 == y1 + 1 && m1 == 12 && m2 == 1 && d1 == 31 && d2 == 1) {
        return true;
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int numberOfMeasures;
    while (std::cin >> numberOfMeasures && numberOfMeasures != 0) {
        int previousDay, previousMonth, previousYear, previousComsumption;
        std::cin >> previousDay >> previousMonth >> previousYear >>
            previousComsumption;

        int validMeasures{};
        long long totalComsumption{};

        for (int i{}; i < numberOfMeasures - 1; ++i) {
            int currentDay, currentMonth, currentYear, currentComsumption;
            std::cin >> currentDay >> currentMonth >> currentYear >>
                currentComsumption;

            if (isNextDay(previousDay, previousMonth, previousYear, currentDay,
                          currentMonth, currentYear)) {
                ++validMeasures;
                totalComsumption += (currentComsumption - previousComsumption);
            }
            previousDay = currentDay;
            previousMonth = currentMonth;
            previousYear = currentYear;
            previousComsumption = currentComsumption;
        }
        output << validMeasures << " " << totalComsumption << "\n";
    }

    std::cout << output.str();
}
