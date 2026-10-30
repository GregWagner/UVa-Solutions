// 170 - Clock Patience
#include <cctype>
#include <iomanip>
#include <iostream>
#include <vector>

auto getPileIndex(const std::string& card) -> int {
    char rank{card[0]};
    if (isdigit(rank)) {
        return (rank - '0') - 1; // '1' is index 0, '9' is index 8
    }
    switch (rank) {
    case 'A':
        return 0; // Ace -> 1 o'clock (index 0)
    case 'T':
        return 9; // 10 -> 10 o'clock (index 9)
    case 'J':
        return 10; // Jack -> 11 o'clock (index 10)
    case 'Q':
        return 11; // Queen -> 12 o'clock (index 11)
    case 'K':
        return 12; // King -> Center (index 12)
    }
    return 0;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string card;
    while (std::cin >> card && card != "#") {
        std::vector<std::vector<std::string>> piles(13);

        // note first card read is last card dealt
        std::vector<std::string> deck(52);
        deck[51] = card;
        for (int i{50}; i >= 0; --i) {
            std::cin >> deck[i];
        }

        // deal
        for (int i{0}; i < 52; ++i) {
            piles[i % 13].push_back(deck[i]);
        }

        int currentPile{12};
        int exposedCount{};
        std::string lastCard{};

        // play until target pile is empty
        while (!piles[currentPile].empty()) {
            ++exposedCount;
            lastCard = piles[currentPile].back();
            piles[currentPile].pop_back();

            currentPile = getPileIndex(lastCard);
        }
        std::cout << std::setw(2) << std::setfill('0') << exposedCount << ',' << lastCard
                  << '\n';
    }
}
