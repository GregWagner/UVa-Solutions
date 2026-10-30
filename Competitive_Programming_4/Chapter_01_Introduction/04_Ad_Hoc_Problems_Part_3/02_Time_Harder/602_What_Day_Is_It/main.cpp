#include <iostream>
#include <sstream>
#include <vector>

const std::vector<std::string> MONTH_NAMES = {
    "",     "January", "February",  "March",   "April",    "May",     "June",
    "July", "August",  "September", "October", "November", "December"};

const std::vector<std::string> WEEKDAY_NAMES = {
    "Sunday",   "Monday", "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday"};

const int DAYS_IN_MONTH[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

auto isJulian(int m, int d, int y) -> bool {
    if (y < 1752)
        return true;
    if (y > 1752)
        return false;
    if (m < 9)
        return true;
    if (m > 9)
        return false;
    return d <= 2;
}

// Check leap year status based on calendar regime
auto isLeapYear(int y, bool julian) -> bool {
    if (julian) {
        return (y % 4 == 0);
    }
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

auto isValidDate(int m, int d, int y) -> bool {
    if (y <= 0 || m < 1 || m > 12 || d < 1) {
        return false;
    }

    // Disallowed transition window
    if (y == 1752 && m == 9 && d >= 3 && d <= 13) {
        return false;
    }

    bool julian{isJulian(m, d, y)};
    int max_days{DAYS_IN_MONTH[m]};
    if (m == 2 && isLeapYear(y, julian)) {
        max_days = 29;
    }
    return d <= max_days;
}

// Calculate total absolute days from 1/1/1 AD
auto getAbsoluteDays(int m, int d, int y) -> long long {
    bool julian = isJulian(m, d, y);
    long long totalDays{};

    if (julian) {
        // Julian calendar math up to (y - 1)
        long long y_prev{y - 1};
        totalDays = y_prev * 365 + (y_prev / 4);

        // Add months of current year
        for (int i{1}; i < m; ++i) {
            totalDays += DAYS_IN_MONTH[i];
            if (i == 2 && isLeapYear(y, true)) {
                totalDays += 1;
            }
        }
        totalDays += d;
    } else {
        // Base days up to Sept 2, 1752 (Julian)
        // 1751 full Julian years + months up to Aug 1752 + 2 days of Sept
        long long julianBase{1751LL * 365 + (1751LL / 4)}; // days to 12/31/1751
        for (int i{1}; i < 9; ++i) {
            julianBase += DAYS_IN_MONTH[i];
            if (i == 2 && isLeapYear(1752, true)) {
                julianBase += 1;
            }
        }
        julianBase += 2; // Sept 2, 1752

        // Gregorian days after Sept 14, 1752
        // Sept 14, 1752 is day (julianBase + 1)
        long long gregorianDays{};

        // If same year 1752
        if (y == 1752) {
            if (m == 9) {
                gregorianDays = d - 14 + 1;
            } else {                          // m > 9
                gregorianDays = (30 - 14 + 1); // remaining days in Sept
                for (int i = 10; i < m; ++i) {
                    gregorianDays += DAYS_IN_MONTH[i];
                }
                gregorianDays += d;
            }
        } else {
            // Finish 1752
            gregorianDays = (30 - 14 + 1) + 31 + 30 +
                          31; // Sept 14-30 + Oct + Nov + Dec

            // Full Gregorian years from 1753 to y - 1
            for (int yr{1753}; yr < y; ++yr) {
                gregorianDays += isLeapYear(yr, false) ? 366 : 365;
            }

            // Current year months
            for (int i{1}; i < m; ++i) {
                gregorianDays += DAYS_IN_MONTH[i];
                if (i == 2 && isLeapYear(y, false))
                    gregorianDays += 1;
            }
            gregorianDays += d;
        }
        totalDays = julianBase + gregorianDays;
    }
    return totalDays;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int month, day, year;
    while (std::cin >> month >> day >> year) {
        if (day == 0 && month == 0 && year == 0) {
            break;
        }
        if (!isValidDate(month, day, year)) {
            output << month << '/' << day << '/' << year
                   << " is an invalid date.\n";
        } else {
            long long days{getAbsoluteDays(month, day, year)};
            int weekDayIndex = (days + 5) % 7;
            output << MONTH_NAMES[month] << " " << day << ", " << year
                   << " is a " << WEEKDAY_NAMES[weekDayIndex] << "\n";
        }
    }
    std::cout << output.str();
}
