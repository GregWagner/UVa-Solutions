#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int beers, lemonades;
  std::cin >> beers >> lemonades;

  std::cout << 2 * std::min(beers, lemonades) << '\n';
}