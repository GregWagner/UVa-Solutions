#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  int length{};
  for (int i{}; i < n; ++i) {
    int x;
    std::cin >> x;
    length += x;
  }
  std::cout << length - n + 1 << '\n';
}