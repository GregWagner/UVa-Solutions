#include <iostream>
#include <sstream>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    int a{}, b{}, c{};
    while (std::cin >> a >> b >> c) {
        if (a == b && b == c) {
            output << "*\n";
        } else if (b == c) {
            output << "A\n";
        } else if (a == c) {
            output << "B\n";
        } else {
            output << "C\n";
        }
    }
    std::cout << output.str();
}
