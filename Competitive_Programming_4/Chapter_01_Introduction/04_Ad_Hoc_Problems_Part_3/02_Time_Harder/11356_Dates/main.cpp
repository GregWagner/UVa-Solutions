// 11356 Dates
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

const std::vector<std::string> MONTH_NAMES = {
    "",     "January", "February",  "March",   "April",    "May",     "June",
    "July", "August",  "September", "October", "November", "December"};

auto isLeap(int y) -> bool {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

auto daysInMonth(int y, int m) -> int {
    if (m == 2) {
        return isLeap(y) ? 29 : 28;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    }
    return 31;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    for (int i{1}; i <= testCases; ++i) {
        std::string date;
        long long increment;
        std::cin >> date >> increment;

        int year, day;
        char monthStr[20];
        sscanf(date.c_str(), "%d-%[^-]-%d", &year, monthStr, &day);

        std::string nameOfMonth(monthStr);
        int month = 1;
        for (int i{1}; i <= 12; ++i) {
            if (MONTH_NAMES[i] == nameOfMonth) {
                month = i;
                break;
            }
        }

        while (increment > 0) {
            int dim{daysInMonth(year, month)};
            int daysLeft{dim - day};
            if (increment > daysLeft) {
                increment -= (daysLeft + 1);
                day = 1;
                month++;
                if (month > 12) {
                    month = 1;
                    year++;
                }
            } else {
                day += increment;
                increment = 0;
            }
        }

        output << "Case " << i << ": "
        << year << '-'
        << MONTH_NAMES[month] << '-'
        << std::setw(2) << std::setfill('0') << day << '\n';
    }
    std::cout << output.str();
}
