#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    int k {};
    while (std::cin >> k && k != 0) {
        int n {};
        int m {};
        std::cin >> n >>m;
        while (k--) {
            int x {};
            int y {};
            std::cin >> x >> y;
            if (x == n || y == m) {
                output << "divisa\n";
            } else if (x > n) {
                output << (y > m ? "NE" : "SE") << '\n';
            } else {
                output << (y > m ? "NO" : "SO") << '\n';
            }
        }
    }
    std::cout << output.str();
}
