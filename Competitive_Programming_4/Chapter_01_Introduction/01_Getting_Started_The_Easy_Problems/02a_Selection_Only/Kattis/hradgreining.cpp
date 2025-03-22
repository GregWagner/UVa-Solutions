#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string dna;
  std::cin >> dna;

  if (dna.find("COV") != std::string::npos) {
    std::cout << "Veikur!\n";
  } else {
    std::cout << "Ekki veikur!\n";
  }
}