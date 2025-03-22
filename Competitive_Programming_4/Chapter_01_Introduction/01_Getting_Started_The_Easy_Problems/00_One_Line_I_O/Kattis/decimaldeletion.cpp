#include <iostream>
#include <cmath>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  double input;
  std::cin >> input;
  std::cout << std::round(input) << '\n';
}