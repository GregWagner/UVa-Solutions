/*
 * Problem 12250 - Language Detection
 */
#include <iostream>
#include <sstream>

int main() {
    std::ostringstream output;

    int test {0};
    std::string input;
    while (std::cin >> input) {
        if (input == "#") {
            break;
        }
        output << "Case " << ++test << ": ";
        if (input == "HELLO") {
            output << "ENGLISH\n";
        } else if (input == "HOLA") {
            output << "SPANISH\n";
        } else if (input == "HALLO") {
            output << "GERMAN\n";
        } else if (input == "BONJOUR") {
            output << "FRENCH\n";
        } else if (input == "CIAO") {
            output << "ITALIAN\n";
        } else if (input == "ZDRAVSTVUJTE") {
            output << "RUSSIAN\n";
        } else {
            output << "UNKNOWN\n";
        }
    }
    std::cout << output.str();
}
