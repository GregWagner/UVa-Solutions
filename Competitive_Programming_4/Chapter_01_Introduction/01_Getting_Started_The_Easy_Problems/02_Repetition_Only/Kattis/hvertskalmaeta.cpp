#include <iostream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::string s;
    std::getline(std::cin, s);
    if (s == "Akureyri" || s == "Fjardabyggd" || s == "Mulathing") {
        std::cout << "Akureyri\n";
    } else {
        std::cout << "Reykjavik\n";
    }
}