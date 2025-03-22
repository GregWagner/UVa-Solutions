#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int windowsCovered{}, windowsOpen{};
  std::cin >> windowsCovered >> windowsOpen;
  std::cout << windowsCovered - windowsOpen << '\n';
}