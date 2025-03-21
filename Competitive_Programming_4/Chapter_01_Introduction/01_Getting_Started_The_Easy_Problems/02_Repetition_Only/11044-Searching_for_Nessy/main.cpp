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
        int m {};
        std::cin >> n >> m;

        output << (n / 3) * (m / 3) << '\n';
    }

    std::cout << output.str();
}
