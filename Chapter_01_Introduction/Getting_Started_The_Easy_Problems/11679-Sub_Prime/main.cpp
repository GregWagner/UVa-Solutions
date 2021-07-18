/*
 * 11679 - Sub-prime
 * debtor is -
 * creditor is +
 */
#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int numberOfBanks {}, numberOfDebentures {};
    while (std::cin >> numberOfBanks >> numberOfDebentures && numberOfBanks != 0
            && numberOfDebentures != 0) {
        std::vector<int> banks (numberOfBanks + 1);
        for (int i {1}; i < numberOfBanks + 1; ++i) {
            std::cin >> banks[i];
        }
        for (int i {}; i < numberOfDebentures; ++i) {
            int debtor{}, creditor, value;
            std::cin >> debtor >> creditor >> value;
            banks[debtor] -= value;
            banks[creditor] += value;
        }
        bool negativeBalance {};
        for (int i {1}; i < numberOfBanks + 1; ++i) {
            if (banks[i] < 0) {
                negativeBalance = true;
                break;
            }
        }
        output << (negativeBalance ? "N\n" :"S\n");
    }
    std::cout << output.str();
}
