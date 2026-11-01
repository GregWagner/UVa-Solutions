#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int K, N;
    while (std::cin >> K >> N) {
        if (K == 0 && N == 0)
            break;
        std::vector<std::string> inst(N + 1);
        std::vector<std::vector<int>> reviewers(N + 1);
        for (int i{1}; i <= N; ++i) {
            std::cin >> inst[i];
            for (int j{}; j < K; ++j) {
                int paper;
                std::cin >> paper;
                if (paper >= 1 && paper <= N) {
                    reviewers[paper].push_back(i);
                }
            }
        }
        int violations{};
        for (int p{1}; p <= N; ++p) {
            bool flagged{};
            auto& vec = reviewers[p];
            // check duplicate reviewers
            std::set<int> uniq(vec.begin(), vec.end());
            if ((int)uniq.size() != (int)vec.size()) {
                flagged = true;
            }
            if ((int)uniq.size() != K) {
                flagged = true;
            }
            if (!flagged) {
                for (int rev : uniq) {
                    if (inst[rev] == inst[p]) {
                        flagged = true;
                        break;
                    }
                }
            }
            if (flagged)
                ++violations;
        }
        if (violations == 0) {
            output << "NO PROBLEMS FOUND\n";
        } else if (violations == 1) {
            output << "1 PROBLEM FOUND\n";
        } else {
            output << violations << " PROBLEMS FOUND\n";
        }
    }
    std::cout << output.str();
}
