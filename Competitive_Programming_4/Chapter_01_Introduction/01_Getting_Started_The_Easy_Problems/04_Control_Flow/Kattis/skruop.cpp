#include <iostream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    int volume{ 7 };
    std::cin.ignore(); // Ignore the newline character after reading n
    while (n--) {
        std::string command;
        std::getline(std::cin, command);
        if (command == "Skru op!" && volume < 10) {
            ++volume;
        } else if (command == "Skru ned!" && volume > 0) {
            --volume;
        }
    }
    std::cout << volume << '\n';
}