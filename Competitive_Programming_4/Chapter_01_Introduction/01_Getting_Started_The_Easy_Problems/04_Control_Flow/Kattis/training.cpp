#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

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