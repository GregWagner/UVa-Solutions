// 245 Uncompress
#include <cctype>
#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    std::vector<std::string> words;
    char c;

    while (std::cin.get(c)) {
        unsigned char uc = static_cast<unsigned char>(c);
        if (std::isalpha(uc)) {
            std::string word;
            word.push_back(c);
            while (std::cin.peek() != EOF) {
                int peekc = std::cin.peek();
                unsigned char up = static_cast<unsigned char>(peekc);
                if (std::isalpha(up)) {
                    std::cin.get(c);
                    word.push_back(c);
                } else {
                    break;
                }
            }
            output << word;
            words.insert(words.begin(), word);
        } else if (std::isdigit(uc)) {
            int number = c - '0';
            while (std::cin.peek() != EOF) {
                int peekc = std::cin.peek();
                unsigned char up = static_cast<unsigned char>(peekc);
                if (std::isdigit(up)) {
                    std::cin.get(c);
                    number = number * 10 + (c - '0');
                } else {
                    break;
                }
            }
            if (number == 0) {
                break;
            }
            int index = number - 1;
            if (index >= 0 && index < static_cast<int>(words.size())) {
                std::string targetWord = words[index];
                output << targetWord;
                words.erase(words.begin() + index);
                words.insert(words.begin(), targetWord);
            }
        } else {
            output << c;
        }
    }

    std::cout << output.str();
}
