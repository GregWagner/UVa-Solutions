/*
 * UVa 10963 - The Swalling Ground
 * For two blocks to me mergable, the gabs between their columns must be the same
 */
#include <iostream>
#include <sstream>

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::ostringstream output;
  int testCases {};
  bool first {true};
  std::cin >> testCases;
  while (testCases--) {
    int columns {};
    std::cin >> columns;

    int x, y;
    std::cin >> x >> y;
    int gap {x - y};

    bool closeable {true};
    for (int i {1}; i < columns; ++i) {
      std::cin >> x >> y;
      if (x - y != gap) {
        closeable = false;
      }
    }
    output << (first ? "" : "\n");
    first = false;
    output << (closeable ? "yes" : "no") << '\n';
  }
  std::cout << output.str();
}
