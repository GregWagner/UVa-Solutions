/*
 * Heart Rate
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int b; 
        double p;
        std::cin >> b >> p;
        output << (60 * (b - 1)) / p << " " << (60 * b) / p << " "
            << (60 * (b + 1)) / p << '\n';
    }
    std::cout << output.str();
}
