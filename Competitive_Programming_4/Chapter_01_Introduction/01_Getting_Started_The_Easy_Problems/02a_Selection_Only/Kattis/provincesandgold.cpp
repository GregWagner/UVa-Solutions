#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int gold, silver, copper;
  std::cin >> gold >> silver >> copper;

  int total{ (gold * 3) + (silver * 2) + copper };

  
}
