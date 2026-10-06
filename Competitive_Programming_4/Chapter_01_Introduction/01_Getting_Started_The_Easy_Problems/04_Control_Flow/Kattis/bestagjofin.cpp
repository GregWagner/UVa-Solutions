#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string maxName{};
  int maxFun{};

  int numOfGuests;
  std::cin >> numOfGuests;

  while (numOfGuests--) {
    std::string name;
    int fun;
    std::cin >> name >> fun;

    if (fun > maxFun) {
      maxFun = fun;
      maxName = name;
    }
  }
  std::cout << maxName << '\n';
}