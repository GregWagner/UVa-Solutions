#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a, b, c, n;
  std::cin >> a >> b >> c >> n;

  if (n >= 3 && a != 0 && b != 0 && c != 0 && a + b + c >= n) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
}