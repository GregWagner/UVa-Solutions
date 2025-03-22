#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int wc, hc, ws, hs;
  std::cin >> wc >> hc >> ws >> hs;
  std::cout << (wc - 2 >= ws && hc - 2 >= hs)
    ? "1\n" : "0\n";
}