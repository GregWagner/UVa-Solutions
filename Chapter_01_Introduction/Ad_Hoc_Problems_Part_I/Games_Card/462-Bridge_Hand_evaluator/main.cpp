/*
 * Problem 462 - Bridge Hand Evaluator
 */
#include <iostream>
#include <sstream>
#include <vector>

struct HasRank {
    bool hasAce[4] {};
    bool hasJack[4] {};
    bool hasQueen[4] {};
    bool hasKing[4] {};
    bool stopped[4] {};
    int counts[4] {};
};

struct Card {
    char suite;
    char rank;
};

std::vector<Card> cards;

bool read_cards() {
    std::string input;
    if (std::getline(std::cin, input)) {
        for (int i = 0; i < 13; ++i) {
            Card card;
            card.rank = input[3 * i];
            card.suite = input[3 * i + 1];
            cards.push_back(card);
        }
        return true;
    }
    return false;
}

int step_one(HasRank &ranks) {
    int score {};
    for (auto c : cards) {
        if (c.rank == 'A')  {
            if (c.suite == 'C') {
                ranks.hasAce[0] = true;
                ranks.stopped[0] = true;
            } else if (c.suite == 'S') {
                ranks.hasAce[1] = true;
                ranks.stopped[1] = true;
            } else if (c.suite == 'H') {
                ranks.hasAce[2] = true;
                ranks.stopped[2] = true;
            } else if (c.suite == 'D') {
                ranks.hasAce[3] = true;
                ranks.stopped[3] = true;
            }
            score += 4;
        } else if (c.rank == 'K') {
            if (c.suite == 'C') {
                ranks.hasKing[0] = true;
            } else if (c.suite == 'S') {
                ranks.hasKing[1] = true;
            } else if (c.suite == 'H') {
                ranks.hasKing[2] = true;
            } else if (c.suite == 'D') {
                ranks.hasKing[3] = true;
            }
            score += 3;
        } else if (c.rank == 'Q') {
            if (c.suite == 'C') {
                ranks.hasQueen[0] = true;
            } else if (c.suite == 'S') {
                ranks.hasQueen[1] = true;
            } else if (c.suite == 'H') {
                ranks.hasQueen[2] = true;
            } else if (c.suite == 'D') {
                ranks.hasQueen[3] = true;
            }
            score += 2;
        } else if (c.rank == 'J') {
            if (c.suite == 'C') {
                ranks.hasJack[0] = true;
            } else if (c.suite == 'S') {
                ranks.hasJack[1] = true;
            } else if (c.suite == 'H') {
                ranks.hasJack[2] = true;
            } else if (c.suite == 'D') {
                ranks.hasJack[3] = true;
            }
            score += 1;
        }
    }
    return score;
}

void count_suite(HasRank &ranks) {
    for (auto c : cards) {
        if (c.suite == 'C') {
            ++ranks.counts[0];
        } else if (c.suite == 'S') {
            ++ranks.counts[1];
        } else if (c.suite == 'H') {
            ++ranks.counts[2];
        } else if (c.suite == 'D') {
            ++ranks.counts[3];
        }
    }
}

int step_two(HasRank &ranks) {
    int score {};
    for (int i = 0; i < 4; ++i) {
        if (ranks.hasKing[i]) {
            if (ranks.counts[i] == 1) {
                score -= 1;
            } else if (ranks.counts[i] >= 2) {
                ranks.stopped[i] = true;
            }
        } 
    }
    return score;
}

int step_three(HasRank &ranks) {
    int score {};
    for (int i = 0; i < 4; ++i) {
        if (ranks.hasQueen[i]) {
            if (ranks.counts[i] <= 2) {
                score -= 1;
            } else if (ranks.counts[i] >= 3) {
                ranks.stopped[i] = true;
            }
        } 
    }
    return score;
}

int step_four(const HasRank &ranks) {
    int score {};
    for (int i = 0; i < 4; ++i) {
        if ((ranks.hasJack[i])  && (ranks.counts[i] <= 3)) {
            --score;
        } 
    }
    return score;
}

int step_five(const HasRank &ranks) {
    int score {};
    for (int i = 0; i < 4; ++i) {
        if (ranks.counts[i] == 2) {
            ++score;
        } else if ((ranks.counts[i] == 1) || (ranks.counts[i] == 0)) {
            score += 2;
        }
    }
    return score;
}

char largest_suite(const HasRank &ranks) {
    char ch = 'C';
    int max = std::max(ranks.counts[1], std::max(ranks.counts[2],
                std::max(ranks.counts[3], ranks.counts[0])));
    if (max == ranks.counts[1]) {
        ch = 'S';
    } else if (max == ranks.counts[2]) {
        ch = 'H';
    } else if (max == ranks.counts[3]) {
        ch = 'D';
    }
    return ch;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;

    while (read_cards()) {
        HasRank ranks;
        count_suite(ranks);

        int score = step_one(ranks);
        score += step_two(ranks);
        score += step_three(ranks);
        score += step_four(ranks);
        int noTrumpScore = score;
        score += step_five(ranks);

        if (score < 14) {
            output << "PASS\n";
        } else if (noTrumpScore >= 16 && 
                    ranks.stopped[0] && ranks.stopped[1] && 
                    ranks.stopped[2] && ranks.stopped[3]) {
                output << "BID NO-TRUMP\n";
        } else {
            output << "BID " << largest_suite(ranks) << "\n";
        }
        cards.clear();
    }
    std::cout << output.str();
}
