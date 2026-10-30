// 300 - Maya Calendar
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const std::vector<std::string> HAAB_MONTHS = {
    "pop",  "no",   "zip",   "zotz",  "tzec", "xul", "yoxkin",
    "mol",  "chen", "yax",   "zac",   "ceh",  "mac", "kankin",
    "muan", "pax",  "koyab", "cumhu", "uayet"};

const std::vector<std::string> TZOLKIN_NAMES = {
    "imix",  "ik",    "akbal", "kan",   "chicchan", "cimi", "manik",
    "lamat", "muluk", "ok",    "chuen", "eb",       "ben",  "ix",
    "mem",   "cib",   "caban", "eznab", "canac",    "ahau"};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    output << testCases << '\n';

    for (int i{0}; i < testCases; ++i) {
        int day, year;
        char skip;
        std::string month;
        std::cin >> day >> skip >> month >> year;

        int monthIndex = 0;
        for (int m{0}; m < (int)HAAB_MONTHS.size(); ++m) {
            if (HAAB_MONTHS[m] == month) {
                monthIndex = m;
                break;
            }
        }

        int totalDays = (year * 365) + (monthIndex * 20) + day;

        int tzolkinYear = totalDays / 260;
        int remainingDays = totalDays % 260;
        int number = (remainingDays % 13) + 1;
        int nameIndex = remainingDays % 20;
        std::string name = TZOLKIN_NAMES[nameIndex];

        output << number << ' ' << name << ' ' << tzolkinYear << '\n';
    }
    std::cout << output.str();
}