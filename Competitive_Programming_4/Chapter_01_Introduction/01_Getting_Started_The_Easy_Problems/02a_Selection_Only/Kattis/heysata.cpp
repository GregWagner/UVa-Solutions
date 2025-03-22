#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;
  std::cin.ignore(); // Ignore the newline character after reading n
  std::string needle;
  std::getline(std::cin, needle);
  std::string haystack;
  std::getline(std::cin, haystack);

  if (haystack.find(needle) != std::string::npos) {
    std::cout << "Unnar fann hana!\n";
  } else {
    std::cout << "Unnar fann hana ekki!\n";
  }
}