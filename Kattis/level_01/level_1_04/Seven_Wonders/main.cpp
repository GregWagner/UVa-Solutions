/*
 * Seven Wonders
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int tablet {};
    int compass {};
    int gear {};

    std::string input;
    std::cin >> input;
    for (auto c : input) {
        if (c == 'T') {
            ++tablet;
        } else if (c == 'C') {
            ++compass;
        } else if (c == 'G') {
            ++gear;
        }
    }
    int score = tablet * tablet + compass * compass + gear * gear;
    int m = std::min(tablet, std::min(compass, gear));
    score += 7 * m;
    std::cout << score << '\n';
}
