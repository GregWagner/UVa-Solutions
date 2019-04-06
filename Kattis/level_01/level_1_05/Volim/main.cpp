/*
 * Volim
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int player, numberOfQuestions;
    int time = 210;
    std::cin >> player >> numberOfQuestions;
    while (numberOfQuestions--) {
        int answerTime;
        char answer;
        std::cin >> answerTime >> answer;
        time -= answerTime;
        if (time <= 0) {
            break;
        }
        if (answer == 'T') {
            ++player;
        }
    }
    player %= 8;
    player = (player == 0 ? 8 : player);
    std::cout << player << '\n';
}
