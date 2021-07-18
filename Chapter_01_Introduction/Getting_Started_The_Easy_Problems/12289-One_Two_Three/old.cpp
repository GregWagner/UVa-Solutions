/*
 * UVa 12289 - One-Two-Three
 * Just use if-else statements
 */
#include <iostream>
#include <sstream>

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::ostringstream output;
  int testCases {};
  std::cin >> testCases;
  while (testCases--) {
    std::string input;
    std::cin >> input;

    if (input.size() == 5) {
      output << "3\n";
    } else {
      if (input[0] == 'o' && input[1] == 'n') {
        output << "1\n";
      } else if (input[0] == 'o' && input[2] == 'e') {
        output << "1\n";
      } else if (input[1] == 'n' && input[2] == 'e') {
        output << "1\n";
      } else {
        output << "2\n";
      }
    }
  }
  std::cout << output.str();
}
