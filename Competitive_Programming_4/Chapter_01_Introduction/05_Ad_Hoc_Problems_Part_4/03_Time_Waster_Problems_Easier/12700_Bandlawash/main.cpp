#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int testCases;
    std::cin >> testCases;
    for (int i{1}; i <= testCases; ++i) {
        output << "Case " << i << ": ";
        int numberOfMatches;
        std::cin >> numberOfMatches;

        std::string results;
        std::cin >> results;

        int b{}, w{}, t{}, a{};
        for (char c : results) {
            if (c == 'A') {
                ++a;
            } else if (c == 'B') {
                ++b;
            } else if (c == 'T') {
                ++t;
            } else if (c == 'W') {
                ++w;
            }
        }

        if (a == numberOfMatches) {
            output << "ABANDONED\n";
        } else if (b + a == numberOfMatches) {
            output << "BANGLAWASH\n";
        } else if (w + a == numberOfMatches) {
            output << "WHITEWASH\n";
        } else if (b == w) {
            output << "DRAW " << b << " " << t << "\n";
        } else if (b > w) {
            output << "BANGLADESH " << b << " - " << w << "\n";
        } else { // w > b
            output << "WWW " << w << " - " << b << "\n";
        }
    }
    std::cout << output.str();
}
