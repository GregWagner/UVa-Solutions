#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s;
  std::getline(std::cin, s);
  int sum = 0;
  for (char c : s) {  
    sum += int(c);
  }
  std::cout << static_cast<char>(sum / s.length()) << '\n'; 
}