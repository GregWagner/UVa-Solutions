/*
 * Problem 695 - How Many Knights
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int n, m;
    while (std::cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        if (n == 0 || m == 0) {
            output << 0;
        } else if (n == 1 || m == 1) {
            output << n * m;
        } else if (n == 2 || m == 2) {
            std::cout << "N: " << n << ", M: " << m << '\n';
            int b = std::max(n, m);     // this should be the non 2 number
            std::cout << "B: " << b << '\n';
#if 0
            if (b % 2) {
                ++b;
                std::cout << "B (increcement if odd: " << b << '\n';
            }
#endif
            int results = b / 4;
            int remainder = b % 4;
            std::cout << "Results: " << results << ", Remainder: "
                << remainder << '\n';
            if (remainder >= 2) {
                results += 2;
            } else if (remainder == 1) {
                ++results;
            }
            std::cout << "Results: " << results << '\n';
            std::cout << "Answer: " << results  * 2 << '\n';
            std::cout << "=======================\n";
            output << results * 2;
        }
        output << " knights may be placed on a " << n 
            << " row " << m << " column board.\n";
    }
    std::cout << output.str();
}
