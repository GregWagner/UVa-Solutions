/*
 * UVa 01124 - Celebtiry Jeopardy
 * Just echo/re-print the input again
 */
#include <iostream>
#include <sstream>

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::ostringstream output;
  std::string input;

  while (std::getline(std::cin, input)) {
    output << input << '\n';
  }
  std::cout << output.str();
}
