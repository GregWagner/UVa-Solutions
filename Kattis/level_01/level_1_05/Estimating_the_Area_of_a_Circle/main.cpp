/*
 * Estimating the Area of a Circle
 */
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    output << std::setprecision(20);
    double r, m, c;
    while (std::cin >> r >> m >> c) {
        if (r == 0 && m == 0 && c == 0) {
            break;
        }
        double diameter = 2.0 * r;
        double estimate = (c / m) * (diameter * diameter);
        output << M_PI * r * r << ' ' << estimate << '\n';
    }
    std::cout << output.str();
}
