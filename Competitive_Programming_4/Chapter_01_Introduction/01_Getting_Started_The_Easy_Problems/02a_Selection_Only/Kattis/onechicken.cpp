#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  if (m > n) {
    std::cout << "Dr. Chaz will have " << m - n << " piece"
      << (m - n > 1 ? "s" : "") << " of chicken left over!\n";
  } else {
    std::cout << "Dr. Chaz needs " << n - m << " more piece"
      << (n - m > 1 ? "s" : "") << " of chicken!\n";
  }
}