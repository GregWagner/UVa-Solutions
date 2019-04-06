/*
 * Herman
 */
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int radius;
    std::cin >> radius;
    output << std::setprecision(30);
    output << M_PI * radius * radius << '\n';
    output << 2 * radius * radius << '\n';
    std::cout << output.str();
}
