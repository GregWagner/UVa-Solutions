/*
 * UVa 10300 - Ecological Premium
 * Ignore the number of animals
 *
 * space per animal * environment_friendliness * number of animals
 * note: number of animals factors out
 */
#include <iostream>
#include <sstream>

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::ostringstream output;
  int testCases {};
  std::cin >> testCases;
  while (testCases--) {
    int numberOfFarmers {};
    std::cin >> numberOfFarmers;

    int burden {};
    for (int i {}; i < numberOfFarmers; ++i) {
      int size {}, numberOfAnimals {}, value {};
      std::cin >> size >> numberOfAnimals >> value;

      burden += size * value;
    }
    output << burden << '\n';
  }
  std::cout << output.str();
}
