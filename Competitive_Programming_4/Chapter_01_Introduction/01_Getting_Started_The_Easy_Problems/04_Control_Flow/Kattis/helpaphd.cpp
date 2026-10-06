#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;
  while (n--) {
    std::string s;
    std::cin >> s;
    if (s == "P=NP") {
      std::cout << "skipped\n";
    } else {
      std::string first{ s.substr(0, s.find('+')) };
      std::string second{ s.substr(s.find('+') + 1) };
      std::cout << std::stoi(first) + std::stoi(second) << '\n';
    }
  } 
}