/*
 * Help a PhD Candiate out
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
        if (input == "P=NP") {
            output << "skipped\n";
        } else {
            int a = std::stoi(input);
            int plus = input.find('+');
            input = input.substr(plus + 1);
            int b = std::stoi(input);
            output << a + b << '\n';
        }
    }
    std::cout << output.str();
}
