#include <iostream>

// not working correctly

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int rate, seconds;
  std::cin >> rate >> seconds;

  auto angle = (rate * seconds) % 360;
  std::cout << angle << '\n';

  // Calculate the total number of blueberries
  std::cout << (angle > 0 && angle < 180 ? "up" : "down")
    << '\n';
}