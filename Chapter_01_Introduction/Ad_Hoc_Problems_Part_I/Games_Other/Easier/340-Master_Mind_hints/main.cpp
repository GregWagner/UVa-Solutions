/*
 * Problem 340 - Master Mind Hints
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int origCode[1000];
    int code[1000];
    int guess[1000];

    std::ostringstream output;
    int length;
    int gameNumber {};
    while (std::cin >> length && length != 0) {
        for (int i {}; i < length; ++i) {
            std::cin >> origCode[i];
        }
        output << "Game " << ++gameNumber << ":\n";
        while (true) {
            for (int i {}; i < length; ++i) {
                code[i] = origCode[i];
            }
            bool done {};
            int strong {};
            int weak {};
            for (int i {}; i < length; ++i) {
                std::cin >> guess[i];
                if (guess[i] == 0) {
                    done = true;
                } else if (guess[i] == code[i]) {
                    ++strong;
                    guess[i] = 0;
                    code[i] = 0;
                }
            }
            if (done) {
                break;
            } else {
                for (int i {}; i < length; ++i) {
                    for (int j {}; j < length; ++j) {
                        if (i != j && guess[i] != 0 && guess[i] == code[j]) {
                            ++weak;
                            code[j] = 0;
                            guess[i] = 0;
                        }
                    }
                }
            }
            output << "    (" << strong << "," << weak << ")\n";
        }
    }
    std::cout << output.str();
}
