// 10878 Decode the tape
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string tape;
    std::getline(std::cin, tape);
    while (std::getline(std::cin, tape)) {
        if (tape[0] != '|') {
            continue;
        }
        int bit{128};
        int accumulator{};
        for (auto c : tape) {
            if (c == 'o' || c == 'O') {
                accumulator += bit;
                bit >>= 1;
            } else if (c == ' ') {
                bit >>= 1;
            }
        }
        output << static_cast<char>(accumulator);
    }
    std::cout << output.str();
}
