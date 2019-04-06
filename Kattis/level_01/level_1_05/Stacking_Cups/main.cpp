/*
 * Stacking Cups
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

struct Cup {
    std::string color;
    int radius;

    bool operator<(Cup a) {
        return radius < a.radius;
    }
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::vector<Cup> cups;

    std::ostringstream output;
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        std::string a, b;
        std::cin >> a >> b;
        Cup cup;
        if (std::isdigit(a[0])) {
            cup.color = b;
            cup.radius = std::stoi(a) / 2;
        } else {
            cup.color = a;
            cup.radius = std::stoi(b);
        }
        cups.push_back(cup);
    }
    std::sort(cups.begin(), cups.end());
    for (auto cup : cups) {
        output << cup.color << '\n';
    }
    std::cout << output.str();
}
