/*
 * Problem 10315 - Poker Hands
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

enum Hand {
    NONE, PAIR, TWO_PAIR, THREE_OF_A_KIND, STRAIGHT, FLUSH, FULL_HOUSE,
    FOUR_OF_A_KIND, STRAIGHT_FLUSH
};

std::vector<int> blackTieBreaker;
std::vector<int> whiteTieBreaker;

std::vector<int> temp;

class Card {
    public:
        char suite;
        char value;
        int num;

        bool operator<(const Card &rhs) const {
            return num < rhs.num;
        }
};

int charToInt(char c) {
    if (c == '2') return 2;
    if (c == '3') return 3;
    if (c == '4') return 4;
    if (c == '5') return 5;
    if (c == '6') return 6;
    if (c == '7') return 7;
    if (c == '8') return 8;
    if (c == '9') return 9;
    if (c == 'T') return 10;
    if (c == 'J') return 11;
    if (c == 'Q') return 12;
    if (c == 'K') return 13;
    return 14;
}

std::vector<Card> blackHand;
std::vector<Card> whiteHand;

Card evalCard(std::string s) {
    Card card;
    card.suite = s[1];
    card.value = s[0];
    card.num = charToInt(s[0]);
    return card;
}

// note return PAIR if there is at least one pair
Hand isPair(const std::vector<Card> &hand, std::vector<int> &tie) {
    tie.clear();
    for (unsigned i = 0; i < hand.size(); ++i) {
        int count {1};
        int n = hand[i].num;
        for (unsigned j = 0; j < hand.size(); ++j) {
            if (i != j) {
                if (hand[j].num == n) {
                    ++count;
                    if (count == 2) {
                        tie.push_back(n);
                        for (unsigned k = hand.size(); k > 0; --k) {
                            if (hand[k - 1].num != n) {
                                tie.push_back(hand[k - 1].num);
                            }
                        }
                        return Hand::PAIR;
                    }
                }
            }
        }
    }
    return Hand::NONE;
}

void removePair(std::vector<Card> &hand) {
    for (unsigned i = 0; i < hand.size(); ++i) {
        int count {1};
        int n = hand[i].num;
        for (unsigned j = 0; j < hand.size(); ++j) {
            if (i != j) {
                if (hand[j].num == n) {
                    ++count;
                    if (count == 2) {
                        for (auto k = hand.begin(); k < hand.end(); ++k) {
                            if (k->num == n) {
                                --count;
                                hand.erase(k);
                                k = hand.begin();
                            }
                            if (count == 0) {
                                return;
                            }
                        }
                        return;
                    }
                }
            }
        }
    }
}

Hand isTwoPairs(const std::vector<Card> &hand, std::vector<int> &tie) {
    tie.clear();
    int onePair = 0, twoPair = 0;
    std::vector<Card> copyOfHand;
    for (unsigned i = 0; i < hand.size(); ++i) {
        copyOfHand.push_back(hand[i]);
    }

    if (isPair(hand, temp) == Hand::PAIR) {
        onePair = temp[0];
        removePair(copyOfHand);
        temp.clear();
        Hand rc = isPair(copyOfHand, temp);
        twoPair = temp[0];
        if (rc == Hand::PAIR) {
            tie.push_back(std::max(onePair, twoPair));
            tie.push_back(std::min(onePair, twoPair));
            for (unsigned i = 0; i < hand.size(); ++i) {
                if (hand[i].num != onePair && hand[i].num != twoPair) {
                    tie.push_back(hand[i].num);
                }
            }
            return Hand::TWO_PAIR;
        } 
    }
    return Hand::NONE;
}

void removeThree(std::vector<Card> &hand, std::vector<int> &tie) {
    tie.size();
    for (unsigned i = 0; i < hand.size(); ++i) {
        int count {1};
        int n = hand[i].num;
        for (unsigned j = 0; j < hand.size(); ++j) {
            if (i != j) {
                if (hand[j].num == n) {
                    ++count;
                    if (count == 3) {
                        for (auto k = hand.begin(); k < hand.end(); ++k) {
                            if (k->num == n) {
                                --count;
                                hand.erase(k);
                                k = hand.begin();
                            }
                            if (count == 0) {
                                return;
                            }
                        }
                        return;
                    }
                }
            }
        }
    }
}

int highCard(const std::vector<Card> &hand, std::vector<int> &tie) {
    for (unsigned k = hand.size() - 1; k > 0; --k) {
        tie.push_back(hand[k].num);
    }
    return (hand[hand.size() - 1].num);
}

Hand isThreeOfAKind(const std::vector<Card> &hand, std::vector<int> &tie) {
    int card {0};
    tie.clear();
    int max {0};
    for (unsigned i = 0; i < hand.size(); ++i) {
        int count {1};
        int n = hand[i].num;
        for (unsigned j = 0; j < hand.size(); ++j) {
            if (i != j) {
                if (hand[j].num == n) {
                    ++count;
                    if (count == 3) {
                        card = n;
                    }
                }
            }
        }
        if (count > max) {
            max = count;
        }
    }
    if (max == 3) {
        tie.push_back(card);
        for (unsigned k = hand.size(); k > 0; --k) {
            if (hand[k - 1].num != card) {
                tie.push_back(hand[k - 1].num);
            }
        }
        return Hand::THREE_OF_A_KIND;
    }
    return Hand::NONE;
}

Hand isStraight(const std::vector<Card> &hand, std::vector<int> &tie) {
    tie.clear();
    int n = hand[0].num;
    for (unsigned i = 1; i < hand.size(); ++i) {
        if (hand[i].num != ++n) {
            return Hand::NONE;
        }
    }
    tie.push_back(highCard(hand, temp));
    return Hand::STRAIGHT;
}

Hand isFlush(const std::vector<Card> &hand, std::vector<int> &tie) {
    tie.clear();
    char suite = hand[0].suite;
    for (unsigned i = 1; i < hand.size(); ++i) {
        if (hand[i].suite != suite) {
            return Hand::NONE;
        }
    }
    for (unsigned k = hand.size(); k > 0; --k) {
        tie.push_back(hand[k - 1].num);
    }
    return Hand::FLUSH;
}

Hand isFullHouse(const std::vector<Card> &hand, std::vector<int> &tie) {
    tie.clear();
    std::vector<Card> copyOfHand;
    for (unsigned i = 0; i < hand.size(); ++i) {
        copyOfHand.push_back(hand[i]);
    }

    if (isThreeOfAKind(hand, temp) == Hand::THREE_OF_A_KIND) {
        tie.push_back(temp[0]);
        removeThree(copyOfHand, temp);
        Hand rc = isPair(copyOfHand, temp);
        if (rc == Hand::PAIR) {
            tie.push_back(temp[0]);
            return Hand::FULL_HOUSE;
        }
    }
    return Hand::NONE;
}

Hand isFourOfAKind(const std::vector<Card> &hand, std::vector<int> &tie) {
    tie.clear();
    int card;
    int max {0};
    for (unsigned i = 0; i < hand.size(); ++i) {
        int count {1};
        int n = hand[i].num;
        for (unsigned j = 0; j < hand.size(); ++j) {
            if (i != j) {
                if (hand[j].num == n) {
                    ++count;
                }
            }
        }
        if (count > max) {
            card = n;
            max = count;
        }
    }
    if (max == 4) {
        tie.push_back(card);
        for (unsigned i = 0; i < hand.size(); ++i) {
            if (hand[i].num != card) {
                tie.push_back(hand[i].num);
            }
        }
        return Hand::FOUR_OF_A_KIND;
    }
    return Hand::NONE;
}

Hand isStraightFlush(const std::vector<Card> &hand, std::vector<int> &tie) {
    tie.push_back(highCard(hand, temp));
    return (isStraight(hand, temp) == Hand::STRAIGHT &&
            isFlush(hand, temp) == Hand::FLUSH)
        ?  Hand::STRAIGHT_FLUSH : Hand::NONE;
}

Hand evalHand(const std::vector<Card> &hand, std::vector<int> &tie) {
    if (isStraightFlush(hand, tie) == Hand::STRAIGHT_FLUSH) {
        return Hand::STRAIGHT_FLUSH;
    }
    if (isFourOfAKind(hand, tie) == Hand::FOUR_OF_A_KIND) {
        return Hand::FOUR_OF_A_KIND;
    }
    if (isFullHouse(hand, tie) == Hand::FULL_HOUSE) {
        return Hand::FULL_HOUSE;
    }
    if (isFlush(hand, tie) == Hand::FLUSH) {
        return Hand::FLUSH;
    }
    if (isStraight(hand, tie) == Hand::STRAIGHT) {
        return Hand::STRAIGHT;
    }
    if (isThreeOfAKind(hand, tie) == Hand::THREE_OF_A_KIND) {
        return Hand::THREE_OF_A_KIND;
    }
    if (isTwoPairs(hand, tie) == Hand::TWO_PAIR) {
        return Hand::TWO_PAIR;
    }
    if (isPair(hand, tie) == Hand::PAIR) {
        return Hand::PAIR;
    }
    highCard(hand, tie);
    return Hand::NONE;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::ostringstream output;

    std::string in;
    while (std::cin >> in) {
        blackHand.clear();
        whiteHand.clear();
        blackTieBreaker.clear();
        whiteTieBreaker.clear();

        Card card = evalCard(in);
        blackHand.push_back(card);
        for (int i = 1; i < 5; ++i) {
            std::cin >> in;
            card = evalCard(in);
            blackHand.push_back(card);
        }

        for (int i = 1; i <= 5; ++i) {
            std::cin >> in;
            card = evalCard(in);
            whiteHand.push_back(card);
        }

        std::sort(blackHand.begin(), blackHand.end());
        std::sort(whiteHand.begin(), whiteHand.end());

        Hand black = evalHand(blackHand, blackTieBreaker);
        Hand white = evalHand(whiteHand, whiteTieBreaker);

        if (black > white) {
            output << "Black wins.\n";
        } else if (white > black) {
            output << "White wins.\n";
        } else {
            bool done {false};
            int blackTie, whiteTie;
            while (!done) {
                if ((blackTieBreaker.size() == 0) &&
                        (whiteTieBreaker.size() == 0)) {
                    done = true;
                    output << "Tie.\n";
                } else {
                    if (blackTieBreaker.size() > 0) {
                        blackTie = blackTieBreaker[0];
                        blackTieBreaker.erase(blackTieBreaker.begin());
                    }
                    if (whiteTieBreaker.size() > 0) {
                        whiteTie = whiteTieBreaker[0];
                        whiteTieBreaker.erase(whiteTieBreaker.begin());
                    }
                    if (blackTie > whiteTie) {
                        done = true;
                        output << "Black wins.\n";
                    } else if (blackTie < whiteTie) {
                        done = true;
                        output << "White wins.\n";
                    }
                }
            }
        }

    }
    std::cout << output.str();
}
