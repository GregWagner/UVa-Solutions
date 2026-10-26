// 442 - Matrix Chain Multiplication
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::unordered_map<char, std::pair<int, int>> m;
    std::stack<std::pair<int, int>> s;

    int numberOfMatrices{};
    if (!(std::cin >> numberOfMatrices)) {
        return 0;
    }

    while (numberOfMatrices--) {
        char name;
        int rows, columns;
        std::cin >> name >> rows >> columns;
        m[name] = {rows, columns};
    }

    std::string expression;
    while (std::cin >> expression) {
        bool error{};
        long long total{};
        int depth{};

        while (!s.empty())
            s.pop();

        for (char c : expression) {
            if (c == '(') {
                ++depth;
            } else if (c == ')') {
                if (--depth < 0 || s.size() < 2) {
                    error = true;
                    break;
                }
                // right operand on top, left operand below it
                std::pair<int, int> b = s.top();
                s.pop();
                std::pair<int, int> a = s.top();
                s.pop();
                if (a.second != b.first) {
                    error = true;
                    break;
                }
                total += static_cast<long long>(a.first) * a.second * b.second;
                s.push({a.first, b.second});
            } else {
                auto it = m.find(c);
                if (it == m.end()) {
                    error = true;
                    break;
                }
                s.push(it->second);
            }
        }

        if (!error && (depth != 0 || s.size() != 1)) {
            error = true;
        }

        if (error) {
            output << "error\n";
        } else {
            output << total << '\n';
        }
    }

    std::cout << output.str();
}
