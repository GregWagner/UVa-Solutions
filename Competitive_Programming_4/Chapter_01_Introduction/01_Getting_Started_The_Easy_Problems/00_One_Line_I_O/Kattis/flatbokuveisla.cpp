#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int numberOfSlices{};
  int numberOfResidents{};
  std::cin >> numberOfSlices >> numberOfResidents;

  std::cout << numberOfSlices % numberOfResidents << '\n';
}