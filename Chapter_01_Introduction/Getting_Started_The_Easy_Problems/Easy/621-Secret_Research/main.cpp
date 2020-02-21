/*
 * Uva 00621 - Secret Research
 * Case analysis for only 4 possible outputs
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
    std::string input {};
    std::cin >> input;
    const int size = input.size() - 1;
    if (input == "1" || input == "4" || input == "78") {
      output << "+\n";
    } else if (size > 1 && input[size - 1] == '3' && input[size] == '5') {
      output << "-\n";
    } else if (size > 1 && input[0] == '9' && input[size] == '4') {
      output << "*\n";
    } else {
      output << "?\n";
    }
  }
  std::cout << output.str();
}
