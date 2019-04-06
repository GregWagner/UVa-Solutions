/*
 * IsItHalloween.com
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string input;
    std::getline(std::cin, input);
    if (input == "OCT 31" || input == "DEC 25") {
        std::cout << "yup\n";
    } else {
        std::cout << "nope\n";
    }
}
