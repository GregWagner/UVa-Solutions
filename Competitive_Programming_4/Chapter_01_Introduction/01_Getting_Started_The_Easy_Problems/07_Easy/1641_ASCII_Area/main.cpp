#include <iostream>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);

    int height, width;
    while (std::cin >> height >> width) {

        int area {};
        for (int i {}; i < height; ++i) {
            std::string line;
            std::cin >> line;
            bool open {};
            for (const auto c : line) {
                if (open) {
                    if (c == '.') {
                        area += 2;
                    } else {
                        ++area;
                        open = false;
                    }
                } else {
                    if (c != '.') {
                        ++area;
                        open = true;
                    }
                }
            }
        }
        std::cout << area / 2 << '\n';
    }
}
