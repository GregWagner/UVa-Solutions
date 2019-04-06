/*
 * Reversed Binary Numbers
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int binary[50];

    unsigned long n;
    int index {};
    std::cin >> n;
    while (n > 0) {
        binary[index++] =  (n % 2);
        n /= 2;
    }

    n = 0;
    int mult {1};
    for (int i {index - 1}; i >= 0; --i) {
        n += mult * binary[i];
        mult *= 2;
    }
    std::cout << n << '\n';
}
