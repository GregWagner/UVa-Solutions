/*
 * DRM Messages
 */
#include <iostream>

int calculate(const std::string &s) {
    int count {};
    for (auto c : s) {
        count += c - 'A';
    }
    return count;
}

void rotate(std::string &s, int count) {
    for (size_t i {}; i < s.length(); ++i) {
        s[i] = ('A' + (s[i] - 'A' + count) % 26);
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::string input;
    std::cin >> input;

    // Divide
    std::string first = input.substr(0, input.size() / 2);
    std::string second = input.substr(input.size() / 2);

    // Rotate
    int firstCount = calculate(first);
    int secondCount = calculate(second);
    rotate(first, firstCount);
    rotate(second, secondCount);

    // Merge
    for (size_t i {}; i < first.length(); ++i) {
        first[i] = 'A' + ((first[i] - 'A') + (second[i] - 'A')) % 26; 
    }
    std::cout << first  << '\n';
}
