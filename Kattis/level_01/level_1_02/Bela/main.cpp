/*
 * Bela
 */
#include <iostream>

int rank(const std::string &card, char suit) {
    bool match = card[1] == suit;

    switch (card[0]) {
        case 'T':
            return 10;
        case 'J':
            return (match ? 20 : 2);
        case 'Q':
            return 3;
        case 'K':
            return 4;
        case 'A':
            return 11;
        case '9':
            return (match ? 14 : 0);
        default:
            return 0;
    }

}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int numberOfHands {};
    char suit {};
    std::cin >> numberOfHands >> suit;

    int numberOfCards {numberOfHands * 4};
    int score {};
    for (int i {}; i < numberOfCards; ++i) {
        std::string card {};
        std::cin >> card;
        score += rank(card, suit);
    }
    std::cout << score << '\n';
}
