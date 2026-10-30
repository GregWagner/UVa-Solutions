#include <iostream>
#include <sstream>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    int numberOfSoliders, numberOfLossReports;
    while (std::cin >> numberOfSoliders >> numberOfLossReports) {
        if (numberOfSoliders == 0 && numberOfLossReports == 0) {
            break;
        }
        std::vector<int> leftBuddy(numberOfSoliders + 2);
        std::vector<int> rightBuddy(numberOfSoliders + 2);
        std::vector<char> alive(numberOfSoliders + 2, 0);

        // initialize buddy vectors 1-based
        for (int i{}; i < numberOfSoliders; ++i) {
            int idx = i + 1;
            leftBuddy[idx] = i;
            rightBuddy[idx] = i + 2;
            alive[idx] = 1;
        }
        leftBuddy[0] = 0;
        rightBuddy[numberOfSoliders + 1] = numberOfSoliders + 1;

        for (int i{}; i < numberOfLossReports; ++i) {
            int left, right;
            std::cin >> left >> right;

            int leftSurvior{leftBuddy[left]};
            int rightSurvior{rightBuddy[right]};

            // remove all soldiers in [left,right] that are still alive
            for (int j = left; j <= right; ++j) {
                if (alive[j]) {
                    int l = leftBuddy[j];
                    int r = rightBuddy[j];
                    rightBuddy[l] = r;
                    leftBuddy[r] = l;
                    alive[j] = 0;
                }
            }

            if (leftSurvior == 0) output << '*';
            else output << leftSurvior;
            output << ' ';
            if (rightSurvior > numberOfSoliders) output << '*';
            else output << rightSurvior;
            output << '\n';
        }
        output << "-\n";
    }
    std::cout << output.str();
}
