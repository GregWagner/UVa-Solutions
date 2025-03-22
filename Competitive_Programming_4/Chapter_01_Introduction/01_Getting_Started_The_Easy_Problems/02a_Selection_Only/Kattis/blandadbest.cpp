#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;
  if (n == 1) {
    std::cout << "blandad best" << '\n';
  } else {
    std::string meat;
    std::cin >> meat;
    std::cout << meat << '\n';
  }
}
