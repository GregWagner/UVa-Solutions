#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int numOfProblems, currentSkill;
    std::cin >> numOfProblems >> currentSkill;

    while (numOfProblems--) {
        int lower, upper;
        std::cin >> lower >> upper;

        if (currentSkill >= lower && currentSkill <= upper) {
            ++currentSkill;
        }
    }
    std::cout << currentSkill << '\n';
}