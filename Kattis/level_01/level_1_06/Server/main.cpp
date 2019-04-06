/*
 * Server
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int t, n;
    std::cin >> n >> t;
    int count {};
    while (n--) {
        int number;
        std::cin >> number;
        if (t - number < 0) {
            break;
        }
        t -= number;
        ++count;
    }
    std::cout << count << '\n';
}
