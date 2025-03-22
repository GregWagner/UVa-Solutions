#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string input;
  std::getline(std::cin, input);
  std::cout << input << ' ' << input << ' ' << input << '\n';
}