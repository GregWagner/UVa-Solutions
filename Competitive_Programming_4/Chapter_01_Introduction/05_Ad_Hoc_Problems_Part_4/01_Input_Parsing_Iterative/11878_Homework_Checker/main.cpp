// 11878 Homework Checker
#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b;
    char op;
    std::string answer;

    int correct{};
    char skip;
    while (std::cin >> a) {
        std::cin >> op >> b >> skip >> answer;
        if (answer == "?") {
            continue;
        }
        int result{};
        if (op == '+') {
            result = a + b;
        } else if (op == '-') {
            result = a - b;
        }
        if (result == stoi(answer)) {
            ++correct;
        }
    }
    std::cout << correct << '\n';
}
