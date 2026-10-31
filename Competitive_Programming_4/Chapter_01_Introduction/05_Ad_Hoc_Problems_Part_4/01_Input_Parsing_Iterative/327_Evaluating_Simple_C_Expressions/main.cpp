#include <cctype>
#include <iostream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            continue;
        }
        std::cout << "Expression: " << line << "\n";

        // build expression without whitespace
        std::string expr;
        expr.reserve(line.size());
        for (char c : line) {
            if (!std::isspace(static_cast<unsigned char>(c))) {
                expr.push_back(c);
            }
        }

        int values[26];
        bool used[26] = {false};
        for (int i = 0; i < 26; ++i) {
            values[i] = i + 1;
        }

        size_t n = expr.size();
        size_t i = 0;
        bool firstOperand = true;
        char op = '+';
        int result = 0;
        bool expectingOperand = true;

        while (i < n) {
            if (expectingOperand) {
                int prefix = 0;
                if (i + 2 < n && expr[i] == expr[i + 1] &&
                    (expr[i] == '+' || expr[i] == '-') &&
                    std::islower(static_cast<unsigned char>(expr[i + 2]))) {
                    prefix = (expr[i] == '+') ? 1 : -1;
                    i += 2;
                }
                if (i >= n ||
                    !std::islower(static_cast<unsigned char>(expr[i]))) {
                    // skip invalid character
                    ++i;
                    continue;
                }
                int idx = expr[i] - 'a';
                used[idx] = true;
                if (prefix != 0)
                    values[idx] += prefix;
                int operandVal = values[idx];
                ++i; // consume variable

                int postfix = 0;
                if (i + 1 < n && expr[i] == expr[i + 1] &&
                    (expr[i] == '+' || expr[i] == '-')) {
                    postfix = (expr[i] == '+') ? 1 : -1;
                    i += 2;
                }
                if (postfix != 0)
                    values[idx] += postfix;

                if (firstOperand) {
                    result = operandVal;
                    firstOperand = false;
                } else {
                    if (op == '+')
                        result += operandVal;
                    else
                        result -= operandVal;
                }
                expectingOperand = false;
            } else {
                if (expr[i] == '+' || expr[i] == '-') {
                    op = expr[i];
                    ++i;
                    expectingOperand = true;
                } else {
                    ++i; // skip unexpected
                }
            }
        }

        std::cout << "    value = " << result << "\n";
        for (int k = 0; k < 26; ++k) {
            if (used[k]) {
                std::cout << "    " << char('a' + k) << " = " << values[k]
                          << "\n";
            }
        }
    }
}
