#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

// Check Gregorian leap year
auto isLeap(long long year) -> bool {
    if (year % 400 == 0) {
        return true;
    }
    if (year % 100 == 0) {
        return false;
    }
    return year % 4 == 0;
}

// Get maximum days in a month for a given year
auto getDaysInMonth(long long year, int month) -> int {
    if (month < 1 || month > 12) {
        return 0;
    }
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeap(year)) {
        return 29;
    }
    return days[month];
}

struct Date {
    long long y;
    int m, d;
    bool operator<(const Date& other) const {
        if (y != other.y) {
            return y < other.y;
        }
        if (m != other.m) {
            return m < other.m;
        }
        return d < other.d;
    }
};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        long long century;
        int a, b, c;
        if (!(std::cin >> century >> a >> b >> c)) {
            return 0;
        }

        std::vector<int> nums = {a, b, c};
        std::sort(nums.begin(), nums.end());

        std::vector<Date> validDates;

        // Try all 6 permutations of the 3 numbers
        do {
            int yy{nums[0]};
            int mm{nums[1]};
            int dd{nums[2]};

            long long fullYear = century * 100LL + yy;

            if (mm >= 1 && mm <= 12) {
                int maxD = getDaysInMonth(fullYear, mm);
                if (dd >= 1 && dd <= maxD) {
                    validDates.push_back({fullYear, mm, dd});
                }
            }
        } while (next_permutation(nums.begin(), nums.end()));

        if (validDates.empty()) {
            output << "-1\n";
        } else {
            sort(validDates.begin(), validDates.end());
            auto earliest = validDates[0];
            int yy = static_cast<int>(earliest.y % 100);
            output << std::setfill('0') << std::setw(2) << yy << " "
                   << std::setw(2) << earliest.m << " "
                   << std::setw(2) << earliest.d << "\n";
            output << std::setfill(' ');
        }
    }
    std::cout << output.str();
}
