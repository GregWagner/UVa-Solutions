#include <iostream>
#include <sstream>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;
    int test_case {};
    int n {};
    std::cin >> n;
    while (n--) {
        int l, w, h;
        std::cin >> l >> w >> h;
        output << "Case " << ++test_case << ": " <<
            (l <= 20 && w <= 20 && h <= 20 ? "good" : "bad") << '\n';
    }

    std::cout << output.str();
}
