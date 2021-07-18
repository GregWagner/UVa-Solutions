/*
 * 10055 Hashmat the brace warrior
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    long long  hashmatArmySize {};
    while (std::cin >> hashmatArmySize) {
        long long  oppoentArmySize {};
        std::cin >> oppoentArmySize;
        output << std::abs(oppoentArmySize - hashmatArmySize) << '\n';
    }
    std::cout << output.str();
}
