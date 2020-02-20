/*
 * UVa 12250 - Language Detection
 * if-else check
 */
#include <iostream>
#include <sstream>

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::ostringstream output;
  int testCase {1};
  std::string input {};
  while (std::cin >> input && input != "#") {
    if (input == "HELLO") {
      output << "Case " << testCase++ << ": ENGLISH\n";
    } else if (input == "HOLA") {
      output << "Case " << testCase++ << ": SPANISH\n";
    } else if (input == "HALLO") {
      output << "Case " << testCase++ << ": GERMAN\n";
    } else if (input == "BONJOUR") {
      output << "Case " << testCase++ << ": FRENCH\n";
    } else if (input == "CIAO") {
      output << "Case " << testCase++ << ": ITALIAN\n";
    } else if (input == "ZDRAVSTVUJTE") {
      output << "Case " << testCase++ << ": RUSSIAN\n";
    } else {
      output << "Case " << testCase++ << ": UNKNOWN\n";
    }
  }
  std::cout << output.str();
}
