// 457 Linear Cellular Automata
#include <iostream>
#include <sstream>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    const char symbol[4] = {' ', '.', 'x', 'W'};

    int testCases;
    std::cin >> testCases;
    bool first = true;
    while (testCases--) {
        if (!first) {
            output << '\n';
        }
        first = false;

        std::vector<char> dna(40, 0);
        std::vector<char> next(40, 0);
        std::vector<int> program(10, 0);
        dna[19] = 1;
        for (int i{}; i < 10; ++i) {
            std::cin >> program[i];
        }

        for (int day{}; day < 50; ++day) {
            for (auto&& i : dna) {
                output << symbol[static_cast<unsigned char>(i)];
            }
            output << '\n';

            for (int i{}; i < 40; ++i) {
                int left = i > 0 ? dna[i - 1] : 0;
                int right = i < 39 ? dna[i + 1] : 0;
                int sum = left + dna[i] + right;
                next[i] = static_cast<char>(program[sum]);
            }
            dna.swap(next);
        }
    }

    std::cout << output.str();
}