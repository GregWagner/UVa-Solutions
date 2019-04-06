/*
 * Trik
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string input;
    std::cin >> input;
    int position {1};
    for (char c : input) {
        if (c == 'A') {
            if (position != 3) {
                position = (position == 1 ? 2 : 1);
            }
        } else if (c == 'B') {
            if (position != 1) {
                position = (position == 2 ? 3 : 2);
            }
        } else {
            if (position != 2) {
                position = (position == 1 ? 3 : 1);
            }
        }
    }
    std::cout << position << '\n';
}
