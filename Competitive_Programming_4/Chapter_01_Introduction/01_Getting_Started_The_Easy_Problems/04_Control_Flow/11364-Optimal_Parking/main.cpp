#include <iostream>
#include <sstream>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    int n {};
    std::cin >> n;
    while (n--) {
        int first {200};
        int last {-1};
        int number_of_stores {};
        std::cin >> number_of_stores;
        while (number_of_stores--) {
            int store {};
            std::cin >> store;
            first = std::min(first, store);
            last = std::max(last, store);
        }
        output << (2 * (last - first)) << '\n';
    }
    std::cout << output.str();
}
