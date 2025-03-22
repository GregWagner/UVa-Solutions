#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr); 

  std::string month;
  int day;
  std::cin >> month >> day;
  if ((month == "OCT" && day == 31) || (month == "DEC" && day == 25)) {
    std::cout << "yup\n";
  } else {
    std::cout << "nope\n";
  }
}