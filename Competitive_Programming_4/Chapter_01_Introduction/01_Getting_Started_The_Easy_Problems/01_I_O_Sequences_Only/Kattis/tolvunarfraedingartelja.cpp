#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n{};
  std::cin >> n;
  std::cout << n - 1 << '\n';
}