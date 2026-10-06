#include <iostream>
#include <iomanip>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  int count{};
  for (int i{}; i < m; ++i) {
    std::string s;
    std::cin >> s;
    for (const auto c : s) {
      if (c == '.') {
        ++count;
      }
    }
  }
  std::cout << std::fixed << std::setprecision(10);
  std::cout << (double)count / (n * m) << '\n';
}