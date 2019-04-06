/*
 * Kemija
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    std::string input;
    std::getline(std::cin, input);
    for (size_t i {}; i < input.length(); ++i) {
        char c = input[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            i += 2;
        } 
        output << c;
    }
    std::cout << output.str() << '\n';
}
