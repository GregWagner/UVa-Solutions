#include <iostream>

int main() {
    int weight {};
    std::cin >> weight;
    if (weight <= 3) {
        std::cout << "NO\n";
    } else {
        std::cout << (weight % 2 == 0 ? "YES" : "NO") << '\n';
    }
}
