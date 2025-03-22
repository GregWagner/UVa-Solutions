#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s1, s2;
  std::getline(std::cin, s1);
  std::getline(std::cin, s2);

  int s1split = s1.find('|');
  int s2split = s2.find('|');

  std::cout << s1.substr(0, s1split) << s2.substr(0, s2split) << ' '
    << s1.substr(s1split + 1) << s2.substr(s2split + 1) << '\n';
}