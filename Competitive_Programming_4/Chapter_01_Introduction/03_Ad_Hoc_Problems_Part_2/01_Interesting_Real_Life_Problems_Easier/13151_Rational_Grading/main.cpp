// 13151 Rational Grading
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    std::string ivalue_str;
    int t;
    while (std::cin >> ivalue_str >> t) {
        if (ivalue_str == "0" && t == 0)
            break;

        // strtoll with base 0 auto-detects 0x (hex) and leading 0 (octal).
        long long cur = std::strtoll(ivalue_str.c_str(), nullptr, 0);

        int mark{};
        for (int i{}; i < t; ++i) {
            std::string expr;
            long long x;
            std::cin >> expr >> x;

            long long p{};
            if (expr == "i")
                p = cur;
            else if (expr == "i++")
                p = cur;
            else if (expr == "++i")
                p = cur + 1;
            else if (expr == "i--")
                p = cur;
            else if (expr == "--i")
                p = cur - 1;

            if (p == x) {
                ++mark;
            }

            // Propagate state from the examinee's output (rational grading).
            if (expr == "i")
                cur = x;
            else if (expr == "i++")
                cur = x + 1;
            else if (expr == "++i")
                cur = x;
            else if (expr == "i--")
                cur = x - 1;
            else if (expr == "--i")
                cur = x;
        }
        output << mark << "\n";
    }
    std::cout << output.str();
}
