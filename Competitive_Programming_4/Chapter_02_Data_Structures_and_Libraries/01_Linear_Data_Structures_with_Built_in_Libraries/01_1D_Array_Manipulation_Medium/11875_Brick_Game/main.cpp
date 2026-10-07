#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::ostringstream output;
    std::vector<int> a(10);

    int testCases{};
    std::cin >> testCases;
    int test{1};
    while (testCases--) {
        int teamSize{};
        std::cin >> teamSize;
        for (int i{}; i < teamSize; ++i) {
            std::cin >> a[i];
        }
        std::sort(a.begin(), a.begin() + teamSize);
        int answer = a[teamSize / 2];
        output << "Case " << test++ << ": " << answer << '\n';
    }
    std::cout << output.str();
}
