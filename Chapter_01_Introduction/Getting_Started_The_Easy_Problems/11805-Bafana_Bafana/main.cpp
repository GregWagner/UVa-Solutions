#include <iostream>
#include <sstream>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;
    int test { 1 };
    int testCases {};
    std::cin >> testCases;
    while (testCases--) {
        int n, k, p;
        std::cin >> n >> k >> p;
        int lastPlayer = (k + p) % n;
        output << "Case " << test++ << ": "
               << (lastPlayer == 0 ? n : lastPlayer) << '\n';
    }
    std::cout << output.str();
}
