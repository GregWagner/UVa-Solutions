#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s;
  std::getline(std::cin, s);
  std::cout << "Kvedja,\n" << s << '\n';
}
