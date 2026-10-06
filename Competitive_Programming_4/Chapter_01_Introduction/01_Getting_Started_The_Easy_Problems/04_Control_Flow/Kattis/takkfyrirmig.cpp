#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  for (int i{}; i < n; ++i) {
    std::string s;
    std::cin >> s;
    std::cout << "Takk " << s << '\n';;
  } 
}