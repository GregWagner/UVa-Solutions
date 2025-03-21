/*
 * Problem 104324 - Love Calculator
 */
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>

int calculate(std::string s) {
    int sum {};
    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') {
            sum += c - 'a' + 1;
        }
    }
    return sum;
}

int sum(int a) {
    int answer {};
    while (a > 0) {
        answer += a % 10;
        a /= 10;
    }
    return answer;
}

int convert(int a) {
    while (a >= 10) {
        a = sum(a);
    }
    return a;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    output << std::setprecision(2);
    std::string first, second;
    while (std::getline(std::cin, first)) {
        std::getline(std::cin, second);
        std::transform(first.begin(), first.end(), first.begin(), ::tolower);
        std::transform(second.begin(), second.end(), second.begin(), ::tolower);
        int a = calculate(first);
        int b = calculate(second);

        a = convert(a);
        b = convert(b);

        if (a == 0 && b == 0) {
            output << '\n';
        } else {
            double ratio = 100 * 
                static_cast<double>(std::min(a, b)) / std::max(a, b);
            output << std::fixed << (ratio > 100 ? 100 : ratio) << " %\n";
        }
    }
    std::cout << output.str();
}
