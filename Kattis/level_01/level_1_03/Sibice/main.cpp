/*
 * Sibice
 */
#include <iostream>
#include <cmath>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;

    int numberOfMatches, w, h;
    std::cin >> numberOfMatches >> w >> h;
    double max = std::sqrt(w * w + h * h);
    for (int i {}; i < numberOfMatches; ++i) {
        int length;
        std::cin >> length;
        output << (length <= max ? "DA" : "NE") << '\n';
    }
    std::cout << output.str();
}
