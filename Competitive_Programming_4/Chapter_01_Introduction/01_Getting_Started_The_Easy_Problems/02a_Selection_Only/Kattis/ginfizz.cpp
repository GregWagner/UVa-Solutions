#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n{};
  std::cin >> n;

  std::cout << n * 45 << " ml gin\n"
    << n * 30 << " ml fresh lemon juice\n"
    << n * 10 << " ml simple syrup\n";
  std::cout << n
    << (n == 1
      ? " slice of lemon\n"
      : " slices of lemon\n");
}
