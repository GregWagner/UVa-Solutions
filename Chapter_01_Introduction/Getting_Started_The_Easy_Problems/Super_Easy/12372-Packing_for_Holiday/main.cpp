/*
 * UVa 12372 - Packing for Holiday
 * Just check if all L, W, H <= 20
 */
#include <iostream>
#include <sstream>

int main()
{
  const int SIZE {20};
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::ostringstream output;
  int testCases {};
  std::cin >> testCases;
  int test {1};
  while (testCases--) {
    int length {}, width {}, height {};
    std::cin >> length >> width >> height;
    output << "Case " << test++ << ": "
      << (length <= SIZE && width <= SIZE && height <= SIZE
          ? "good" : "bad") << '\n';
  }
  std::cout << output.str();
}
