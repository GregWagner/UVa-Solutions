#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string braille[10][3] = {
    {".*", "**", ".."}, // 0
    {"*.", "..", ".."}, // 1
    {"*.", "*.", ".."}, // 2
    {"**", "..", ".."}, // 3
    {"**", ".*", ".."}, // 4
    {"*.", ".*", ".."}, // 5
    {"**", "*.", ".."}, // 6
    {"**", "**", ".."}, // 7
    {"*.", "**", ".."}, // 8
    {".*", "*.", ".."}  // 9
};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int n;
    while (std::cin >> n && n != 0) {
        char type;
        std::cin >> type;

        if (type == 'S') {
            std::string s;
            std::cin >> s;

            for (int i{}; i < n; ++i) {
                output << braille[s[i] - '0'][0];
                if (i + 1 < n) {
                    output << " ";
                }
            }
            output << "\n";

            for (int i{}; i < n; ++i) {
                output << braille[s[i] - '0'][1];
                if (i + 1 < n) {
                    output << " ";
                }
            }
            output << "\n";

            for (int i{}; i < n; ++i) {
                output << braille[s[i] - '0'][2];
                if (i + 1 < n) {
                    output << " ";
                }
            }
            output << "\n";

        } else if (type == 'B') {
            std::vector<std::string> b(3);
            std::string dummy;
            std::getline(std::cin, dummy); // consume rest of line after type
            for (int i{}; i < 3; ++i) {
                std::getline(std::cin, b[i]);
            }

            for (int i{}; i < n; ++i) {
                std::string block[3];
                for (int r{}; r < 3; ++r) {
                    block[r] = b[r].substr(i * 3, 2);
                }

                // Match with known digits
                for (int d{}; d <= 9; ++d) {
                    if (braille[d][0] == block[0] &&
                        braille[d][1] == block[1] &&
                        braille[d][2] == block[2]) {
                        output << d;
                        break;
                    }
                }
            }
            output << "\n";
        }
    }
    std::cout << output.str();
}