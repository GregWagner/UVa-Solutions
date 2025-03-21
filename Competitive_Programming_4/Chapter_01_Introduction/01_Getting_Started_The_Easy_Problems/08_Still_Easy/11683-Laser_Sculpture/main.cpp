/*
 * Problem 11683 - Laser Sculpture
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int height {};
    while (std::cin >> height && height != 0) {
        int length {};
        int previous {};
        std::cin >> length >> previous;
        int count {height - previous};

        for (int i {1}; i < length; ++i) {
            int next {};
            std::cin >> next;
            if (next < previous) {
                count += previous - next;
            }
            previous = next;
        }
        output << count << '\n';
    }
    std::cout << output.str();
}
