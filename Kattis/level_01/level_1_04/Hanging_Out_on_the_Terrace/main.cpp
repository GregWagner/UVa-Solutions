/*
 * Hanging Out of the Terrace
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int count {};
    int denied {};

    int limit, events;
    std::cin >> limit >> events;
    while (events--) {
        std::string event;
        int amount;
        std::cin >> event >> amount;
        if (event == "enter") {
            if (count + amount > limit) {
                ++denied;
            } else {
                count += amount;
            }
        } else {
            count -= amount;
        }
    }
    std::cout << denied << '\n';
}
