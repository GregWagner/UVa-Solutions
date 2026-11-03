#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

static const int mapping[36] = {1,  3,  5,  10, 14, 19, 22, 29, 33, 8,  11, 15,
                                18, 23, 26, 28, 31, 35, 2,  6,  13, 16, 21, 25,
                                30, 32, 34, 0,  4,  7,  9,  12, 17, 20, 24, 27};

std::string decode(const std::string& encrypted) {
    std::string reversed;
    for (size_t i{}; i < encrypted.size(); i += 36) {
        std::string group{encrypted.substr(i, 36)};
        std::string chunk;
        chunk.reserve(group.size());
        for (size_t j{}; j < group.size(); ++j) {
            chunk.push_back(group[mapping[j]]);
        }
        reversed += chunk;
    }
    std::string plain{reversed};
    std::reverse(plain.begin(), plain.end());
    while (!plain.empty() && plain.back() == '#') {
        plain.pop_back();
    }
    return plain;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(std::cin, line)) {
        lines.push_back(line);
    }
    while (lines.size() > 1 && lines.back().empty()) {
        lines.pop_back();
    }

    std::string out;
    for (const auto& l : lines) {
        out += decode(l);
        out += '\n';
    }
    std::cout << out;
}
