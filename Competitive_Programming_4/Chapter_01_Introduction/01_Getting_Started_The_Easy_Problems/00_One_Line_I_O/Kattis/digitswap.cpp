#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string number;
  std::cin >> number;
  std::cout << number[1] << number[0] << '\n';
}