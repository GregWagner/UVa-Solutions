/*
 * Problem 11678 - Cards' Exchange
 */
#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>

void get_cards(int count, std::set<int> &cards) {
    for (int i {}; i < count; ++i) {
        int temp;
        std::cin >> temp;
        cards.insert(temp);
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int aliceCount, bettyCount;
    while ((std::cin >> aliceCount >> bettyCount) && aliceCount && bettyCount) {
        std::set<int> aliceCards;
        std::set<int> bettyCards;
        get_cards(aliceCount, aliceCards);
        get_cards(bettyCount, bettyCards);

        std::vector<int> aliceResults;
        std::set_difference(aliceCards.begin(), aliceCards.end(),
                bettyCards.begin(), bettyCards.end(),
                std::inserter(aliceResults, aliceResults.begin()));
        std::vector<int> bettyResults;
        std::set_difference(bettyCards.begin(), bettyCards.end(),
                aliceCards.begin(), aliceCards.end(),
                std::inserter(bettyResults, bettyResults.begin()));
        output << (aliceResults.size() < bettyResults.size()
                ? aliceResults.size() : bettyResults.size()) << '\n';

    }
    std::cout << output.str();
}
