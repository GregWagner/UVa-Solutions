/*
 * UVa 12403 - Save Setu
 * Straightforward
 */
#include <iostream>
#include <sstream>

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::ostringstream output;
  int amount {};
  int testCases {};
  std::cin >> testCases;
  while (testCases--) {
    std::string input;
    std::cin >> input;
    if (input == "donate") {
      int donation {};
      std::cin >> donation;
      amount += donation;
    } else {
      output << amount << '\n';
    }
  }
  std::cout << output.str();
}
