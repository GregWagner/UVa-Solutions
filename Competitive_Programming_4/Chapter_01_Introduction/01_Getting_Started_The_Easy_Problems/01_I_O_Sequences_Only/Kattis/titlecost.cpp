#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string title;
  double cap{};
  std::cin >> title >> cap;

  std::cout << std::setprecision(12) << std::min((double)title.length(), cap) << '\n';
}