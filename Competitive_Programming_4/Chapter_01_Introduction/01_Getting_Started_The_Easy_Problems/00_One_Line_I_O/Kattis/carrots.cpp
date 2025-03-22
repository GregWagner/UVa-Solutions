#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int numberOfContestants {};
    int numberOfProblems {};
    std::cin >> numberOfContestants >> numberOfProblems;
    std::cout << numberOfProblems << '\n';
}