// 11220 - Decoding the Message
#include <iostream>
#include <sstream>
#include <vector>

auto decodeLine(const std::string& line) -> std::string {
    std::istringstream ss(line);
    std::string word;
    std::size_t position{1};
    std::string res;
    while (ss >> word) {
        if (word.size() >= position) {
            res.push_back(word[position - 1]);
            ++position;
        }
    }
    return res;
}

auto isBlank(const std::string& s) -> bool {
    for (char c : s) {
        if (c != ' ' && c != '\t' && c != '\r' && c != '\n') {
            return false;
        }
    }
    return true;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int testCases;
    if (!(std::cin >> testCases)) {
        return 0;
    }
    std::string line;
    std::getline(std::cin, line); // consume end of line

    for (int caseNum{1}; caseNum <= testCases; ++caseNum) {
        // skip leading blank lines
        while (std::getline(std::cin, line)) {
            if (!isBlank(line))
                break;
        }
        std::vector<std::string> decoded;
        while (!isBlank(line) && std::cin) {
            decoded.push_back(decodeLine(line));
            if (!std::getline(std::cin, line))
                break;
        }
        std::cout << "Case #" << caseNum << ":\n";
        for (const auto& s : decoded) {
            std::cout << s << "\n";
        }
        if (caseNum != testCases)
            std::cout << "\n";
    }
}
