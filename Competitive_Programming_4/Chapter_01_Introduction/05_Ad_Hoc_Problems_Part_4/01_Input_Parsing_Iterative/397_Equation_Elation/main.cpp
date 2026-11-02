#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string line;
    bool isFirstCase{true};
    while (std::getline(std::cin, line)) {
        if (line.find_first_not_of(" \t\r\n") == std::string::npos) {
            continue;
        }

        std::stringstream ss(line);
        std::vector<long long> operands;
        std::vector<char> ops;
        std::string varName;

        long long num;
        char op;

        while (ss >> num) {
            operands.push_back(num);
            if (ss >> op) {
                if (op == '=') {
                    ss >> varName;
                    break;
                } else {
                    ops.push_back(op);
                }
            }
        }

        if (operands.empty() || varName.empty()) {
            continue;
        }

        if (!isFirstCase) {
            output << "\n";
        }

        auto printState = [&]() {
            output << operands[0];
            for (size_t i = 0; i < ops.size(); ++i) {
                output << " " << ops[i] << " " << operands[i + 1];
            }
            output << " = " << varName << "\n";
        };

        printState();

        while (!ops.empty()) {
            int targetIdx{-1};

            // Look for highest priority (* or /) from left to right
            for (size_t i{}; i < ops.size(); ++i) {
                if (ops[i] == '*' || ops[i] == '/') {
                    targetIdx = i;
                    break;
                }
            }

            // If no * or / is found, take the first + or - from left to right
            if (targetIdx == -1) {
                targetIdx = 0;
            }

            // Evaluate the operation at targetIdx
            long long a{operands[targetIdx]};
            long long b{operands[targetIdx + 1]};
            long long res{};

            if (ops[targetIdx] == '*') {
                res = a * b;
            } else if (ops[targetIdx] == '/') {
                res = a / b;
            } else if (ops[targetIdx] == '+') {
                res = a + b;
            } else if (ops[targetIdx] == '-') {
                res = a - b;
            }

            operands[targetIdx] = res;
            operands.erase(operands.begin() + targetIdx + 1);
            ops.erase(ops.begin() + targetIdx);

            printState();
        }
        isFirstCase = false;
    }
    std::cout << output.str();
}
