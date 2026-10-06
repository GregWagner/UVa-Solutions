#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int readings{};
  std::cin >> readings;
  int sum{};
  for (int i = 0; i < readings; ++i) {
    int temp{};
    std::cin >> temp;
    sum += temp;
  }
  std::cout << sum / readings << '\n'; // integer division
}