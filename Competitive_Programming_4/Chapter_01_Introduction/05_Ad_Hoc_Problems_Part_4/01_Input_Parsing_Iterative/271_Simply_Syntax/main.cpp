// 271 Simply Syntax
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string input;
    while (std::cin >> input) {
        int count = 0;
        bool valid = true;
        for (int i = (int)input.size() - 1; i >= 0; --i) {
            char c = input[i];
            if (c >= 'p' && c <= 'z') {
                ++count;
            } else if (c == 'N') {
                if (count == 0) {
                    valid = false;
                }
            } else if (c == 'C' || c == 'D' || c == 'E' || c == 'I') {
                if (count < 2) {
                    valid = false;
                } else {
                    --count;
                }
            } else {
                valid = false;
            }
        }

        if (valid && count == 1) {
            output << "YES\n";
        } else {
            output << "NO\n";
        }
    }
    std::cout << output.str();
}
