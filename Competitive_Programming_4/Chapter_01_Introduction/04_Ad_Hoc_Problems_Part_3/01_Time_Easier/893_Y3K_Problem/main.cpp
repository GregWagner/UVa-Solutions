#include <iostream>
#include <sstream>

auto isLeapYear(long long year) -> bool {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

auto daysInMonth(int month, long long year) -> int {
    switch (month) {
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return 31;
    }
}

auto daysInYear(long long year) -> long long {
    return isLeapYear(year) ? 366 : 365;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int numberOfDaysToAdd, day, month, year;
    while (std::cin >> numberOfDaysToAdd >> day >> month >> year) {
        if (numberOfDaysToAdd == 0 && day == 0 && month == 0 && year == 0) {
            break;
        }

        long long cycles = numberOfDaysToAdd / 146097;
        year += cycles * 400;
        numberOfDaysToAdd %= 146097;

        // go year-by-year which number of days is larger than days left
        // in current year
        while (true) {
            int dim = daysInYear(year);
            long long daysPassed = day;
            for (int i{1}; i < month; ++i) {
                daysPassed += daysInMonth(i, year);
            }
            long long daysLeftInYear{dim - daysPassed + 1};

            if (numberOfDaysToAdd >= daysLeftInYear) {
                numberOfDaysToAdd -= daysLeftInYear;
                year++;
                day = 1;
                month = 1;
            } else {
                break;
            }
        }

        // go month by month
        while (true) {
            int dim = daysInMonth(month, year);
            long long daysLeftInMonth{dim - day + 1};

            if (numberOfDaysToAdd >= daysLeftInMonth) {
                numberOfDaysToAdd -= daysLeftInMonth;
                day = 1;
                month++;
                if (month > 12) {
                    month = 1;
                    year++;
                }
            } else {
                day += numberOfDaysToAdd;
                numberOfDaysToAdd = 0;
                break;
            }
        }
        output << day << ' ' << month << ' ' << year << '\n';
    }
    std::cout << output.str();
}
