#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ostringstream output;

    int velocity {};
    int time {};
    while (std::cin >> velocity >> time) {
        output << 2 * velocity * time << '\n';
    }

    std::cout << output.str();
}
