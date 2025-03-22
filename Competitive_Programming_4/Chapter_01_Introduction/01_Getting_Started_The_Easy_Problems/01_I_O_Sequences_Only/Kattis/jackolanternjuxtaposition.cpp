#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int eyes, nose, mouth;
  std::cin >> eyes >> nose >> mouth;

  std::cout << eyes * nose * mouth << '\n';
}
