#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  char c;
  std::cin >> c;

  if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
    std::cout << "Jebb\n";
  } else if (c == 'Y') {
    std::cout << "Kannski \n";
  } else {
    std::cout << "Neibb\n";
  }
}