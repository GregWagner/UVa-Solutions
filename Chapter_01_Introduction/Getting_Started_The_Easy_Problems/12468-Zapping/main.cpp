#include <iostream>
#include <sstream>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    int current {};
    int desired {};
    while (std::cin >> current >> desired && current != -1 && desired != -1) {
        int button_presses {};
        if (current < desired) {
            button_presses = std::min(desired - current,
                current + 100 - desired);
        } else {
            button_presses = std::min(current - desired,
                desired + 100 - current);
        }
        output << button_presses << '\n';
    }
    std::cout << output.str();
}
