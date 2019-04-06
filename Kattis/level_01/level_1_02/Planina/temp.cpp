/*
 * Planina
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int count {2};
    int increment {1};
    for (int i = 1; i <=15; ++i) {
        count += increment;
        increment *= 2;
        std::cout << i << ": " << count * count << '\n';
    }
}
