#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::ostringstream output;
    std::vector<int> a (3);

    int n {};
    int test_cases {1};
    std::cin >> n;
    while (n--) {
        std::cin >> a[0] >> a[1] >> a[2];
        std::sort(a.begin(), a.end());
        output << "Case " << test_cases++ << ": " << a[1] << '\n';
    }
    std::cout << output.str();
}
