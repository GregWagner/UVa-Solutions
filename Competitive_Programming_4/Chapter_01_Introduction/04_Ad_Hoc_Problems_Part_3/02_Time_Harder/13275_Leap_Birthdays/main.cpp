// 13275 Leap Birthdays
#include <iostream>
#include <sstream>

auto leapCountUpTo(long long n) -> long long {
    if (n < 1) return 0;
    return n / 4 - n / 100 + n / 400;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    for (int i{1}; i <= testCases; ++i) {
        long long day, month, year, queryYear;
        std::cin >> day >> month >> year >> queryYear;

        long long birthdayCount{};
        if (month == 2 && day == 29) {
            long long a{year + 1};
            long long b{queryYear};
            if (b >= a) {
                birthdayCount = leapCountUpTo(b) - leapCountUpTo(a - 1);
            }
        } else {
            birthdayCount = queryYear - year;
            if (birthdayCount < 0) birthdayCount = 0;
        }
        output << "Case " << i << ": " << birthdayCount << '\n';
    }

    std::cout << output.str();
}