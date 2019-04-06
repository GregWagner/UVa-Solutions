/*
 * Spavanac
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int hour, minute;
    std::cin >> hour >> minute;
    if (minute >= 45) {
        std::cout << hour << ' ' << minute - 45 << '\n';
    } else if (hour > 0) {
        std::cout << hour - 1 << ' ' << minute + 15 << '\n';
    } else {
        std::cout << 23 << ' ' << minute + 15 << '\n';
    }
}
