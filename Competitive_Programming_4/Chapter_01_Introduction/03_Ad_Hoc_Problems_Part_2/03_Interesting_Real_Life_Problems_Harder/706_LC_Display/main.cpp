/*
 * 706 - LC Display
 */
#include <iostream>
#include <string>

// Segment order: a(top) b(top-right) c(bottom-right) d(bottom)
//                e(bottom-left) f(top-left) g(middle).
const bool kSegments[10][7] = {
    {true, true, true, true, true, true, false},     // 0
    {false, true, true, false, false, false, false}, // 1
    {true, true, false, true, true, false, true},    // 2
    {true, true, true, true, false, false, true},    // 3
    {false, true, true, false, false, true, true},   // 4
    {true, false, true, true, false, true, true},    // 5
    {true, false, true, true, true, true, true},     // 6
    {true, true, true, false, false, false, false},  // 7
    {true, true, true, true, true, true, true},      // 8
    {true, true, true, true, false, true, true},     // 9
};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string output;

    int s;
    std::string n;
    while (std::cin >> s >> n && s != 0) {
        // One digit's content for row r (0 .. 2s+2), without separators.
        auto digitRow = [&](char ch, int r) -> std::string {
            const bool* seg = kSegments[ch - '0'];
            if (r == 0) // top horizontal
                return std::string(1, ' ') +
                       std::string(s, seg[0] ? '-' : ' ') + ' ';
            if (r == s + 1) // middle horizontal
                return std::string(1, ' ') +
                       std::string(s, seg[6] ? '-' : ' ') + ' ';
            if (r == 2 * s + 2) // bottom horizontal
                return std::string(1, ' ') +
                       std::string(s, seg[3] ? '-' : ' ') + ' ';
            if (r <= s) // upper verticals (f ... b)
                return std::string(1, seg[5] ? '|' : ' ') +
                       std::string(s, ' ') + (seg[1] ? '|' : ' ');
            // lower verticals (e ... c)
            return std::string(1, seg[4] ? '|' : ' ') + std::string(s, ' ') +
                   (seg[2] ? '|' : ' ');
        };

        for (int r{}; r <= 2 * s + 2; ++r) {
            std::string line;
            for (std::size_t i{}; i < n.size(); ++i) {
                if (i > 0) {
                    line += ' ';
                }
                line += digitRow(n[i], r);
            }
            output += line;
            output += '\n';
        }
        output += '\n'; // blank line after each case
    }
    std::cout << output;
}
