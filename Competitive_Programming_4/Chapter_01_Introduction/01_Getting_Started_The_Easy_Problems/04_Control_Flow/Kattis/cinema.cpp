#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  int current{};
  int count{};
  while (m--) {
    int groupSize{};
    std::cin >> groupSize;
    if (current + groupSize <= n) {
      current += groupSize;
    } else {
      ++count;
    }
  }
  std::cout << count << '\n';
}