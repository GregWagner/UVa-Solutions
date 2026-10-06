#include <iostream>
#include <iomanip>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  double result{};
  for (int i{}; i < n; ++i) {
    double x, y;
    std::cin >> x >> y;
    result += x * y;
  }
  std::cout << std::fixed << std::setprecision(5) << result << '\n';
}