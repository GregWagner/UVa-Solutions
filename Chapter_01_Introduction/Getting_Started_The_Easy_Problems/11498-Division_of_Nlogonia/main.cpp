/*
 * 11498 Division of Nlogonia
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int numberOfQueries {};
    while (std::cin >> numberOfQueries && numberOfQueries != 0) {
        int n {};
        int m {};
        std::cin >> n >> m;
        for (int i {}; i < numberOfQueries; ++i) {
            int x {};
            int y {};
            std::cin >> x >> y;
            if (x == n || y == m) {
                output << "divisa\n";
            } else if (x > n) {
                output << (y > m ? "NE" : "SE") << '\n';
            } else {
                output << (y > m ? "NO" : "SO") << '\n';
            }
        }
    }

    std::cout << output.str();
}
