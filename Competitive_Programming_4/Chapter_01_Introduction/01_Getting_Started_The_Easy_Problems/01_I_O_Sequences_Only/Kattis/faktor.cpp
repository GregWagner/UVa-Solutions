#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int numberOfActicles {};
    int impactFactor {};
    std::cin >> numberOfActicles >> impactFactor;
    std::cout << numberOfActicles * (impactFactor - 1) + 1 << '\n';
}