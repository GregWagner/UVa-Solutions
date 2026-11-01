// 11744 Parallel Carry Adder
#include <iostream>
#include <sstream>

const std::string ALL_ZEROS(31, '0');

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int testCases;
    std::cin >> testCases;
    for (int i{1}; i <= testCases; ++i) {
        if (i > 1) {
            output << '\n';
        }

        std::string a, b;
        std::cin >> a >> b;

        output << a << ' ' << b << '\n';

        while (b != ALL_ZEROS && b != "overflow") {
            std::string nextA = a;
            std::string nextB(31, '0');

            for (int j{}; j < 31; ++j) {
                nextA[j] = (a[j] == b[j]) ? '0' : '1';
            }

            std::string carry(31, '0');
            for (int j{}; j < 31; ++j) {
                if (a[j] == '1' && b[j] == '1') {
                    carry[j] = '1';
                }
            }

            if (carry[0] == '1') {
                nextB = "overflow";
            } else {
                for (int j{}; j < 30; ++j) {
                    nextB[j] = carry[j + 1];
                }
                nextB[30] = '0';
            }

            a = nextA;
            b = nextB;

            output << a << ' ' << b << '\n';
        }
    }
    std::cout << output.str();
}