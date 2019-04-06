/*
 * Problem 10205 - Stack 'esm up
 */
#include <iostream>
#include <sstream>

std::string cards[] = {
    "DONT USE ME",
    "2 of Clubs", "3 of Clubs", "4 of Clubs", "5 of Clubs", "6 of Clubs",
    "7 of Clubs", "8 of Clubs", "9 of Clubs", "10 of Clubs", "Jack of Clubs",
    "Queen of Clubs", "King of Clubs", "Ace of Clubs", "2 of Diamonds",
    "3 of Diamonds", "4 of Diamonds", "5 of Diamonds", "6 of Diamonds",
    "7 of Diamonds", "8 of Diamonds", "9 of Diamonds", "10 of Diamonds",
    "Jack of Diamonds", "Queen of Diamonds", "King of Diamonds",
    "Ace of Diamonds", "2 of Hearts", "3 of Hearts", "4 of Hearts",
    "5 of Hearts", "6 of Hearts", "7 of Hearts", "8 of Hearts", "9 of Hearts",
    "10 of Hearts", "Jack of Hearts", "Queen of Hearts", "King of Hearts",
    "Ace of Hearts", "2 of Spades", "3 of Spades", "4 of Spades", "5 of Spades",
    "6 of Spades", "7 of Spades", "8 of Spades", "9 of Spades", "10 of Spades",
    "Jack of Spades", "Queen of Spades", "King of Spades", "Ace of Spades"
};

int deck[53];
int new_deck[53];
int deals[100][53];

void initialize_deck() {
    for (int i {}; i < 53; ++i) {
        deck[i] = i;
    }
}

void deal_cards(int index) {
    for (int i {}; i < 52; ++i) {
        int move = deals[index][i];
        new_deck[i + 1] = deck[move];
    }
    for (int i {}; i <= 52; ++i) {
        deck[i] = new_deck[i];
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    bool first = true;

    int testCases; 
    std::cin >> testCases;
    while (testCases--) {
        initialize_deck();
        int n;
        std::cin >> n;
        for (int i {1}; i <= n; ++i) {
            for (int j {}; j < 52; ++j) {
                int move;
                std::cin >> move;
                deals[i][j] = move;
            }
        }

        std::string s;
        getline(std::cin, s);
        getline(std::cin, s);
        while (s != "") {
            int index = std::atoi(s.c_str());
            deal_cards(index);
            getline(std::cin, s);
        }

        if (first) {
            first = false;
        } else {
            output << '\n';
        }
        for (int i {1}; i < 53; ++i) {
            output << cards[deck[i]] << '\n';
        }
    }
    std::cout << output.str();
}
