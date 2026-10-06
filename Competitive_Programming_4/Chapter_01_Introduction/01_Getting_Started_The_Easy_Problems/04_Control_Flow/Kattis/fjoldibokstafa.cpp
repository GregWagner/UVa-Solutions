#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s;
  std::cin >> s;

  int count{};
  for (char c : s) {
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
      ++count;
    }
  }
  std::cout << count << '\n';
}