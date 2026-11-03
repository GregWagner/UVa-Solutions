#include <cctype>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

struct Node {
    std::string op1;
    char op;
    std::string op2;
};

std::map<std::string, Node> exprMap;

auto isNumber(const std::string& s) -> bool {
    if (s.empty()) {
        return false;
    }
    for (char c : s) {
        if (!std::isdigit(static_cast<unsigned char>(c))) {
            return false;
        }
    }
    return true;
}

char topOp(const std::string& s) {
    if (isNumber(s)) {
        return '\0';
    }
    auto it = exprMap.find(s);
    if (it == exprMap.end()) {
        return '\0';
    }
    return it->second.op;
}

std::string expand(const std::string& var) {
    auto it = exprMap.find(var);
    if (it == exprMap.end()) {
        return var;
    }

    const Node& node = it->second;
    std::string left = isNumber(node.op1) ? node.op1 : expand(node.op1);
    std::string right = isNumber(node.op2) ? node.op2 : expand(node.op2);

    char leftOp = topOp(node.op1);
    char rightOp = topOp(node.op2);

    if (node.op == '+') {
        if (rightOp == '\0' || rightOp == '*') {
            return left + "+" + right;
        }
        return left + "+(" + right + ")";
    }

    // '*'
    bool leftNeeds = (leftOp == '+');
    bool rightNeeds = (rightOp != '\0');

    if (leftNeeds && rightNeeds) {
        return "(" + left + ")*(" + right + ")";
    }
    if (leftNeeds) {
        return "(" + left + ")*" + right;
    }
    if (!rightNeeds) {
        return left + "*" + right;
    }
    return left + "*(" + right + ")";
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    for (int caseNum{1}; caseNum <= testCases; ++caseNum) {
        int n;
        std::cin >> n;
        exprMap.clear();

        std::string lastVar{};
        for (int i{}; i < n; ++i) {
            std::string var, eq, op1, op, op2;
            std::cin >> var >> eq >> op1 >> op >> op2;
            exprMap[var] = {op1, op[0], op2};
            lastVar = var;
        }

        std::string result = expand(lastVar);
        output << "Expression #" << caseNum << ": " << result << "\n";
    }
    std::cout << output.str();
}