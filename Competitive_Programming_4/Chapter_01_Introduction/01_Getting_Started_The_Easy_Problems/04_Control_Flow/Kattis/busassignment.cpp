#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  int maxCapacity{};
  int capacity{};
  while (n--) {
    int a, b;
    std::cin >> a >> b;
    capacity += b - a;
    maxCapacity = std::max(capacity, maxCapacity);
  }
  std::cout << maxCapacity << '\n';
}