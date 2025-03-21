/*
 * Problem 10315 - Poker Hands
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>

//#define DEBUG
//                      detected    tie breaker returned
// high card            x           x
// Pair                 x           x
// 2 pair
// 3 of a kind          x           x
// straight             x           x
// flush                x
// full house           x           x
// 4 of a kind          x           x
// straight flush       x           x

struct Card {
    char suite;
    char rank;
    int num;

    bool operator<(const Card &rhs) const {
        return num < rhs.num;
    }
    bool operator==(const Card &rhs) const {
        return rank == rhs.rank;
    }
};

int evaluate(char rank) {
    if (rank >= '2' && rank <= '9') {
        return rank - '0';
    }
    if (rank == 'T')    return 10;
    if (rank == 'J')    return 11;
    if (rank == 'Q')    return 12;
    if (rank == 'K')    return 13;
    return 14;
}

void print_cards(const std::vector<Card> &cards) {
    for (int i {}; i < 5; ++i) {
        std::cout << cards[i].rank << cards[i].suite << ' ';
    }
    std::cout << '\n';
}

void setup_deck(std::vector<Card> &cards, std::string &input, int start) {
    for (int i {start}; i < start + 5; ++i) {
        Card card;
        card.rank = input[i * 3 + 0];
        card.suite = input[i * 3 + 1];
        card.num = evaluate(card.rank);
        cards.emplace_back(card);
    }
    std::sort(cards.begin(), cards.end());
}

int high_card(const std::vector<Card> &cards) {
    return cards[cards.size() - 1].num;
}

int pair(const std::vector<Card> &cards) {
    int highestValue {};
    for (size_t i {}; i < cards.size(); ++i) {
        if (std::count(cards.begin(), cards.end(), cards[i]) == 2) {
            highestValue = std::max(highestValue, cards[i].num);
        }
    }
    return highestValue;
}

int two_pairs(std::vector<Card> cards, int &tieBreaker, int &otherCard) {
    int first {};
    int second {};
    int matches {};
    for (size_t i {}; i < cards.size(); ++i) {
//      std::cout << "Card is " << cards[i].rank << cards[i].suite << '\n';
        if (std::count(cards.begin(), cards.end(), cards[i]) == 2) {
            if (first == 0) {
                first = cards[i].num;
            } else if (first != cards[i].num) {
                second = cards[i].num;
            }
            ++matches;
        } else {
            otherCard = cards[i].num;
        }
#ifdef DEBUG
        std::cout << "First: " << first << ", second: " << second
            <<", other: " << otherCard << '\n';
#endif
    }
    int highestValue = std::max(first, second);
    tieBreaker = std::min(first, second);
    return (matches == 4 ? highestValue : 0);
}

int three_of_a_kind(const std::vector<Card> &cards) {
    int highestValue {};
    for (size_t i {}; i < cards.size(); ++i) {
        if (std::count(cards.begin(), cards.end(), cards[i]) == 3) {
            highestValue = std::max(highestValue, cards[i].num);
        }
    }
    return highestValue;
}

int straight(const std::vector<Card> &cards) {
    for (int i {}; i < 4; ++i) {
        if (cards[i + 1].num - cards[i].num != 1) {
            return 0;
        }
    }
    return cards[4].num;
}

int flush(const std::vector<Card> &cards) {
    for (int i {}; i < 4; ++i) {
        if (cards[i + 1].suite != cards[i].suite) {
            return 0;
        }
    }
    return cards[4].num;
}

int full_house(const std::vector<Card> &cards) {
    // a set will only have 2 cards since and 4 of a kind is already checked
    // 2 2 2 4 4 -> 2 4
    std::set<char> setOfCards;
    for (size_t i {}; i < cards.size(); ++i) {
        setOfCards.insert(cards[i].rank);
    }
    return (setOfCards.size() == 2 ? three_of_a_kind(cards) : 0);
}

int four_of_a_kind(const std::vector<Card> &cards) {
    for (size_t i {}; i < cards.size(); ++i) {
        if (std::count(cards.begin(), cards.end(), cards[i]) == 4) {
            return cards[i].num;
        }
    }
    return 0;
}

int straight_flush(const std::vector<Card> &cards) {
    if (straight(cards) && flush(cards)) {
        return cards[4].num;
    }
    return 0;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    for (std::string input; std::getline(std::cin, input);) {

        std::vector<Card> black_hand;
        setup_deck(black_hand, input, 0);

        std::vector<Card> white_hand;
        setup_deck(white_hand, input, 5);

        int black_score = straight_flush(black_hand);
        int white_score = straight_flush(white_hand);
        if (black_score || white_score) {
#ifdef DEBUG
            std::cout << "STRAIGHT FLUSH\n";
            print_cards(black_hand);
            print_cards(white_hand);
            std::cout << "Black score: " << black_score <<
                ", White score: " << white_score << '\n';
#endif
            // this might not be needed here
            int i {4};
            while (i >= 0 && black_score == white_score) {
                black_score = black_hand[i].num;
                white_score = white_hand[i].num;
                i--;
            } 
            if (i >= 0) {
                output << (black_score > white_score ? "Black" : "White")
                    << " wins.\n";
            } else {
                output << "Tie.\n";
            }
        } else {
            black_score = four_of_a_kind(black_hand);
            white_score = four_of_a_kind(white_hand);
            if (black_score || white_score) {
#ifdef DEBUG
                std::cout << "4 OF A KIND\n";
                print_cards(black_hand);
                print_cards(white_hand);
                std::cout << "Black score: " << black_score <<
                    ", White score: " << white_score << '\n';
#endif
                if (black_score == white_score) {
                    output << "Tie.\n";
                } else {
                    output << (black_score > white_score ? "Black" : "White")
                        << " wins.\n";
                }
            } else {
                black_score = full_house(black_hand);
                white_score = full_house(white_hand);
                if (black_score || white_score) {
#ifdef DEBUG
                    std::cout << "FULL HOUSE\n";
                    print_cards(black_hand);
                    print_cards(white_hand);
                    std::cout << "Black score: " << black_score <<
                        ", White score: " << white_score << '\n';
#endif
                    if (black_score == white_score) {
                        output << "Tie.\n";
                    } else {
                        output << (black_score > white_score ? "Black" : "White")
                            << " wins.\n";
                    }
                } else {
                    black_score = flush(black_hand);
                    white_score = flush(white_hand);
                    if (black_score || white_score) {
#ifdef DEBUG
                        std::cout << "FLUSH\n";
                        print_cards(black_hand);
                        print_cards(white_hand);
                        std::cout << "Black score: " << black_score <<
                            ", White score: " << white_score << '\n';
#endif
                        int i {4};
                        while (i >= 0 && black_score == white_score) {
                            black_score = black_hand[i].num;
                            white_score = white_hand[i].num;
                            i--;
                        } 
#ifdef DEBUG
                        std::cout << "Last black: " << black_score
                            << ", white score: " << white_score << '\n';
                        std::cout << "And i is " << i << '\n';
#endif
                        if (black_score == white_score) {
                            output << "Tie.\n";
                        } else {
                            output << (black_score > white_score ? "Black" : "White")
                                << " wins.\n";
                        }
                    } else {
                        black_score = straight(black_hand);
                        white_score = straight(white_hand);
                        if (black_score || white_score) {
#ifdef DEBUG
                            std::cout << "STRAIGHT\n";
                            print_cards(black_hand);
                            print_cards(white_hand);
                            std::cout << "Black score: " << black_score <<
                                ", White score: " << white_score << '\n';
#endif
                            if (black_score == white_score) {
                                output << "Tie.\n";
                            } else {
                                output << (black_score > white_score ? "Black" : "White")
                                    << " wins.\n";
                            }
                        } else {
                            black_score = three_of_a_kind(black_hand);
                            white_score = three_of_a_kind(white_hand);
                            if (black_score || white_score) {
#ifdef DEBUG
                                std::cout << "3 OF A KIND\n";
                                print_cards(black_hand);
                                print_cards(white_hand);
                                std::cout << "Black score: " << black_score <<
                                    ", White score: " << white_score << '\n';
#endif
                                if (black_score == white_score) {
                                    output << "Tie.\n";
                                } else {
                                    output << (black_score > white_score ? "Black" : "White")
                                        << " wins.\n";
                                }
                            } else {
                                int blackTieBreaker {};
                                int blackOther {};
                                int whiteTieBreaker {};
                                int whiteOther {};
                                black_score = two_pairs(black_hand, blackTieBreaker, blackOther);
                                white_score = two_pairs(white_hand, whiteTieBreaker, whiteOther);
                                if (black_score || white_score) {
#ifdef DEBUG
                                    std::cout << "TWO PAIRS\n";
                                    print_cards(black_hand);
                                    print_cards(white_hand);
                                    std::cout << "Black score: " << black_score <<
                                        ", White score: " << white_score << '\n';
                                    std::cout << "Black tiebreaker: " << blackTieBreaker <<
                                        ", White tiebreaker: " << whiteTieBreaker << '\n';
                                    std::cout << "Black other: " << blackOther <<
                                        ", White other: " << whiteOther << '\n';
#endif
                                    if (black_score == white_score) {
                                        if (blackTieBreaker == whiteTieBreaker) {
                                            if (blackOther == whiteOther) {
                                                output << "Tie.\n";
                                            } else {
                                                output << (blackOther > whiteOther ? "Black" : "White")
                                                    << " wins.\n";
                                            }
                                        } else {
                                            output << (blackTieBreaker > whiteTieBreaker ? "Black" : "White")
                                                << " wins.\n";
                                        }
                                    } else {
                                        output << (black_score > white_score ? "Black" : "White")
                                            << " wins.\n";
                                    }
                                } else {
                                    black_score = pair(black_hand);
                                    white_score = pair(white_hand);
                                    if (black_score || white_score) {
#ifdef DEBUG
                                        std::cout << "PAIR\n";
                                        print_cards(black_hand);
                                        print_cards(white_hand);
                                        std::cout << "Black score: " << black_score <<
                                            ", White score: " << white_score << '\n';
#endif
                                        if (black_score == white_score) {
                                            int blackIndex {4};
                                            int whiteIndex {4};
                                            bool done {};
                                            while (!done && blackIndex >= 0 && whiteIndex >= 0) {
                                                while (black_hand[blackIndex].num == black_score) {
                                                    --blackIndex;
                                                    if (blackIndex < 0) {
                                                        break;
                                                    }
                                                }
                                                while (white_hand[whiteIndex].num == white_score) {
                                                    --whiteIndex;
                                                    if (whiteIndex < 0) {
                                                        break;
                                                    }
                                                }
                                                if (blackIndex >= 0 && whiteIndex >= 0) {
#ifdef DEBUG
                                                    std::cout << "Black Index: " << blackIndex 
                                                        << ", White Index: " << whiteIndex << '\n';
                                                    std::cout << "Checking " << black_hand[blackIndex].num 
                                                        << " and " << white_hand[whiteIndex].num << '\n';
#endif
                                                    if (black_hand[blackIndex].num != white_hand[whiteIndex].num) {
                                                        if (black_hand[blackIndex].num > white_hand[whiteIndex].num) {
                                                            output << "Black wins.\n";
                                                        } else {
                                                            output << "White wins.\n";
                                                        }
                                                        done = true;
                                                    }
                                                    --blackIndex;
                                                    --whiteIndex;
                                                }
                                            }
                                            if (!done) {
                                                output << "Tie.\n";
                                            }
                                        } else {
                                            output << (black_score > white_score ? "Black" : "White")
                                                << " wins.\n";
                                        }
                                    } else {
                                        black_score = high_card(black_hand);
                                        white_score = high_card(white_hand);
                                        if (black_score || white_score) {
#ifdef DEBUG
                                            std::cout << "HIGH CARD\n";
                                            print_cards(black_hand);
                                            print_cards(white_hand);
                                            std::cout << "Black score: " << black_score <<
                                                ", White score: " << white_score << '\n';
#endif
                                            int i {4};
                                            while (i >= 0 && black_score == white_score) {
                                                black_score = black_hand[i].num;
                                                white_score = white_hand[i].num;
                                                i--;
                                            } 
                                            if (i >= 0) {
                                                output << (black_score > white_score ? "Black" : "White")
                                                    << " wins.\n";
                                            } else {
                                                output << "Tie.\n";
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << output.str();
}
