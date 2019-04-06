/*
 * ACM COntest Scoring
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    bool correct[26] {};
    int time[26] {};
    int correctCount {};

    int currentTime;
    while (true) {
        std::cin >> currentTime;
        if (currentTime == -1) {
            break;
        }
        char p;
        std::string results;
        std::cin >> p >> results;
        int problem = p - 'A';
        if (!correct[problem]) {
            if (results == "right") {
                ++correctCount;
                correct[problem] = true;
                time[problem] += currentTime;
            } else {
                time[problem] += 20;
            }
        }
    }

    int score {};
    for (int i {}; i < 26; ++i) {
        if (correct[i]) {
            score += time[i];
        }
    }
    std::cout << correctCount << ' ' << score << '\n';
}
