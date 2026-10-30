// 865 - Substitution Cypher
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    if (!(std::cin >> T)) return 0;
    std::string line;
    std::getline(std::cin, line); // consume end of line after T

    for (int tc = 0; tc < T; ++tc) {
        std::string plaintext, substitution;
        // skip blank lines before plaintext
        do {
            if (!std::getline(std::cin, plaintext)) plaintext.clear();
        } while (plaintext.empty() && !std::cin.eof());

        std::getline(std::cin, substitution);

        // build map
        char mapTable[256];
        for (int i = 0; i < 256; ++i) mapTable[i] = static_cast<char>(i);
        size_t n = std::min(plaintext.size(), substitution.size());
        for (size_t i = 0; i < n; ++i) {
            mapTable[static_cast<unsigned char>(plaintext[i])] = substitution[i];
        }

        // read text lines until blank line or EOF
        std::vector<std::string> texts;
        while (std::getline(std::cin, line)) {
            if (line.empty()) break;
            texts.push_back(line);
        }

        // output
        if (tc > 0) std::cout << '\n';
        std::cout << substitution << '\n' << plaintext << '\n';
        for (const auto& txt : texts) {
            std::string out;
            out.reserve(txt.size());
            for (unsigned char c : txt) out.push_back(mapTable[c]);
            std::cout << out << '\n';
        }
    }
    return 0;
}
