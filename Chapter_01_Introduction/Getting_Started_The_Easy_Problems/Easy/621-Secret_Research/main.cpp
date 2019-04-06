/*
 * Problem 621 - Secret Research
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        std::string input;
        std::cin >> input;
        int size = input.size() - 1;
        if (input == "1" || input == "4" || input == "78") {
            output << "+\n";
        } else if (input[size - 1] == '3' && input[size] == '5') {
            output << "-\n";
        } else if (input[0] == '9' && input[size] == '4') {
            output << "*\n";
        } else {
            output << "?\n";
        }
    }
    std::cout << output.str();
}
