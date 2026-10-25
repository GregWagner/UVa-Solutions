// 10070 Leap Year or Not Leap Year
#include <iostream>
#include <sstream>
#include <string>

static int remainder(const std::string& s, int m) {
    int r = 0;
    for (char c : s)
        r = (r * 10 + (c - '0')) % m;
    return r;
}

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    std::string year;
    bool first{true};
    while (std::cin >> year) {
        if (!first)
            output << '\n';
        first = false;
        bool leap = (remainder(year, 4) == 0 && remainder(year, 100) != 0) ||
                    remainder(year, 400) == 0;
        bool hulu = remainder(year, 15) == 0;
        bool bulu = leap && remainder(year, 55) == 0;
        if (leap)
            output << "This is leap year.\n";
        if (hulu)
            output << "This is huluculu festival year.\n";
        if (bulu)
            output << "This is bulukulu festival year.\n";
        if (!leap && !hulu && !bulu)
            output << "This is an ordinary year.\n";
    }
    std::cout << output.str();
}
