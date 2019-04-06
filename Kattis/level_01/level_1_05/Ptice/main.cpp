/*
 * Ptice
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;

    int adrianCount {};
    const std::string adrian = "ABC";
    const size_t adrianLength = adrian.length();
    int brunoCount {};
    const std::string bruno = "BABC";
    const size_t brunoLength = bruno.length();
    int goranCount {};
    const std::string goran = "CCAABB";
    const size_t goranLength = goran.length();

    int numberOfQuestions;
    std::cin >> numberOfQuestions;
    std::string input;
    std::cin >> input;

    for (size_t i {}; i < input.length(); ++i) {
        if (input[i] == adrian[i % adrianLength]) {
            ++adrianCount;
        }
        if (input[i] == bruno[i % brunoLength]) {
            ++brunoCount;
        }
        if (input[i] == goran[i % goranLength]) {
            ++goranCount;
        }
    }
    int max = std::max(adrianCount, std::max(brunoCount, goranCount));
    output << max << '\n';
    if (adrianCount == max) {
        output << "Adrian\n";
    }
    if (brunoCount == max) {
        output << "Bruno\n";
    }
    if (goranCount == max) {
        output << "Goran\n";
    }
    std::cout << output.str();
}
