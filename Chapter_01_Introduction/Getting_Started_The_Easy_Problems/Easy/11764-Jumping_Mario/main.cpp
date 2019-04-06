/*
 * Problem 11764 - Jumping Mario
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int test {1};
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int high {};
        int low {};
        int jumps;
        std::cin >> jumps;
        if (jumps > 0) {
            int start;
            std::cin >> start;
            for (int i = 1; i < jumps; ++i) {
                int next;
                std::cin >> next;
                if (start > next) {
                    ++low;
                } if (start < next) {
                    ++high;
                }
                start = next;
            }
        }
        std::cout << "Case " << test++ << ": " << high << " " << low << '\n';
    }
    std::cout << output.str();
}
