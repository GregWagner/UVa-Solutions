#include <iostream>
#include <sstream>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;
    int test_case {};
    int problem_sets {};
    std::cin >> problem_sets;
    while (problem_sets--) {
        bool has_zero {};
        for (int i {}; i < 13; ++i) {
            int input {};
            std::cin >> input;
            if (input == 0) {
                has_zero = true;
            }
        }
        output << "Set #" << ++test_case << ": "
            << (has_zero ? "No" : "Yes") << '\n';
    }
    std::cout << output.str();
}
