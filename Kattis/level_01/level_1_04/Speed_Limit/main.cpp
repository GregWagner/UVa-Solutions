/*
 * Speed Limit
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int n;
    while (std::cin >> n && n != -1) {
        int previousTime {};
        int total {};
        for (int i {}; i < n; ++i) {
            int speed, time;
            std::cin >> speed >> time;
            total += speed * (time - previousTime);
            previousTime = time;
        }
        output << total << " miles\n";
    }
    std::cout << output.str();
}
