#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int year{};
  std::cin >> year;
  std::cout << ((year <= 2020)
    ? 1000 : 1000 + (year - 2020) * 100) << '\n';
}