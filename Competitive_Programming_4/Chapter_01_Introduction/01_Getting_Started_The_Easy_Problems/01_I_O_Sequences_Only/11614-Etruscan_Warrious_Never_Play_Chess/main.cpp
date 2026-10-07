/*
 * This is an arithmentic sequence ?
 * The total number of warriors required to completely fill n
 * rows is given by the sum of the first n integers
 * (the n-th triangular number):
 *
 * n(n+1)
 * ------ = s
 *   2
 *
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
#include <cstdint>
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    int test_cases {};
    std::cin >> test_cases;
    while (test_cases--) {
        uint64_t number_of_warriors {};
        std::cin >> number_of_warriors;

        double warriors = static_cast<double>(number_of_warriors);
        auto n = static_cast<uint64_t>((-1 + std::sqrt(1 + 8 * warriors)) / 2);
        while (n * (n + 1) / 2 > number_of_warriors) { --n; }
        while ((n + 1) * (n + 2) / 2 <= number_of_warriors) { ++n; }

        output << n << '\n';
    }

    std::cout << output.str();
}
