#include <iostream>
#include <sstream>
#include <vector>

struct Bumper {
    bool hasBumper{};
    int value{};
    int cost{};
};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int m, n, fixedWallCost, numberOfBumpers;
    std::cin >> m >> n >> fixedWallCost >> numberOfBumpers;

    std::vector<std::vector<int>> grid(m + 1, std::vector<Bumper>(n + 1));

    std::cout << output.str();
}
