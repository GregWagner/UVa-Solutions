/*
 * UVa 10550 - Combination Lock
 * Simple, do as asked.
 */
#include <iostream>
#include <sstream>

int main()
{
  const int DEGREES_PER_TICK {9};
  const int EXTRA_TURNS {120};

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::ostringstream output;
  int count {};

  int initial {}, first {}, second {}, third{};
  while (true) {
    std::cin >> initial >> first >> second >> third;
    if (initial == 0 && first == 0 && second == 0 && third == 0) {
      break;
    }

    count = EXTRA_TURNS;

    // stop at first number
    count += (initial - first > 0 ? initial - first : initial + (40 - first));

    // counter clockwise to second number
    count += (second - first > 0 ? second - first : second + (40 - first));
    
    // clockwise to thrid number
    count += (second - third > 0 ? second - third : second + (40 - third));

    output << count * DEGREES_PER_TICK  << '\n';
  }

  std::cout << output.str();
}
