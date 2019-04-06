/*
 * Stuck in a Time Loop
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int n;
    std::cin >> n;
    for (int i {1}; i <= n; ++i) {
        output << i << " Abracadabra\n";
    }
    std::cout << output.str() << '\n';
}
