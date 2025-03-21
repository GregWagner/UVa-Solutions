#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ostringstream output;
    int testCases {};
    int testCase {};
    std::cin >> testCases;
    while (testCases--) {
        output << "Case " << ++testCase << ": ";
        int games {};
        int consectutiveCount {};
        bool fired {};
        int gamesPlayed{};
        std::cin >> gamesPlayed;
        for (int i {}; i < gamesPlayed; ++i) {
            char score;
            std::cin >> score;
            if (!fired) {
                if (score == 'W') {
                    ++games;
                    consectutiveCount = 0;
                } else {
                    ++consectutiveCount;
                    ++games;
                    if (consectutiveCount >= 3) {
                        fired = true;
                    }
                }
            }
        }
        if (!fired) {
            output << "Yay! Mighty Rafa persists!\n";
        } else {
            output << games << '\n';
        }
    }
    std::cout << output.str();
}
