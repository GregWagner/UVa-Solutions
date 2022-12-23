#include <iostream>
#include <sstream>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    int a[60];
    int setNumber{1};

    int n{};
    while (std::cin >> n && n != 0) {
        int total{};
        for (int i{}; i < n; ++i) {
            std::cin >> a[i];
            total += a[i];
        }

        int stackHeight = total / n;
        int answer{};
        for (int i{}; i < n; ++i) {
            if (a[i] > stackHeight) {
                answer += a[i] - stackHeight;
            }
        }
        output << "Set #" << setNumber++ << '\n'
               << "The minimum number of moves is " << answer << ".\n\n";
    }
    std::cout << output.str();
}
