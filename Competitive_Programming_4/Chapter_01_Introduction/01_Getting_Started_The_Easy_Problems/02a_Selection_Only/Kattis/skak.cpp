#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a, b, c, d;
  std::cin >> a >> b >> c >> d;

  std::cout << (a == c || b == d
    ? "1\n" : "2\n");
}