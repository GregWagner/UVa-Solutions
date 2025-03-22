#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int amount{};
  std::cin >> amount;

  if (amount >= 7) {
    std::cout << "7\n";
  } else if (amount > 0) {
    std::cout << amount + 1 << '\n';
  } else {
    std::cout << "0\n";
  }
}