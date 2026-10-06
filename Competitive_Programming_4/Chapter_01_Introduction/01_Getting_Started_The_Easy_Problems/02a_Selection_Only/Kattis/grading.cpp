#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a, b, c, d, e, exam;
  std::cin >> a >> b >> c >> d >> e  >> exam;

  if (exam <= 100 && exam >= a) std::cout << "A\n";
  else if (100 && exam >= b) std::cout << "B\n";
  else if (100 && exam >= c) std::cout << "C\n";
  else if (100 && exam >= d) std::cout << "D\n";
  else if (100 && exam >= e) std::cout << "E\n";
  else std::cout << "F\n";
}