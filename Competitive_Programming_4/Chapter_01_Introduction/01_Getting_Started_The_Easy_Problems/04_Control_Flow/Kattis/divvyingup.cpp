#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int numOfContests{};
  std::cin >> numOfContests;

  int sum{};
  while (numOfContests--) {
    int prize{};
    std::cin >> prize;
    sum += prize;
  }
  std::cout << (sum % 3 == 0 ? "yes" : "no") << '\n';
}