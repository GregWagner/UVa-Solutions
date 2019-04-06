/*
 * Hissing Microphone
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string input;
    std::cin >> input;
    std::cout << (input.find("ss") == std::string::npos ? "no " : "")
        << "hiss\n";
}
