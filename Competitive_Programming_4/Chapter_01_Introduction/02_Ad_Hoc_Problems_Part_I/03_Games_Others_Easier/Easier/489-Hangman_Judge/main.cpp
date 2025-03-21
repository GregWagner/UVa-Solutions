/*
 * Problem 389 - Hangman Judge
 */
#include <iostream>
#include <sstream>

void addCorrectLetter(char c, std::string &correct) {
    for (size_t i {}; i < correct.size(); ++i) {
        if (c == correct[i]) {
            return;
        }
    }
    correct += c;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int round;
    while (std::cin >> round && round != -1) {
        std::string wrongLetters {};
        std::string correctLetters {};
        std::string word;
        std::string guess;
        std::cin >> word >> guess;

        for (size_t i {}; i < guess.size(); ++i) {
            bool match {};
            for (size_t j {}; j < word.size(); ++j) {
                if (guess[i] == word[j] && wrongLetters.size() < 7) {
                    addCorrectLetter(word[j], correctLetters);
                    match  = true;
                    word[j] = '_';
                }
            }
            if (!match) {
                bool found {};
                for (size_t k {}; k < wrongLetters.size(); ++k) {
                    if (wrongLetters[k] == guess[i]) {
                        found = true;
                    }
                }
                for (size_t k {}; k < correctLetters.size(); ++k) {
                    if (correctLetters[k] == guess[i]) {
                        found = true;
                    }
                }
                if (!found) {
                    wrongLetters += guess[i];
                }
            }
        }
        bool won {true};
        for (size_t i {}; i < word.size(); ++i) {
            if (word[i] != '_') {
                won = false;
                break;
            }
        }
        output << "Round " << round << '\n';
        if (wrongLetters.size() < 7 && !won) {
            output << "You chickened out.\n";
        } else if (won) {
            output << "You win.\n";
        } else {
            output << "You lose.\n";
        }
    }
    std::cout << output.str();
}
