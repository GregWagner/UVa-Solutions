/*
 * Autori
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;

    std::string input;
    std::cin >> input;
    
    size_t index = input.find('-');
    output << input[0];
    while (index != std::string::npos) {
        output << input[index + 1];
        index = input.find('-', index + 1);
    }
    std::cout << output.str() << '\n';
}
