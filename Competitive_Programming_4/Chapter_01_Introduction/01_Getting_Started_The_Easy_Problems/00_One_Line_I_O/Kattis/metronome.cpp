#include <iostream>
#include <iomanip>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int ticks{};
  std::cin >> ticks;
  std::cout << std::setprecision(2) << std::fixed << (ticks / 4.0) << '\n';
}