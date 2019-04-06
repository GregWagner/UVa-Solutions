/*
 * Provinces and Gold
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;

    int gold, silver, copper;
    std::cin >> gold >> silver >> copper;
    int buyingPower = (gold * 3) + (silver * 2) + copper;
    if (buyingPower >= 8) {
        output << "Province or ";
    } else if (buyingPower >= 5) {
        output << "Duchy or ";
    } else if (buyingPower >= 2) {
        output << "Estate or ";
    }

    if (buyingPower >= 6) {
        output << "Gold";
    } else if (buyingPower >= 3) {
        output << "Silver";
    } else {
        output << "Copper";
    }
    std::cout << output.str() << '\n';
}
