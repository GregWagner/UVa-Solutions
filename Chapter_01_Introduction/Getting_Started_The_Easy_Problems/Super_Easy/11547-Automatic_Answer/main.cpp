/*
 * UVa 11547 - Automatic Answer
 * A One liner O(1) solution exists
 */
#include <iostream>
#include <sstream>
#include <cmath>

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::ostringstream output;
  int testCases {};
  std::cin >> testCases;
  while (testCases--) {
    int n {};
    std::cin >> n;
    output << std::abs(((((n * 63) + 7492) * 5) - 498) % 100 / 10) << '\n';
  }
  std::cout << output.str();
}
