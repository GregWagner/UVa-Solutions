#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int c, v;
    int caseNum = 1;

    while (std::cin >> c >> v && !(c == 0 && v == 0)) {
        std::vector<std::vector<int>> ballots(v, std::vector<int>(c));
        std::vector<char> bad(v, 0);
        int badCount = 0;

        for (int i = 0; i < v; ++i) {
            std::vector<int> mark(c + 1, 0);
            bool isBad = false;
            for (int j = 0; j < c; ++j) {
                std::cin >> ballots[i][j];
                int x = ballots[i][j];
                if (x < 1 || x > c) {
                    isBad = true;
                } else {
                    if (mark[x] > 0) {
                        isBad = true;
                    }
                    mark[x]++;
                }
            }
            if (isBad) {
                bad[i] = 1;
                ++badCount;
            }
        }

        output << "Election #" << caseNum++ << "\n";
        if (badCount > 0) {
            output << "   " << badCount << " bad ballot(s)\n";
        }

        std::vector<int> atop(v, 0);
        std::vector<char> eliminated(c + 1, 0);
        int aliveCount = c;

        for (int round = 1; round < c; ++round) {
            std::vector<int> votes(c + 1, 0);

            for (int i = 0; i < v; ++i) {
                if (bad[i])
                    continue;
                while (atop[i] < c && eliminated[ballots[i][atop[i]]]) {
                    ++atop[i];
                }
                if (atop[i] < c) {
                    votes[ballots[i][atop[i]]]++;
                }
            }

            int mx = 0;
            for (int i = 1; i <= c; ++i) {
                if (!eliminated[i]) {
                    mx = std::max(mx, votes[i]);
                }
            }

            int del = -1;
            for (int i = 1; i <= c; ++i) {
                if (!eliminated[i] && votes[i] < mx) {
                    del = i;
                    mx = votes[i];
                }
            }

            if (del == -1) {
                break;
            }
            eliminated[del] = 1;
            --aliveCount;
        }

        if (aliveCount == 1) {
            for (int i = 1; i <= c; ++i) {
                if (!eliminated[i]) {
                    output << "   Candidate " << i << " is elected.\n";
                }
            }
        } else {
            output << "   The following candidates are tied:";
            for (int i = 1; i <= c; ++i) {
                if (!eliminated[i]) {
                    output << " " << i;
                }
            }
            output << "\n";
        }
    }
    std::cout << output.str();
}