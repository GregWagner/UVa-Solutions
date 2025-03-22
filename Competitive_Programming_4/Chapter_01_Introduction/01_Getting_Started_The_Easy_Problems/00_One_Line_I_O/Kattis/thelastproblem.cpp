#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string name;
  std::getline(std::cin, name);
  std::cout << "Thank you, " << name << ", and farewell!\n";
}