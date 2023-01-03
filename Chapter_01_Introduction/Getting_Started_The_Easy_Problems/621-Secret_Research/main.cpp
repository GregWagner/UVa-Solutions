#include <iostream>
#include <sstream>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    int n {};
    std::cin >> n;
    while (n--) {
        std::string input {};
        std::cin >> input;
        const size_t size = input.size();
        if (input == "1" || input == "4" || input == "78") {
            output << "+\n";
        } else if (size >= 2 && input[size - 2] == '3' && input[size - 1] == '5') {
            output << "-\n";
        } else if (size >= 2 && input[0] == '9' && input[size - 1] == '4') {
            output << "*\n";
        } else {
            output << "?\n";
        }
    }
    std::cout << output.str();
}
