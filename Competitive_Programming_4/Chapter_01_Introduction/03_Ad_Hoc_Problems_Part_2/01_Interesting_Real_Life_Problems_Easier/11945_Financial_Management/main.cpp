#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

void print_with_commas(std::ostream& os, long long n) {
    if (n < 0) {
        os << '-';
        n = -n;
    }
    std::string s = std::to_string(n);
    int len = static_cast<int>(s.size());
    for (int i{}; i < len; ++i) {
        os << s[i];
        int remaining{len - i - 1};
        if (remaining > 0 && remaining % 3 == 0) {
            os << ',';
        }
    }
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int testCases;
    if (!(std::cin >> testCases)) {
        return 0;
    }
    for (int caseNumber{1}; caseNumber <= testCases; ++caseNumber) {
        double sum{};
        double monthly;
        for (int i{}; i < 12; ++i) {
            std::cin >> monthly;
            sum += monthly;
        }

        double avg{sum / 12.0};
        long long total_cents{llround(avg * 100.0)};
        long long dollars{total_cents / 100};
        long long cents{total_cents % 100};
        if (cents < 0) {
            cents = -cents;
        }
        bool neg{total_cents < 0};
        std::cout << caseNumber << " $";
        if (neg) {
            std::cout << '-';
        }
        print_with_commas(std::cout, std::llabs(dollars));
        std::cout << '.' << std::setw(2) << std::setfill('0') << cents
                  << std::setfill(' ') << '\n';
    }
}
