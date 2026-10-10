/*
 * 10082 WERTYU
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string map = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    std::string line;
    while (std::getline(std::cin, line)) {
        for (char c : line) {
            if (c == ' ') {
                output << ' ';
            } else {
                auto index = map.find(c);
                output << map[index - 1];
            }
        }
        output << '\n';
    }
    std::cout << output.str();
}
