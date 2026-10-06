#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string answer;
  int count{};

  std::string s;
  while (std::getline(std::cin, s)) {
    ++count;
    answer += s;
    answer += '\n';

  }
  std::cout << count << '\n' << answer;
}