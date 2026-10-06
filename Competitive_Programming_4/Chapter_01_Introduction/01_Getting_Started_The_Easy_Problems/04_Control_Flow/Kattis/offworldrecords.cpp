#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int n, current, previous;
    std::cin >> n >> current >> previous;
    int count{};
    while (n--) {
        int next;
        std::cin >> next;
        if (next > current + previous) {
            ++count;
            if (next > current) {
                previous = current;
                current = next;
            } else if (next > previous) {
                previous = next;
            }
        }
    }
    std::cout << count << '\n';
}