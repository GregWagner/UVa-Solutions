// 12439 February 29
#include <iostream>
#include <sstream>
#include <unordered_map>

// map month names to numbers
std::unordered_map<std::string, int> months = {
    {"January", 1},   {"February", 2}, {"March", 3},     {"April", 4},
    {"May", 5},       {"June", 6},     {"July", 7},      {"August", 8},
    {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}};

// returns number of leap years from year 1 up to year y
auto countLeapYears(long long year) -> long long {
    if (year < 0) {
        return 0;
    }
    return (year / 4) - (year / 100) + (year / 400);
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    for (int i{1}; i <= testCases; ++i) {
        std::string startMonth, endMonth;
        int startDay, startYear, endDay, endYear;
        char skip;
        std::cin >> startMonth >> startDay >> skip >> startYear >> endMonth >>
            endDay >> skip >> endYear;

        // adjust start year
        if (months[startMonth] > 2) {
            ++startYear;
        }

        if ((months[endMonth] < 2) || (months[endMonth] == 2 && endDay < 29)) {
            --endYear;
        }

        long long totalLeapYears{countLeapYears(endYear) -
                                 countLeapYears(startYear - 1)};
        output << "Case " << i << ": " << totalLeapYears << "\n";
    }
    std::cout << output.str();
}
