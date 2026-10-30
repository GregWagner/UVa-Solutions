#include <iostream>
#include <sstream>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int testCases;
    std::cin >> testCases;
    for (int test{1}; test <= testCases; ++test) {
        int numberOfPhones;
        std::cin >> numberOfPhones;

        std::vector<std::string> numbers(numberOfPhones);
        for (int i{}; i < numberOfPhones; ++i) {
            std::cin >> numbers[i];
        }
        std::string targetPhone;
        std::cin >> targetPhone;

        output << "Case " << test << ":\n";
        for (int i{}; i < numberOfPhones; ++i) {
            if (numbers[i].size() != targetPhone.size()) {
                continue;
            }
            int countOfDiffs{};
            for (size_t j{}; j < targetPhone.size(); ++j) {
                if (numbers[i][j] != targetPhone[j]) {
                    ++countOfDiffs;
                }
            }
            if (countOfDiffs <= 1) {
                output << numbers[i] << '\n';
            }
        }
    }
    std::cout << output.str();
}
