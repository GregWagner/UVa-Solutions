/*
 * 11727 - Cost Curring
 * Sort the 3 numbers and get the median
 */
#include <iostream>
#include <sstream>
#include <array>
#include <algorithm>

int main()
{
  std::array<int, 3> a;
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::ostringstream output;
  int testCases {};
  std::cin >> testCases;
  int test {1};
  while (testCases--) {
    std::cin >> a[0] >> a[1] >> a[2];
    std::sort(a.begin(), a.end());
    output << "Case " << test++ << ": " << a[1] << '\n';
  }
  std::cout << output.str();
}
