#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int windSpeed, numOfRoads;
  std::cin >> windSpeed >> numOfRoads;

  for (int i = 0; i < numOfRoads; ++i) {
    std::string roadName;
    int roadSpeed;
    std::cin >> roadName >> roadSpeed;

    std::cout << roadName
      << (roadSpeed < windSpeed ? " lokud\n" : " opin\n");
  }
}