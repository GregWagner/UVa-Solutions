#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a, b;
  std::cin >> a >> b;
  std::cout << std::min(a, b) << ' ' << std::max(a, b) << '\n';
}