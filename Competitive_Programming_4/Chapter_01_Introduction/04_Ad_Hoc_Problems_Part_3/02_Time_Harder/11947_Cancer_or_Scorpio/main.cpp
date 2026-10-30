#include <iomanip>
#include <iostream>
#include <sstream>

auto isLeap(int year) -> bool {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

auto getDaysInMonth(int month, int year) -> int {
    if (month == 2) {
        return isLeap(year) ? 29 : 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

auto add_280_days(int& month, int& day, int& year) -> void {
    int days_to_add{280};
    while (days_to_add > 0) {
        int dim = getDaysInMonth(month, year);
        int remaining_in_month = dim - day;
        if (days_to_add > remaining_in_month) {
            days_to_add -= (remaining_in_month + 1);
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        } else {
            day += days_to_add;
            days_to_add = 0;
        }
    }
}

auto get_zodiac(int month, int day) -> std::string {
    if ((month == 1 && day >= 21) || (month == 2 && day <= 19))
        return "aquarius";
    if ((month == 2 && day >= 20) || (month == 3 && day <= 20))
        return "pisces";
    if ((month == 3 && day >= 21) || (month == 4 && day <= 20))
        return "aries";
    if ((month == 4 && day >= 21) || (month == 5 && day <= 21))
        return "taurus";
    if ((month == 5 && day >= 22) || (month == 6 && day <= 21))
        return "gemini";
    if ((month == 6 && day >= 22) || (month == 7 && day <= 22))
        return "cancer";
    if ((month == 7 && day >= 23) || (month == 8 && day <= 21))
        return "leo";
    if ((month == 8 && day >= 22) || (month == 9 && day <= 23))
        return "virgo";
    if ((month == 9 && day >= 24) || (month == 10 && day <= 23))
        return "libra";
    if ((month == 10 && day >= 24) || (month == 11 && day <= 22))
        return "scorpio";
    if ((month == 11 && day >= 23) || (month == 12 && day <= 22))
        return "sagittarius";
    return "capricorn"; // (m == 12 && d >= 23) || (m == 1 && d <= 20)
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    for (int i{1}; i <= testCases; ++i) {
        std::string dateAsAString;
        std::cin >> dateAsAString;

        int month{stoi(dateAsAString.substr(0, 2))};
        int day{stoi(dateAsAString.substr(2, 2))};
        int year{stoi(dateAsAString.substr(4, 4))};

        add_280_days(month, day, year);

        output << i << " " << std::setw(2) << std::setfill('0')
               << month << "/" << std::setw(2) << std::setfill('0') << day
               << "/" << year << " " << get_zodiac(month, day) << "\n";
    }
    std::cout << output.str();
}
