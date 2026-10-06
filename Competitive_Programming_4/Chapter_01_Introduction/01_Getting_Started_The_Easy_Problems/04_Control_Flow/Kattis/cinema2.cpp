#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  int current{};
  int count{};
  bool full{};
  while (m--) {
    int groupSize{};
    std::cin >> groupSize;
    if (full) {
      ++count;
      continue;
    } 
    if (current + groupSize <= n) {
      full = true;
      current += groupSize;
    } else {
      ++count;
    }
  }
  std::cout << count << '\n';
}