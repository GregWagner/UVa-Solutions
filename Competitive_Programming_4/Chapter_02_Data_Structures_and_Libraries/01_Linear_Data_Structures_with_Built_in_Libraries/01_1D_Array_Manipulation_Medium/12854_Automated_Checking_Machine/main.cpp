#include <iostream>
#include <sstream>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    std::vector<int> A(5, 0);
    std::vector<int> B(5, 0);

    while (std::cin >> A[0] >> A[1] >> A[2] >> A[3] >> A[4]) {
        std::cin >> B[0] >> B[1] >> B[2] >> B[3] >> B[4];
        bool compatible{true};
        for (int i{}; i < 5; ++i) {
            if (A[i] == B[i]) {
                compatible = false;
                break;
            }
        }
        output << (compatible ? "Y" : "N") << '\n';
    }
    std::cout << output.str();
}
