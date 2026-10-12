// 1586 Molar Mass
#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

static double massOf(char m) {
    switch (m) {
        case 'C': return 12.01;
        case 'H': return 1.008;
        case 'O': return 16.00;
        case 'N': return 14.01;
        default:  return 0.0;
    }
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        double total{};
        char mol{};
        int count{};

        std::string element;
        std::cin >> element;
        for (char c : element) {
            if (std::isdigit(static_cast<unsigned char>(c))) {
                count = count * 10 + (c - '0');
            } else {
                total += massOf(mol) * (count == 0 ? 1 : count);
                count = 0;
                mol = c;
            }
        }
        total += massOf(mol) * (count == 0 ? 1 : count);
        output << std::fixed << std::setprecision(3) << total << '\n';
    }
    std::cout << output.str();
}