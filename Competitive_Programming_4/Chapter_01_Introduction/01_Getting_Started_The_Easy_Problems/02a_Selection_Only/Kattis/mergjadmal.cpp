#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s;
  std::cin >> s;

  if (s.find("69") == std::string::npos && s.find("420") == std::string::npos) {
    std::cout << "Leim!\n";
  } else {
    std::cout << "Mergjad!\n";
  }
}