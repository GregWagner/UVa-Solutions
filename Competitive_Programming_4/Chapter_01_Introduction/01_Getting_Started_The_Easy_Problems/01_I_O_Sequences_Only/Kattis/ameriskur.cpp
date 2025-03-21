#include <iostream>
#include <iomanip>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int length{};
  std::cin >> length;
  std::cout << std::setprecision(20) << length * 0.09144 << '\n';
}