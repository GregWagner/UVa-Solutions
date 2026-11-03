#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static const char* baseLines[5] = {
    "*****..***..*...*.*****...*...*.*****.*****.***...*****.*...*",
    "*.....*...*.*...*.*.......*...*.*...*...*...*..*..*...*..*.*.",
    "*****.*****.*...*.***.....*****.*****...*...*...*.*...*...*..",
    "....*.*...*..*.*..*.......*...*.*.*.....*...*..*..*...*...*..",
    "*****.*...*...*...*****...*...*.*..**.*****.***...*****...*.."};

// Character start columns in baseLines for "SAVEHRIDOY"
static const int charStart[10] = {0, 6, 12, 18, 26, 32, 38, 44, 50, 56};

auto getCharBlock(int idx) -> std::vector<std::string> {
    std::vector<std::string> block(5);
    for (int r{}; r < 5; ++r) {
        block[r] = std::string(baseLines[r] + charStart[idx], 5);
    }
    return block;
}

auto printScaledChar(std::ostringstream& out,
                     const std::vector<std::string>& blk, int scale) -> void {
    for (int r{}; r < 5; ++r) {
        std::string row;
        for (char ch : blk[r]) {
            row.append(scale, ch);
        }
        for (int k = 0; k < scale; ++k) {
            out << row << "\n";
        }
    }
}

auto printDots(std::ostringstream& out, int count, int width) -> void {
    std::string line(width, '.');
    for (int i{}; i < count; ++i) {
        out << line << "\n";
    }
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int n;
    while (std::cin >> n && n != 0) {
        if (n > 0) {
            int scale = n;
            for (int r{}; r < 5; ++r) {
                std::string row;
                for (char ch : std::string(baseLines[r])) {
                    row.append(scale, ch);
                }
                for (int k{}; k < scale; ++k) {
                    output << row << "\n";
                }
            }
        } else {
            int L = -n;
            int charWidth = 5 * L;
            // First word: SAVE (indices 0-3)
            for (int wi{}; wi < 2; ++wi) {
                int startIdx = (wi == 0) ? 0 : 4;
                int endIdx = (wi == 0) ? 4 : 10;
                for (int ci = startIdx; ci < endIdx; ++ci) {
                    auto blk = getCharBlock(ci);
                    printScaledChar(output, blk, L);
                    if (ci + 1 < endIdx) {
                        printDots(output, L, charWidth);
                    }
                }
                if (wi == 0) {
                    printDots(output, 3 * L, charWidth);
                }
            }
        }
        output << "\n\n";
    }
    std::cout << output.str();
}