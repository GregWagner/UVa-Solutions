// 486 English Number Translator
#include <iostream>
#include <sstream>
#include <unordered_map>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::unordered_map<std::string, int> wordToValue;
    wordToValue["zero"] = 0;
    wordToValue["one"] = 1;
    wordToValue["two"] = 2;
    wordToValue["three"] = 3;
    wordToValue["four"] = 4;
    wordToValue["five"] = 5;
    wordToValue["six"] = 6;
    wordToValue["seven"] = 7;
    wordToValue["eight"] = 8;
    wordToValue["nine"] = 9;
    wordToValue["ten"] = 10;
    wordToValue["eleven"] = 11;
    wordToValue["twelve"] = 12;
    wordToValue["thirteen"] = 13;
    wordToValue["fourteen"] = 14;
    wordToValue["fifteen"] = 15;
    wordToValue["sixteen"] = 16;
    wordToValue["seventeen"] = 17;
    wordToValue["eighteen"] = 18;
    wordToValue["nineteen"] = 19;
    wordToValue["twenty"] = 20;
    wordToValue["thirty"] = 30;
    wordToValue["forty"] = 40;
    wordToValue["fifty"] = 50;
    wordToValue["sixty"] = 60;
    wordToValue["seventy"] = 70;
    wordToValue["eighty"] = 80;
    wordToValue["ninety"] = 90;

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        std::string word;

        bool isNegative{};
        long long total{};
        long long currentChunk{};

        while (ss >> word) {
            if (word == "negative") {
                isNegative = true;
            } else if (word == "million") {
                total += currentChunk * 1000000;
                currentChunk = 0;
            } else if (word == "thousand") {
                total += currentChunk * 1000;
                currentChunk = 0;
            } else if (word == "hundred") {
                currentChunk *= 100;
            } else {
                currentChunk += wordToValue[word];
            }
        }

        total += currentChunk;

        if (isNegative) {
            total = -total;
        }
        output << total << '\n';
    }
    std::cout << output.str();
}
