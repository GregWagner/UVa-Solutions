// 12342 Tax Calculator
#include <cmath>
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int caseNumber{1};
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        long long income;
        std::cin >> income;

        double tax{};
        long long remaining = income;

        remaining = (remaining > 180000) ? remaining - 180000 : 0;

        // next 300000 taxed at 10%
        if (remaining > 0) {
            long long taxable = std::min(remaining, 300000LL);
            tax += taxable * 0.10;
            remaining -= taxable;
        }

        // next 400000 taxed at 15%
        if (remaining > 0) {
            long long taxable = std::min(remaining, 400000LL);
            tax += taxable * 0.15;
            remaining -= taxable;
        }

        // next 300000 taxed at 20%
        if (remaining > 0) {
            long long taxable = std::min(remaining, 300000LL);
            tax += taxable * 0.20;
            remaining -= taxable;
        }

        // remaining taxed at 25%
        if (remaining > 0) {
            tax += remaining * 0.25;
        }

        if (income > 180000 && tax < 2000.0 && tax > 0.0) {
            tax = 2000.0;
        }

        output << "Case " << caseNumber++ << ": " << (long long)std::ceil(tax)
               << "\n";
    }
    std::cout << output.str();
}
