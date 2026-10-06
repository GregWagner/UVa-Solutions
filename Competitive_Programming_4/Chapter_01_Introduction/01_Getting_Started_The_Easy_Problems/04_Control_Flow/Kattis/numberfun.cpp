#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;
  while (n--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a + b == c || a * b == c || a - b == c || b - a == c
      || (b != 0 && b * c == a) || (a != 0 && a * c == b)) {
      std::cout << "Possible\n";
    } else {
      std::cout << "Impossible\n";
    }
  }
}
  