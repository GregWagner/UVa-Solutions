/*
 * UVa 00272 - TEX Quotes
 * Replace all double quotes to TEX() style quotes)
 */
#include <iostream>
#include <sstream>

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string input {};
  std::ostringstream output;

  bool first {true};
  while (std::getline(std::cin, input)) {
    for (auto c : input) {
      if (c == '\"') {
        output << (first ? "``" : "''");
        first = !first;
      } else {
        output << c;
      }
    }
    output << '\n';
  }
  std::cout << output.str();
}
