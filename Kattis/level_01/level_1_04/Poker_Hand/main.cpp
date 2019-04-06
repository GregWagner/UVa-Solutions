/*
 * Poker Hand
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int ace {};
    int two {};
    int three {};
    int four {};
    int five {};
    int six {};
    int seven {};
    int eight {};
    int nine {};
    int ten {};
    int jack {};
    int queen {};
    int king {};

    for (int i {}; i < 5; ++i) {
        std::string card;
        std::cin >> card;
        if (card[0] == 'A') {
            ++ace;
        } else if (card[0] == '2') {
            ++two;
        } else if (card[0] == '3') {
            ++three;
        } else if (card[0] == '4') {
            ++four;
        } else if (card[0] == '5') {
            ++five;
        } else if (card[0] == '6') {
            ++six;
        } else if (card[0] == '7') {
            ++seven;
        } else if (card[0] == '8') {
            ++eight;
        } else if (card[0] == '9') {
            ++nine;
        } else if (card[0] == 'T') {
            ++ten;
        } else if (card[0] == 'J') {
            ++jack;
        } else if (card[0] == 'Q') {
            ++queen;
        } else {
            ++king;
        }
    }
    std::cout << std::max(ace, std::max(two, std::max(three, std::max(four, 
                        std::max(five, std::max(six, std::max(seven, 
                                    std::max(eight, std::max(nine, 
                                            std::max(ten, std::max(jack,
                                                    std::max(queen, king))))))))))))
        <<'\n';
}
