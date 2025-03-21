#include <iostream>
#include <cmath>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  double miles{};
  std::cin >> miles;

  std::cout << (int)std::round(miles * 5280 / 4.854);
}