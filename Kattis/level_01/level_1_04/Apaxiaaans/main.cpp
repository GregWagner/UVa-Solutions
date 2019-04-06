/*
 * Apaxiaaaaaaaans
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    std::string input;
    std::cin >> input;
    char previous = ' ';
    for (size_t i {}; i < input.length(); ++i) {
        while (input[i] == previous) {
            ++i;
        }
        previous = input[i];
        output << input[i];
    }
    std::cout << output.str() << '\n';
}
