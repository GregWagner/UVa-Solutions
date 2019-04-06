/*
 * Grass Seen Inc.
 */
#include <iostream>
#include <iomanip>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    double cost; 
    int numberOfLawns;
    std::cin >> cost >> numberOfLawns;
    double total {};
    while (numberOfLawns--) {
        double width, length;
        std::cin >> width >> length;
        total += (width * length) * cost;
    }
    std::cout << std::setprecision(10) << total << '\n';
}
