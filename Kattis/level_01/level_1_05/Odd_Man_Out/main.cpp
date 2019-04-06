/*
 * Odd Man Out
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int testCases;
    int test {};
    std::cin >> testCases;
    while (testCases--) {
        std::vector<int> a;
        int numberOfGuests;
        std::cin >> numberOfGuests;
        while (numberOfGuests--) {
            int input;
            std::cin >> input;
            a.push_back(input);
        }
        std::sort(a.begin(), a.end());
        for (size_t i {}; i < a.size(); i = i + 2) {
            if (a[i] != a[i + 1]) {
                output << "Case #" << ++test << ": " << a[i] << '\n';
                break;
            }
        }
    }
    std::cout << output.str();
}
