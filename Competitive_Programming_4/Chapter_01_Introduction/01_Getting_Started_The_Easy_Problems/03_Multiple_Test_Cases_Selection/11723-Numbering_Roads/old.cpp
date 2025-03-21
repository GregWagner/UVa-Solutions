/*
 * 11723 Numbering Roads
 */
#include <iostream>
#include <sstream>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int numberOfRoads {};
    int numberOfInts {};
    int testCase {};
    while (std::cin >> numberOfRoads >> numberOfInts && numberOfRoads != 0 && numberOfInts != 0) {
        output << "Case " << ++testCase << ": ";
            int x = std::ceil(numberOfRoads / numberOfInts);
            if (x <= 26) {
                if (numberOfRoads % numberOfInts == 0) {
                    output << x - 1 << '\n';
                } else if (x <= 26) {
                    output << x << '\n';
                }
            } else {
                output << "impossible\n";
            }
    }
    std::cout << output.str();
}
