/*
 * This is an arithmentic sequence ?
 * n(n+1)
 * ------ = s
 *   2
 * n^2 + n = 2s
 * n^2 + n - 2s = 0
 *
 * Using quandratic formula where:
 *      a = 1
 *      b = 1
 *      c = -2s
 * -1 +/- sqrt(1^2 - 4 * 1 * -2s)    -1 +/- sqrt(1 + 8s)
 * ------------------------------ =  -----------------
 *            2 * 1                          2
 *
 *
 * s = 10:
 *      - 1 +/- sqrt(1 + 8 * 10)   -1 +/- sqrt(81)   -1 +/- 9
 *      ------------------------ = --------------- = -------- = 8/2 = 4
 *                   2                     2            2
 * s = 7:
 *      - 1 +/- sqrt(1 + 8 * 7)   -1 +/- sqrt(57)   -1 +/- 7    6/2 = 3
 *      ----------------------- = --------------- = -------- =
 *                   2                      2            2
 * 1) Only need to take add the determinate
 * 2) Floor the sqrt
 */
#include <cmath>
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ostringstream output;

    int test_cases {};
    std::cin >> test_cases;
    while (test_cases--) {
        uint64_t number_of_warriors {};
        std::cin >> number_of_warriors;

        output << static_cast<int64_t>((-1 + std::sqrt(1 + 8 * number_of_warriors)) / 2) << '\n';
    }

    std::cout << output.str();
}
