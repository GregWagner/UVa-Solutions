#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::ostringstream output;
    int n {};
    std::cin >> n;
    while (n--) {
        bool valid {true};
        int previous {};
        std::cin >> previous;
        for (int i {1}; i < 5; ++i) {
            int current {};
            std::cin >> current;
            if (current != previous + 1) {
                valid = false;
            }
            previous = current;
        }
        output << (valid ? "Y" : "N") << '\n';
    }
    std::cout << output.str();
}
