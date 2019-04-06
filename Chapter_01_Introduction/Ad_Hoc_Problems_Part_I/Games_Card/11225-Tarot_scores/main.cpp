/*
 * Problems 11225 - Rarot scores
 */
#include <iostream>
#include <sstream>

std::string oudlers[] {"fool", "one of trumps", "twenty-one of trumps",
    "ignore me"};

int get_score(int numberOfOudlers) {
    switch (numberOfOudlers) {
        case 3:     return 36;
        case 2:     return 41;
        case 1:     return 51;
        default:    return 56;
    }
}

int count_oudlers(const std::string &card) {
    int numberOfOudlers {};
    for (int j {}; j < 3; ++j) {
        if (card == oudlers[j]) {
            ++numberOfOudlers;
        }
    }
    return numberOfOudlers;
}

std::string kings[] {"king of diamonds", "king of hearts",
    "king of spades", "king of clubs"};
std::string queens[] {"queen of diamonds", "queen of hearts",
    "queen of spades", "queen of clubs"};
std::string knights[] {"knight of diamonds", "knight of hearts",
    "knight of spades", "knight of clubs"};
std::string jacks[] {"jack of diamonds", "jack of hearts",
    "jack of spades", "jack of clubs"};

double score_card(const std::string &card) {
    for (int j {}; j < 4; ++j) {
        if (card == oudlers[j])     return 4.5;
        if (card == kings[j])       return 4.5;
        if (card == queens[j])      return 3.5;
        if (card == knights[j])     return 2.5;
        if (card == jacks[j])       return 1.5;
    }
    return 0.5;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    bool first {true};

    int test {};
    std::ostringstream output;
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        if (first) {
            first = false;
        } else {
            output << '\n';
        }
        int numberOfOudlers {};
        double score {};
        int numberOfCards;
        std::cin >> numberOfCards;
        std::string input;
        std::getline(std::cin, input);
        for (int i {}; i < numberOfCards; ++i) {
            std::getline(std::cin, input);
            numberOfOudlers += count_oudlers(input);
            score -= score_card(input);
        }
        score += get_score(numberOfOudlers);
        output << "Hand #" << ++test << "\nGame "
            << (score <= 0 ? "won" : "lost")
            << " by " << (score >= 0 ? score : -score) << " point(s).\n";
    }
    std::cout << output.str();
}
