/*
 * Problem 389 - Hangman Judge
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<char> a;
std::vector<char> guesses_made;

int main() {
    std::ios::sync_with_stdio(false);
    std::ostringstream output;

    int game;

    while (std::cin >> game && game != -1) {
        std::string word;
        std::cin >> word;

        a.clear();
        guesses_made.clear();

        for (unsigned i {}; i < word.size(); ++i) {
            a.push_back(word[i]);
        }
        std::sort(a.begin(), a.end());
        auto it = std::unique(a.begin(), a.end());
        a.resize(std::distance(a.begin(), it));

        int misses {};

        std::string guess;
        std::cin >> guess;

        int left = a.size();
        for (unsigned i {}; i < guess.size(); ++i) {
            char ch = guess[i];
std::cout << "Checking " << ch << '\n';
            bool already_used {false};
            for (unsigned k {}; k < guesses_made.size(); ++k) {
                if (guesses_made[k] == ch) {
                    std::cout << "Already used\n";
                    already_used = true;
                }
            }
            if (already_used) {
            } else {
                guesses_made.push_back(ch);
                bool found {false};
                for (unsigned j {}; j < a.size(); ++j) {
                    if (a[j] == ch) {
                        std::cout << "MATCH\n";
                        a[j] = 'D';
                        found = true;
                        --left;
                    }
                }
                if (!found) {
                    std::cout << "No Match\n";
                    if (left) {
                        std::cout << "Counted as a miss\n";
                        ++misses;
                    } else {
                        std::cout << "No left - not counting as miss\n";
                    }
                }
            }
        }
        a.erase(std::remove(a.begin(), a.end(), 'D'), a.end());

    std::cout << "Misses: " << misses << ", not guesses: " << a.size() << '\n';
        output << "Round " << game << '\n';
        if (misses >= 7) {
            output << "You lose.\n";
        } else if (a.size() == 0) {
            output << "You win.\n";
        } else {
            output << "You chickened out.\n";
        }
    }
    std::cout << output.str();
}
