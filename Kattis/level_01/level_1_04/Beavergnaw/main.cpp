/*
 * Beavergnaw
 */
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    output << std::setprecision(20);
    double d, v;
    while (std::cin >> d >> v) {
        if (d == 0 && v == 0) {
            break;
        }
        output << std::cbrt((d * d * d) - ((6.0 * v) / M_PI)) << '\n';
    }
    std::cout << output.str();
}
