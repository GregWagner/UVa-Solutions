/*
 * Relocation
 */
#include <iostream>
#include <sstream>
#include <map>

std::map<int, int> comp;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int companies, requests;
    std::cin >> companies >> requests;
    for (int i {1}; i <= companies; ++i) {
        int location;
        std::cin >> location;
        comp[i] = location;
    }

    for (int i {}; i < requests; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (a == 1) {
            comp[b] = c;
        } else {
            output << std::abs(comp[b] - comp[c]) << '\n';
        }
    }
    std::cout << output.str();
}
