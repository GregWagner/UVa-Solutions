/*
 * Mixed Fractions
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int num, den;
    while (std::cin >> num >> den) {
        if (num == 0 && den == 0) {
            break;
        }
        if (num < den) {
            output << 0 << ' ' << num << " / " << den << '\n';
        } else {
            output << (num / den) << ' ' << (num % den) << " / " << den << '\n';
        }
    }
    std::cout << output.str();
}
