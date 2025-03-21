/*
 * Problem 11956 - Brainfck
 */
#include <iostream>
#include <sstream>
#include <iomanip>

int main() {
    signed short a[100];
    std::ios::sync_with_stdio(false);
    std::ostringstream output;

    int testCases;
    int test {};
    std::cin >> testCases;
    std::string instructions;
    getline(std::cin, instructions);
    while (testCases--) {
        for (int i {}; i < 100; ++i) {
            a[i] = 0;
        }

        getline(std::cin, instructions);
        int ptr {0};
        for (unsigned i {}; i < instructions.size(); ++i) {
            if (instructions[i] == '>') {			// increment point
                ptr = (ptr + 1) % 100;
            } else if (instructions[i] == '<') {	// decrement point
                ptr = (ptr + 100 - 1) % 100;
            } else if (instructions[i] == '+') {	// increment byte
                ++a[ptr];
            } else if (instructions[i] == '-') {	// decrement byte
                --a[ptr];
            }
        }

        output << "Case " << std::dec << ++test << ":";
        for (int i {}; i < 100; ++i) {
            output << ' ' << std::setfill('0') << std::setw(2) << std::hex
                << std::uppercase << (a[i] & 0xff);
        }
        output << '\n';
    }
    std::cout << output.str();
}
