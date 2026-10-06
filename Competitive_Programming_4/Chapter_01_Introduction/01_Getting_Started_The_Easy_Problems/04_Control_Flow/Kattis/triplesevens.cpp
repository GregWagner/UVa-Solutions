#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;
  bool valid{ true };
  for (int i{}; i < 3; ++i) {
    bool goodWheel{ };
    for (int j{}; j < n; ++j) {
      int a;
      std::cin >> a;
      if (a == 7) {
        goodWheel = true;
      }
    }
    if (!goodWheel) {
      valid = false;
    }
  }
  std::cout << (valid ? "777" : "0") << '\n';
}