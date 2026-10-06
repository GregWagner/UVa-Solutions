#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int numberOfContestants {};
    int numberOfProblems {};
    std::cin >> numberOfContestants >> numberOfProblems;
    std::cout << numberOfProblems << '\n';
}