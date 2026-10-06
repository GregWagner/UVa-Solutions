#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;
  int budget{};
  while (n--) {
    std::string name;
    int cost;
    std::cin >> name >> cost;
    budget += cost;
  }
  if (budget == 0) {
    std::cout << "Lagom\n";
  } else if (budget < 0) {
    std::cout << "Nekad\n";
  } else {
    std::cout << "Usch, vinst\n";
  }
}