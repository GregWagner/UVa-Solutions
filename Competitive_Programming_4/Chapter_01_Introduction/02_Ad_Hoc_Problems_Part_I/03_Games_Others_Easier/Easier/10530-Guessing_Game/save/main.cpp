/*
 * Problem 10530 - Guessing Game
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(false);
    std::ostringstream output;

    int low = -1;
    int high = 99;

    std::string s;
    int n;
    while (std::cin >> n && n != 0) {

        std::cin >> s;
        std::cin >> s;
        if (s == "high") {
            if (n < high) {
                high = n;
            }
        } else if (s == "low") {
            if (n > low) {
                low = n;
            }
        } else if (s == "on") {
            if ((high > low) && (high > n) && (low < n)) {
                output << "Stan may be honest\n";
            } else {
                output << "Stan is dishonest\n";
            }
            low = -1;
            high = 99;
        }
    }
    std::cout << output.str();
}
