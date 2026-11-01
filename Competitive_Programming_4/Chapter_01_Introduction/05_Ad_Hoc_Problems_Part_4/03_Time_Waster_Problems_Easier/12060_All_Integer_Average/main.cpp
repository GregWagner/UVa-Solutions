// 12060 - All Integer Average
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

auto gcd(int a, int b) -> int {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

auto numDigits(int n) -> int {
    if (n == 0) {
        return 1;
    }
    n = n < 0 ? -n : n;
    int count{};
    while (n > 0) {
        ++count;
        n /= 10;
    }
    return count;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int n;
    int caseNumber{1};
    while (std::cin >> n && n != 0) {
        int sum{};
        for (int i{}; i < n; ++i) {
            int value;
            std::cin >> value;
            sum += value;
        }
        output << "Case " << caseNumber++ << ":\n";

        if (sum % n == 0) {
            if (sum < 0) {
                output << "- ";
            }
            output << std::abs(sum / n) << '\n';
            continue;
        }

        bool isNegative{sum < 0};
        int absoluteSum{std::abs(sum)};

        int integerPart{absoluteSum / n};
        int remainder{absoluteSum % n};

        int gcdValue{gcd(remainder, n)};
        int numerator{remainder / gcdValue};
        int denominator{n / gcdValue};

        int longest{std::max(numDigits(numerator), numDigits(denominator))};
        int lengthA{integerPart > 0 ? numDigits(integerPart) : 0};
        int signLength{isNegative ? 2 : 0};
        int prefixLength{signLength + lengthA};

        int line1Spaces{prefixLength + longest - numDigits(numerator)};
        output << std::string(line1Spaces, ' ') << numerator << '\n';

        if (isNegative) {
            output << "- ";
        }
        if (integerPart > 0) {
            output << integerPart;
        }
        output << std::string(longest, '-') << '\n';
        output << std::string(prefixLength, ' ') << denominator << '\n';
    }
    std::cout << output.str();
}