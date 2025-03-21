#include <iostream>
#include <sstream>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;
    int test_case {};
    int test;
    std::cin >> test;
    while (test--) {
        int speed {};
        int n {};
        std::cin >> n;
        while (n--) {
            int input;
            std::cin >> input;
            speed = std::max(speed, input);
        }
        output << "Case " << ++test_case << ": " << speed << '\n';
    }
    std::cout << output.str();
}
