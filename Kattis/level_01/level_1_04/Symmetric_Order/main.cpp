/*
 * Symmetric Order
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int n;
    int test {0};
    while (std::cin >> n && n != 0) {
        output << "SET " << ++test << '\n';
        std::string a[20];
        for (int i {}; i < n; ++i) {
            std::string temp;
            std::cin >> temp;
            a[i] = temp;
        }

        for (int i{}; i < n; i += 2) {
            output << a[i] << '\n';
        }
        int start = (n % 2 == 0 ? n - 1 : n - 2);
        for (int i = start; i > 0; i -= 2) {
            output << a[i] << '\n';
        }
    }
    std::cout << output.str();
}
