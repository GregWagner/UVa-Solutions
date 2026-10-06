#include <iostream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::string s = "Hipp hipp hurra!\n";
    for (int i{}; i < 20 ; ++i) {
        std::cout << s;
    } 
}