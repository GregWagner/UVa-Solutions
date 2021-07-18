/*
 * UVa 12577 - Hajj-e-Akbar
 * Straightforward
 */
#include <iostream>
#include <sstream>

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::ostringstream output;
  std::string input {};
  int test {1};
  while (std::cin >> input && input != "*") {
    output << "Case " << test++ << ": Hajj-e-"
      << (input == "Hajj" ? "Akbar\n" : "Asghar\n");
  }
  std::cout << output.str();
}
