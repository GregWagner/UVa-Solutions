#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

// Helper to convert a Roman numeral character to its value
auto charToInt(char c) -> int {
    if (c == 'I')
        return 1;
    if (c == 'V')
        return 5;
    if (c == 'X')
        return 10;
    if (c == 'L')
        return 50;
    if (c == 'C')
        return 100;
    if (c == 'D')
        return 500;
    if (c == 'M')
        return 1000;
    return 0;
}

auto romanToInt(const std::string& s) -> int {
    int total{};
    int n = s.length();
    for (int i{}; i < n; ++i) {
        int currentVal{charToInt(s[i])};
        if (i + 1 < n && currentVal < charToInt(s[i + 1])) {
            total -= currentVal;
        } else {
            total += currentVal;
        }
    }
    return total;
}

std::string op1, op2, res;
std::vector<char> uniqueChars;
std::set<char> leadingChars;
int letterToDigit[256];
bool digitUsed[10];
int solutionCount = 0;

auto parseEquation(const std::string& line) -> void {
    size_t plusPos{line.find('+')};
    size_t eqPos{line.find('=')};
    op1 = line.substr(0, plusPos);
    op2 = line.substr(plusPos + 1, eqPos - plusPos - 1);
    res = line.substr(eqPos + 1);

    leadingChars.insert(op1[0]);
    leadingChars.insert(op2[0]);
    leadingChars.insert(res[0]);

    std::set<char> chars;
    for (char c : op1)
        chars.insert(c);
    for (char c : op2)
        chars.insert(c);
    for (char c : res)
        chars.insert(c);

    uniqueChars.assign(chars.begin(), chars.end());
}

auto evaluateWord(const std::string& w) -> long long {
    long long val{};
    for (char c : w) {
        val = val * 10 + letterToDigit[c];
    }
    return val;
}

auto dfs(int index) -> void {
    if (solutionCount > 1) {
        return; // Prune if already ambiguous
    }

    if (index == uniqueChars.size()) {
        long long v1{evaluateWord(op1)};
        long long v2{evaluateWord(op2)};
        long long v3{evaluateWord(res)};
        if (v1 + v2 == v3) {
            solutionCount++;
        }
        return;
    }

    char currentChar{uniqueChars[index]};
    for (int d{}; d <= 9; ++d) {
        if (!digitUsed[d]) {
            if (d == 0 && leadingChars.count(currentChar)) {
                continue;
            }

            digitUsed[d] = true;
            letterToDigit[currentChar] = d;
            dfs(index + 1);
            digitUsed[d] = false;
        }
    }
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string line;
    while (std::cin >> line && line != "#") {
        leadingChars.clear();
        parseEquation(line);

        // check standard Roman evaluation
        bool isCorrect = (romanToInt(op1) + romanToInt(op2) == romanToInt(res));
        if (isCorrect) {
            output << "Correct ";
        } else {
            output << "Incorrect ";
        }

        // check cryptarithm ambiguity/validity
        solutionCount = 0;
        std::fill(digitUsed, digitUsed + 10, false);
        dfs(0);

        if (solutionCount == 0) {
            output << "impossible\n";
        } else if (solutionCount == 1) {
            output << "valid\n";
        } else {
            output << "ambiguous\n";
        }
    }
    std::cout << output.str();
}