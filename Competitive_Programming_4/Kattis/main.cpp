#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int arnarRoundsWon{}, hannesRoundsWon{};
    int arnarGamesWon{}, hannesGamesWon{};

    int n;
    std::string input;
    std::cin >> n >> input;

    for (auto c : input) {
        if (c == 'A') {
            ++arnarRoundsWon;
            if (arnarRoundsWon == 3) {
                arnarRoundsWon = 0;
                hannesRoundsWon = 0;
                ++arnarGamesWon;
                if (arnarGamesWon == n) {
                    std::cout << "Hannes\n";
                    return 0;
                }
            }
        } else if (c == 'H') {
            ++hannesRoundsWon;
            if (hannesRoundsWon == 3) {
                arnarRoundsWon = 0;
                hannesRoundsWon = 0;
                ++hannesGamesWon;
                if (hannesGamesWon == n) {
                    std::cout << "Arnar\n";
                    return 0;
                }
            }
        }
    }
}
