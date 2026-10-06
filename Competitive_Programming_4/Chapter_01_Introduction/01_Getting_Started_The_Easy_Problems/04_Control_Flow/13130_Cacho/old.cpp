#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);

    std::ostringstream output;
    int testCases {};
    std::cin >> testCases;
    while (testCases--) {
        bool valid {true};
        int current {};
        std::cin >> current;
        for (int i {1}; i < 5; ++i) {
            int n;
            std::cin >> n;
            if (++current != n) {
                valid = false;
            }
        }
        output << (valid ? "Y" : "N") << '\n';
    }
    std::cout << output.str();
}
