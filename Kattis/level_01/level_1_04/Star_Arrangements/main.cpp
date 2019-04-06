/*
 * Star Arrangements
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int s;
    std::cin >> s;
    output << s << ":\n";
    for (int i {2}; i < s; ++i) {

        // rows alternate and either bottom row has same count as top
        // or bottom row has one fewer than top
        if (s % (i + i - 1) == 0 || (s - i) % (i + i - 1) ==0 ) {
            output << i << "," << i - 1 << '\n';
        }

        // each row has the same number of stars
        if (s % i == 0) {
            output << i << "," << i << '\n';
        }
    }

    std::cout << output.str();
}
