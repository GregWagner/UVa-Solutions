/*
 * Problem 162 - Beggar My Neighbour
 */
#include <iostream>
#include <sstream>
#include <iomanip>
#include <deque>
#include <sstream>

std::ostringstream output;

std::deque<char> dealer_hand;
std::deque<char> player_hand;
std::deque<char> pile;

bool deal_cards() {
    bool dealer_turn {};        // player gets first card
    for (int i = 0; i < 52; ++i) {
        std::string card;
        std::cin >> card;
        if (card == "#") {
            return false;
        }
        (dealer_turn ? dealer_hand.push_front(card[1])
                     : player_hand.push_front(card[1]));
        dealer_turn = !dealer_turn;
    }
    return true;
}

bool face_card(char card) {
    return card == 'A' || card == 'J' || card == 'Q' || card == 'K';
}

int penelty(char card) {
    if (card == 'J')    return 1;
    if (card == 'Q')    return 2;
    if (card == 'K')    return 3;
    return 4;
}

void move_pile_to(bool player) {
    for (char val : pile) {
        (player ? dealer_hand.push_back(val) : player_hand.push_back(val));
    }
    pile.clear();
}

void play_game() {
    bool dealer_turn {};        // player starts
    int cards_to_deal {1};
    bool face_found {};
    bool face_card_by {};
    bool done {};

    while (true) {
        if (done) {
            if (player_hand.size() == 0) {
                output << "1" << std::setw(3) << dealer_hand.size() << '\n';
            } else if (dealer_hand.size() == 0) {
                output << "2" << std::setw(3) << player_hand.size() << '\n';
            }
            return;
        }

        if (dealer_turn) {
            while (cards_to_deal) {
                if (dealer_hand.empty()) {
                    done = true;
                    break;
                }
                char dealer_card = dealer_hand.front();
                pile.push_back(dealer_card);
                dealer_hand.erase(dealer_hand.begin());
                --cards_to_deal;
                if (face_card(dealer_card)) {
                    face_found = true;
                    face_card_by = true;
                    cards_to_deal = penelty(dealer_card);
                    dealer_turn = false;
                    break;
                }
                dealer_turn = false;
            }
            if (!cards_to_deal) {
                cards_to_deal = 1;
                if (face_found) {
                    move_pile_to(face_card_by);
                    face_found = false;
                    dealer_turn = face_card_by;
                } else {
                    dealer_turn = false;
                }
            }
        } else {
            while (cards_to_deal) {
                if (player_hand.empty()) {
                    done = true;
                    break;
                }
                char player_card = player_hand.front();
                pile.push_back(player_card);
                player_hand.erase(player_hand.begin());
                --cards_to_deal;
                if (face_card(player_card)) {
                    face_found = true;
                    face_card_by = false;
                    cards_to_deal = penelty(player_card);
                    dealer_turn = true;
                    break;
                }
                dealer_turn = true;
            }
            if (!cards_to_deal) {
                cards_to_deal = 1;
                if (face_found) {
                    move_pile_to(face_card_by);
                    face_found = false;
                    dealer_turn = face_card_by;
                } else {
                    dealer_turn = true;
                }
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    while (deal_cards()) {
        play_game();
        player_hand.clear();
        dealer_hand.clear();
        pile.clear();
    }
    std::cout << output.str();
}
