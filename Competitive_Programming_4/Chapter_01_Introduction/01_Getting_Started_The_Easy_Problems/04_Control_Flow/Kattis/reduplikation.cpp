#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s;
  int n;
  std::cin >> s >> n;

  std::string answer;
  for (int i{}; i < n; ++i) {
    answer += s;
  }
  std::cout << answer << '\n';
}