#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int sweet, sour;
  while (true) {
    std::cin >> sweet >> sour;  // Read the first two integers
    if (sweet == 0 && sour == 0) {
      break;
    }
    if (sweet + sour == 13) {
      std::cout << "Never speak again.\n";
    } else if (sweet > sour) {
      std::cout << "To the convention.\n";
    } else if (sweet < sour) {
      std::cout << "Left beehind.\n";
    } else {
      std::cout << "Undecided.\n";
    }
  }
}
