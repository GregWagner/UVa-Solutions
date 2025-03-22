#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int improvementsSinceFrozen{};
  int improvementsPerYear{};
  std::cin >> improvementsSinceFrozen >> improvementsPerYear;
  std::cout << 2022 + (improvementsSinceFrozen / improvementsPerYear) << '\n';
}