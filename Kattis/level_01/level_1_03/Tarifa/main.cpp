/*
 * Tarifa
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int available {};
    int months;
    std::cin >> available >> months;
    int megabytes {};
    for (int i {}; i < months; ++i) {
        int used;
        std::cin >> used;
        megabytes += available - used;
    }
    std::cout << megabytes + available << '\n';
}
