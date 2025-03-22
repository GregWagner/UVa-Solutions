#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int grossWeight, truckWeight, additionalItems;
  std::cin >> grossWeight >> truckWeight >> additionalItems;

  int additionalWeight{};
  for (int i{}; i < additionalItems; ++i) {
    int itemWeight;
    std::cin >> itemWeight;
    additionalWeight += itemWeight;
  }

  int maxWeight = (grossWeight - truckWeight) * 0.90;
  std::cout << maxWeight - additionalWeight << '\n';
}