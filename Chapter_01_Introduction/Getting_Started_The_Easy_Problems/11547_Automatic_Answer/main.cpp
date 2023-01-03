#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ostringstream output;
    int test_cases {};
    std::cin >> test_cases;
    while (test_cases--) {
        int n {};
        std::cin >> n;
        int64_t answer = (((n * 63) + 7492) * 5) - 498;
        output << std::abs(answer % 100) / 10 << '\n';
    }

    std::cout << output.str();
}
