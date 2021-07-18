/*
 * UVa 11498 - Division of Nlogonia
 * just use if-else statements
 */
#include <iostream>
#include <sstream>

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::ostringstream output;
  int testCases {};
  while (std::cin >> testCases) {
    if (testCases == 0) {
      break;
    }
    int m {}, n {};
    std::cin >> m >> n;
    while (testCases--) {
      int x {}, y {};
      std::cin >> x >> y;

      if (x == m || y == n) {
        output << "divisa\n";
      } else if (x > m) {
        output << (y > n ? "NE\n" : "SE\n");
      } else {
        output << (y > n ? "NO\n" : "SO\n");
      }
    }
  }
  std::cout << output.str();
}
