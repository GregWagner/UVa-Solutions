#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    int base{};
    int count{};
    bool first{ true };
    while (n--) {
        int piece;
        std::cin >> piece;
        if (first) {
            base = piece;
            ++count;
            first = false;
            continue;
        }
        if (piece > base) {
            base = piece;
            ++count;
        } else {
            base = piece;
        }
    }
    std::cout << count << '\n';
}