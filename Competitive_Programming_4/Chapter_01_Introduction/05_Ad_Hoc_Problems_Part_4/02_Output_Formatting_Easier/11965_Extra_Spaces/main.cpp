#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int testCases;
    if (!(std::cin >> testCases)) return 0;
    for (int caseNum = 1; caseNum <= testCases; ++caseNum) {
        int numberOfLines;
        std::cin >> numberOfLines;
        std::string dummy;
        std::getline(std::cin, dummy);
        std::cout << "Case " << caseNum << ":\n";
        for (int i = 0; i < numberOfLines; ++i) {
            std::string line;
            std::getline(std::cin, line);
            std::string normalized;
            normalized.reserve(line.size());
            for (char c : line) {
                if (c == ' ') {
                    if (normalized.empty() || normalized.back() != ' ') {
                        normalized.push_back(' ');
                    }
                } else {
                    normalized.push_back(c);
                }
            }
            std::cout << normalized << '\n';
        }
        if (caseNum != testCases) {
            std::cout << '\n';
        }
    }
}
