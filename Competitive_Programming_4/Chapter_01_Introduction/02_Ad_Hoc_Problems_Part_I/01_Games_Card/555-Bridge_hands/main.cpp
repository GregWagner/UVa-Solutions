/*
 * Problem 555 - Bridge Hands
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

struct Card {
    char suite;
    char rank;
};

// first[0] clubs
// first[1] diamonds
// first[2] spades
// first[3] hearts

std::vector<int> first[] {
    std::vector<int> {}, std::vector<int> {},
    std::vector<int> {}, std::vector<int> {} };

std::vector<int> second[] {
    std::vector<int> {}, std::vector<int> {},
    std::vector<int> {}, std::vector<int> {} };

std::vector<int> third[] {
    std::vector<int> {}, std::vector<int> {},
    std::vector<int> {}, std::vector<int> {} };

std::vector<int> fourth[] {
    std::vector<int> {}, std::vector<int> {},
    std::vector<int> {}, std::vector<int> {} };

void sort_cards() {
    for (int i = 0; i < 4; ++i) {
        std::sort(first[i].begin(), first[i].end());
        std::sort(second[i].begin(), second[i].end());
        std::sort(third[i].begin(), third[i].end());
        std::sort(fourth[i].begin(), fourth[i].end());
    }
}

char int_to_rank(int n) {
    if (n <= 9) {
        return n + '0';
    }
    if (n == 10)    return 'T';
    if (n == 11)    return 'J';
    if (n == 12)    return 'Q';
    if (n == 13)    return 'K';
    return 'A';
}

int rank_to_int(char rank) {
    if (rank >= '2' && rank <= '9') {
        return rank - '0';
    }
    if (rank == 'T')    return 10;
    if (rank == 'J')    return 11;
    if (rank == 'Q')    return 12;
    if (rank == 'K')    return 13;
    return 14;
}

void read_cards() {
    for (int i = 0; i < 52; ++i) {
        Card card;
        std::cin >> card.suite;
        std::cin >> card.rank;
        int index = i % 4;
        if (index == 0) {
            if (card.suite == 'C') {
                first[0].push_back(rank_to_int(card.rank));
            } else if (card.suite == 'S') {
                first[2].push_back(rank_to_int(card.rank));
            } else if (card.suite == 'H') {
                first[3].push_back(rank_to_int(card.rank));
            } else {
                first[1].push_back(rank_to_int(card.rank));
            }
        } else if (index == 1) {
            if (card.suite == 'C') {
                second[0].push_back(rank_to_int(card.rank));
            } else if (card.suite == 'S') {
                second[2].push_back(rank_to_int(card.rank));
            } else if (card.suite == 'H') {
                second[3].push_back(rank_to_int(card.rank));
            } else {
                second[1].push_back(rank_to_int(card.rank));
            }
        } else if (index == 2) {
            if (card.suite == 'C') {
                third[0].push_back(rank_to_int(card.rank));
            } else if (card.suite == 'S') {
                third[2].push_back(rank_to_int(card.rank));
            } else if (card.suite == 'H') {
                third[3].push_back(rank_to_int(card.rank));
            } else {
                third[1].push_back(rank_to_int(card.rank));
            }
        } else if (index == 3) {
            if (card.suite == 'C') {
                fourth[0].push_back(rank_to_int(card.rank));
            } else if (card.suite == 'S') {
                fourth[2].push_back(rank_to_int(card.rank));
            } else if (card.suite == 'H') {
                fourth[3].push_back(rank_to_int(card.rank));
            } else {
                fourth[1].push_back(rank_to_int(card.rank));
            }
        }
    }
}

void clear_vectors() {
    for (int i {}; i < 4; ++i) {
        first[i].clear();
        second[i].clear();
        third[i].clear();
        fourth[i].clear();
    }
}

std::string s = "CDSH";

void print_first(std::ostringstream &output) {
    for (int i {}; i < 4; ++i) {
        for (size_t j {}; j < first[i].size(); ++j) {
            output << ' ' << s[i] << int_to_rank(first[i][j]);
        }
    }
    output << '\n';
}

void print_second(std::ostringstream &output) {
    for (int i {}; i < 4; ++i) {
        for (size_t j {}; j < second[i].size(); ++j) {
            output << ' ' << s[i] << int_to_rank(second[i][j]);
        }
    }
    output << '\n';
}

void print_third(std::ostringstream &output) {
    for (int i {}; i < 4; ++i) {
        for (size_t j {}; j < third[i].size(); ++j) {
            output << ' ' << s[i] << int_to_rank(third[i][j]);
        }
    }
    output << '\n';
}

void print_fourth(std::ostringstream &output) {
    for (int i {}; i < 4; ++i) {
        for (size_t j {}; j < fourth[i].size(); ++j) {
            output << ' ' << s[i] << int_to_rank(fourth[i][j]);
        }
    }
    output << '\n';
}

void print_results(std::ostringstream &output, char dealer) {
    std::string order = "SWNE";
    if (dealer == 'S') {
        output << "S:";
        print_fourth(output);
        output << "W:";
        print_first(output);
        output << "N:";
        print_second(output);
        output << "E:";
        print_third(output);
    } else if (dealer == 'W') {
        output << "S:";
        print_third(output);
        output << "W:";
        print_fourth(output);
        output << "N:";
        print_first(output);
        output << "E:";
        print_second(output);
    } else if (dealer == 'N') {
        output << "S:";
        print_second(output);
        output << "W:";
        print_third(output);
        output << "N:";
        print_fourth(output);
        output << "E:";
        print_first(output);
    } else if (dealer == 'E') {
        output << "S:";
        print_first(output);
        output << "W:";
        print_second(output);
        output << "N:";
        print_third(output);
        output << "E:";
        print_fourth(output);
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    
    for (char dealer; std::cin >> dealer;) {
        if (dealer == '#') {
            break;
        }
        read_cards();
        sort_cards();
        print_results(output, dealer);

        clear_vectors();
    }
    std::cout << output.str();
}
