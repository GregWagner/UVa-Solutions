/*
 * FizzBuzz
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int x, y, n;
    std::cin >> x >> y >> n;
    for (int i {1}; i <= n; ++i) {
        if (i % x == 0 && i % y == 0) {
            output << "FizzBuzz\n";
        } else if (i % x == 0) {
            output << "Fizz\n";
        } else if (i % y == 0) {
            output << "Buzz\n";
        } else {
            output << i << '\n';
        }
    }
    std::cout << output.str();
}
