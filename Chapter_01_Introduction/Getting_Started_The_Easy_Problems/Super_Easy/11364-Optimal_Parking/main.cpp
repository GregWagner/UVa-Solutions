/*
 * UVa 11364 - Parking
 * Linear scan to get l & r, answer = 2 * (r - l)
 */
#include <iostream>
#include <sstream>

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::ostringstream output;
  int testCases {};
  std::cin >> testCases;
  while (testCases--) {
    int storesToVisit {};
    std::cin >> storesToVisit;

    int min {1000}, max {};
    int input {};
    for (int i {}; i < storesToVisit; ++i) {
      std::cin >> input;
      min = std::min(min, input);
      max = std::max(max, input);
    }
    output << 2 * (max - min) << '\n';
  }
  std::cout << output.str();
}
