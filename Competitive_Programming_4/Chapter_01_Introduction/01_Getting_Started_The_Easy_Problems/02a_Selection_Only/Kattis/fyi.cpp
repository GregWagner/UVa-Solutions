#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s;
  std::cin >> s;

  if (s[0] == '5' && s[1] == '5' && s[2] == '5') {
    std::cout << "1\n";
  } else {
    std::cout << "0\n";
  }
}