#include <iostream>

int main() {
    int n {};
    std::cin >> n;
    int count {};
    while (n--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (a + b + c >= 2) {
            ++count;
        }
    }
    std::cout << count << '\n';
}
