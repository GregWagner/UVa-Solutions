/*
 * Problem 10388 - Snap
 */
#include <cstdlib>
#include <deque>
#include <iostream>
#include <string>

struct Player {
    std::deque<char> faceDown;  // front = top
    std::deque<char> faceUp;    // front = top (most recently played)
};

// When the face-down pile is exhausted, the face-up pile is turned over to
// become the face-down pile: its bottom (oldest) card ends up on top.
static void turnOver(Player& p) {
    if (!p.faceDown.empty()) return;
    while (!p.faceUp.empty()) {
        p.faceDown.push_back(p.faceUp.back());
        p.faceUp.pop_back();
    }
}

static bool hasNoCards(const Player& p) {
    return p.faceDown.empty() && p.faceUp.empty();
}

static std::string pileToString(const std::deque<char>& pile) {
    return std::string(pile.begin(), pile.end());
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int testCases{};
    std::cin >> testCases;

    std::string line;
    auto readDeck = [&line]() -> std::string {
        while (std::getline(std::cin, line)) {
            if (!line.empty()) return line;
        }
        return {};
    };

    bool firstCase = true;
    while (testCases--) {
        Player jane, john;
        std::string janesDeck = readDeck();
        std::string johnsDeck = readDeck();
        jane.faceDown.assign(janesDeck.begin(), janesDeck.end());
        john.faceDown.assign(johnsDeck.begin(), johnsDeck.end());

        std::string result;
        bool ended = false;
        int turns{};

        // blank line between consecutive cases
        if (!firstCase) std::cout << '\n';
        firstCase = false;

        while (turns < 1000 && !ended) {
            // a player with no cards at all has lost
            if (hasNoCards(jane)) {
                result = "John wins.";
                ended = true;
                break;
            }
            if (hasNoCards(john)) {
                result = "Jane wins.";
                ended = true;
                break;
            }

            turnOver(jane);
            turnOver(john);

            // both players flip the top card of their face-down pile
            char janesCard = jane.faceDown.front();
            jane.faceDown.pop_front();
            jane.faceUp.push_front(janesCard);

            char johnsCard = john.faceDown.front();
            john.faceDown.pop_front();
            john.faceUp.push_front(johnsCard);

            ++turns;

            if (janesCard == johnsCard) {
                if (std::rand() / 141 % 2 == 0) {  // Jane calls first
                    // Jane takes John's face-up pile and puts it on top of her own
                    john.faceUp.insert(john.faceUp.end(), jane.faceUp.begin(),
                                       jane.faceUp.end());
                    jane.faceUp.swap(john.faceUp);
                    john.faceUp.clear();
                    std::cout << "Snap! for Jane: " << pileToString(jane.faceUp)
                              << '\n';
                    if (hasNoCards(john)) {
                        result = "Jane wins.";
                        ended = true;
                    }
                } else {  // John calls first
                    // John takes Jane's face-up pile and puts it on top of his own
                    jane.faceUp.insert(jane.faceUp.end(), john.faceUp.begin(),
                                       john.faceUp.end());
                    john.faceUp.swap(jane.faceUp);
                    jane.faceUp.clear();
                    std::cout << "Snap! for John: " << pileToString(john.faceUp)
                              << '\n';
                    if (hasNoCards(jane)) {
                        result = "John wins.";
                        ended = true;
                    }
                }
            }
        }

        if (!ended) result = "Keeps going and going ...";
        std::cout << result << '\n';
    }
}