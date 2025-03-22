#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s;
  std::getline(std::cin, s);
  int n = s.length();

  if (s[n - 1] == '?' && s[n - 2] == 'h'
    && s[n - 3] == 'e') {
    std::cout << "Canadian!\n";
  } else {
    std::cout << "Imposter!\n";
  }
}