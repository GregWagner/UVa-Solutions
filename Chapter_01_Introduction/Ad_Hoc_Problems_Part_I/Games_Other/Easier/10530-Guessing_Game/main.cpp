/*
 * Problem 10530 - Guessing Game
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    bool a[11];
    std::ostringstream output;
    int guess;
    std::cin >> guess;
    while (true) {
        if (guess == 0) {
            break;
        }
        for (int i {1}; i <= 10; ++i) {
            a[i] = true;
        }
        bool done {};
        while (!done) {
            std::string second;
            std::cin >> second >> second;
            if (second == "high") {
                for (int i {guess}; i <= 10; ++i) {
                    a[i] = false;
                }
            } else if (second == "low") {
                for (int i {}; i <= guess; ++i) {
                    a[i] = false;
                }
            } else {
                done = true;
                output << "Stan "
                    << (a[guess] ? "may be honest" : "is dishonest") << '\n';
            }
            std::cin >> guess;
        }
    }
    std::cout << output.str();
}
