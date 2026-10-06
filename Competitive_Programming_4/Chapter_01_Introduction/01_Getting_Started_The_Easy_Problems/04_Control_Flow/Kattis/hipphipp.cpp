#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s = "Hipp hipp hurra!\n";
  for (int i{}; i < 20 ; ++i) {
    std::cout << s;
  } 
}