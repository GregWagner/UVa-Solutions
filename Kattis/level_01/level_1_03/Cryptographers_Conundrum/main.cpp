/*
 * Cryptographer's Conundrum
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string input;
    std::cin >> input;

    int count {};
    const std::string results = "PER";
    for (size_t i {}; i < input.length(); ++i) {
        if (input[i] != results[i % 3]) {
            ++count;
        }
    }
    std::cout << count << '\n';
}
