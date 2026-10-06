#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  int count{1};
  int previous;;
  std::cin >> previous;

  int current;
  for (int i = 1; i < n; ++i) {
    std::cin >> current;
    if (previous != current + 1) {
      ++count;
    }
    // std::cout << previous << ' ' << current << ' ' << count <<  '\n';
    previous = current;
  }
  std::cout << count << '\n';
}
