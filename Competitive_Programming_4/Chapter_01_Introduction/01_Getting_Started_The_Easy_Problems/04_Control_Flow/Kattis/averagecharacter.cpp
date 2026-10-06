#include <iostream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::string s;
    std::getline(std::cin, s);
    int sum = 0;
    for (char c : s) {  
        sum += int(c);
    }
    std::cout << static_cast<char>(sum / s.length()) << '\n'; 
}