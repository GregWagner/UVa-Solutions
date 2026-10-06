#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;
  while (n--) {
    int a;
    std::cin >> a;
    std::cout << a << " is " << (a % 2 == 0 ? "even" : "odd") << '\n';
  }
}