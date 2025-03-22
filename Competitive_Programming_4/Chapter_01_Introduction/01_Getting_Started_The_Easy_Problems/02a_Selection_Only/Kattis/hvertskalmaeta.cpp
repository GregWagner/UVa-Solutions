#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);  
  std::cout.tie(nullptr);

  std::string s;
  std::getline(std::cin, s);
  if (s == "Akureyri" || s == "Fjardabyggd" || s == "Mulathing") {
    std::cout << "Akureyri\n";
  } else {
    std::cout << "Reykjavik\n";
  }
}