// Heroes of Velmar
// Problem: https://open.kattis.com/problems/flytibaka
#include <iostream>
#include <vector>


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::vector<std::vector<std::string>> a;

  for (int line{}; line < 6; ++line) {

  }
  int n;
  std::cin >> n;

  int sum{ 0 };
  for (int i{ 1 }; i <= n; ++i) {
    sum += i * i;
  }
  std::cout << sum << '\n';
}