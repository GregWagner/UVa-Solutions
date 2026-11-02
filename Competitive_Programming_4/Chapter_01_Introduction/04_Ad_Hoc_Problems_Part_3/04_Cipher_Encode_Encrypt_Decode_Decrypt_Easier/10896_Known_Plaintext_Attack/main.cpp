#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

auto decrypt(const std::string& ciphertext, int k) -> std::string {
    std::string decrypted{};
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char base{islower(c) ? 'a' : 'A'};
            char decryptedChar = (c - base - k + 26) % 26 + base;
            decrypted += decryptedChar;
        } else {
            decrypted += c; // Keep spaces or punctuation as is
        }
    }
    return decrypted;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    if (std::cin >> testCases) {
        std::string dummy;
        std::getline(std::cin, dummy); // Consume the rest of the first line
        while (testCases--) {
            std::string ciphertext, word;
            std::getline(std::cin, ciphertext);
            std::getline(std::cin, word);

            std::vector<int> validKeys;

            // Try all 26 possible Caesar cipher shift keys
            for (int k{}; k < 26; ++k) {
                std::string decryptedText = decrypt(ciphertext, k);

                std::stringstream ss(decryptedText);
                std::string token;
                bool found{};

                // Check each word in the decrypted text
                while (ss >> token) {
                    if (token == word) {
                        found = true;
                        break;
                    }
                }

                if (found) {
                    validKeys.push_back(k);
                }
            }

            // Sort and print all valid keys found
            sort(validKeys.begin(), validKeys.end());
            for (size_t i{}; i < validKeys.size(); ++i) {
                output << char('a' + validKeys[i]);
            }
            output << "\n";
        }
    }
    std::cout << output.str();
}
