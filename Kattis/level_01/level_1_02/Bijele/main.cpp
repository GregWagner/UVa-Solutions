/*
 * Bijele
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int kings, queens, rooks, bishops, knights, pawns;
    std::cin >> kings >> queens >> rooks >> bishops >> knights >> pawns;

    std::cout << 1 - kings << ' ' << 1 - queens << ' ' << 2 - rooks << ' '
        << 2 - bishops << ' ' << 2 - knights << ' ' << 8 - pawns << '\n';
}
