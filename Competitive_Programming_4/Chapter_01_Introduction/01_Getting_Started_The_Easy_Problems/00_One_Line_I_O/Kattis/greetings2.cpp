#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string greeting;
  std::cin >> greeting;

  int count{ 2 * (greeting.length() - 2) };
  std::cout << "h" + std::string(count, 'e') + "y\n";
}