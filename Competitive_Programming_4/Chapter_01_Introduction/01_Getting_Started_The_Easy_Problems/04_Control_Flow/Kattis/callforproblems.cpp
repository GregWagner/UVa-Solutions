#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int numOfProblems{};
  std::cin >> numOfProblems;

  int count{};
  while (numOfProblems--) {
    int difficulty{};
    std::cin >> difficulty;

    if (difficulty % 2 != 0) {
      ++count;
    }
  }
  std::cout << count << '\n';
}