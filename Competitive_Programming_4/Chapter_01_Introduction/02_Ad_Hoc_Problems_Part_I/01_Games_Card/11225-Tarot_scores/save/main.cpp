/*
 * Problems 11225 - Rarot scores
 */
#include <iostream>
#include <sstream>
#include <cmath>

bool isOulder(const std::string &s)
{
    if (s == "fool" || s == "twenty-one of trumps" ||
            s == "one of trumps") {
        return true;
    }
    return false;
}

double evalCard(const std::string &s)
{
    if (isOulder(s)) {
        return 4.5;
    }
    if (s[0] == 'k' && s[1] == 'i') {
        return 4.5;
    }
    if (s[0] == 'q') {
        return 3.5;
    }
    if (s[0] == 'k' && s[1] == 'n') {
        return 2.5;
    }
    if (s[0] == 'j') {
        return 1.5;
    }
    return 0.5;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::ostringstream output;

    int testCases;
    int test = 0;
    std::cin >> testCases;
    bool first {true};
    while (testCases--) {
        if (first) {
            first = false;
        } else {
            output << '\n';
        }

        double points {0.0};
        int oudlers {0};
        std::string s;
        int handsWon;
        std::cin >> handsWon;
        getline(std::cin, s);
        while (handsWon--) {
            getline(std::cin, s);
            if (isOulder(s)) {
                ++oudlers;
            }
            points += evalCard(s);
        }
        int pointsNeeded = 56;
        if (oudlers == 3) {
            pointsNeeded = 36;
        } else if (oudlers == 2) {
            pointsNeeded = 41;
        } else if (oudlers == 1) {
            pointsNeeded = 51;
        }
        output << "Hand #" << ++ test << '\n';
        if (pointsNeeded <= points) {
            output << "Game won by " << std::ceil(points - pointsNeeded)
                << " point(s).\n";
        } else {
            output << "Game lost by " << std::ceil(pointsNeeded - points)
                << " point(s).\n";
        }
    }
    std::cout << output.str();
}
