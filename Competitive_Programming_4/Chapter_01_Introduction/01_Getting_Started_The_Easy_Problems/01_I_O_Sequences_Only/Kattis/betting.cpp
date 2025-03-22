#include <iostream>
#include <iomanip>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int percentage{};
  std::cin >> percentage;

  std::cout << std::setprecision(10) << std::fixed
    << 100.0 / percentage << '\n'
    << 100.0 / (100 - percentage) << '\n';
}