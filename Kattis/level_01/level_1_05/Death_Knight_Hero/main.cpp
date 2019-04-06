/*
 * Death Knight Hero
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int count {};
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        std::string input;
        std::cin >> input;
        if (input.find("CD") == std::string::npos) {
            ++count;
        }
    }
    std::cout << count << '\n';
}
