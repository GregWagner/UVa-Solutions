/*
 * 621 Secret Research
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int testCases {};
    std::cin >> testCases;
    while (testCases-- != 0) {
        std::string input;
        std::cin >> input;
        const size_t size = input.size();
        if (input == "1" || input == "4" || input == "78") {
            output << "+\n";
        } else if (size >= 2 && input[size - 2] == '3' && input[size - 1] == '5') {
            output << "-\n";
        } else if (size >= 3 && input[0] == '1' && input[1] == '9' && input[2] == '0') {
            output << "?\n";
        } else if (size > 2 && input[0] == '9' && input[size - 1] == '4') {
            output << "*\n";
        } else {
            output << "?\n";
        }
    }
    std::cout << output.str();
}
