/*
 * License to Launch
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int days;
    std::cin >> days;
    unsigned long min;
    int index {0};

    for (int i {}; i < days; ++i) {
        unsigned long temp;
        std::cin >> temp;
        if (i == 0) {
            min = temp;
        } else if (temp < min) {
            min = temp;
            index = i;
        }
    }
    std::cout << index << '\n';
}
