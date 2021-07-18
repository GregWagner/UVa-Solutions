#include <iostream>
#include <sstream>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ostringstream output;
    int testCases {};
    std::cin >> testCases;
    while (testCases--) {
        int answer {std::numeric_limits<int>::min()};
        int numberOfStudents {};
        std::cin >> numberOfStudents;
        int currentScore {};
        std::cin >> currentScore;
        int maxScore {currentScore};
        for (int i {1}; i < numberOfStudents; ++i) {
            std::cin >> currentScore;
            answer = std::max(answer, maxScore - currentScore);
            maxScore = std::max(maxScore, currentScore);
        }
        output << answer << '\n';
    }
    std::cout << output.str();
}
