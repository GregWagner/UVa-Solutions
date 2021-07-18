/*
 * UVa 11172 - Relational Operators
 * Ad hoc - very easy, one liner
 */
#include <iostream>
#include <sstream>

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::ostringstream output;
  int testCases {}, a {}, b {};
  std::cin >> testCases;
  while (testCases--) {
    std::cin >> a >> b;
    output << (a == b ? '=' :
      (a > b ? '>' : '<')) << '\n';
  }

  std::cout << output.str();
}
