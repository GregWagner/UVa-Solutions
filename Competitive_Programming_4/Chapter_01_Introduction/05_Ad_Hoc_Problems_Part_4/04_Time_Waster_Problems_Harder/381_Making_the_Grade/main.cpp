#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto rnd = [](double x) { return std::round(x * 10.0) / 10.0; };

    int testCases;
    if (!(std::cin >> testCases)) {
        return 0;
    }

    std::ostringstream output;
    output << std::fixed << std::setprecision(1);

    output << "MAKING THE GRADE OUTPUT\n";

    for (int t = 0; t < testCases; ++t) {
        int S, T;
        if (!(std::cin >> S >> T)) {
            return 0;
        }

        std::vector<std::vector<int>> scores(S, std::vector<int>(T));
        std::vector<int> bonus(S), absent(S);

        for (int i = 0; i < S; ++i) {
            for (int j = 0; j < T; ++j) {
                std::cin >> scores[i][j];
            }
            std::cin >> bonus[i] >> absent[i];
        }

        std::vector<double> avg(S);
        for (int i = 0; i < S; ++i) {
            std::vector<int> kept = scores[i];
            if (T > 2) {
                std::sort(kept.begin(), kept.end());
                kept.erase(kept.begin()); // drop lowest
            }
            double sum = 0.0;
            for (int v : kept)
                sum += v;
            avg[i] = rnd(sum / static_cast<double>(kept.size()));
        }

        double mean = 0.0;
        for (int i = 0; i < S; ++i)
            mean += avg[i];
        mean /= S;
        mean = rnd(mean);

        double sd = 0.0;
        for (int i = 0; i < S; ++i) {
            double d = avg[i] - mean;
            sd += d * d;
        }
        sd = std::sqrt(sd / S);
        bool sdWasSmall = sd < 1.0;
        sd = rnd(sd);
        if (sdWasSmall)
            sd = 1.0;
        if (sd < 1.0)
            sd = 1.0;

        std::vector<double> adjAvg(S);
        for (int i = 0; i < S; ++i) {
            adjAvg[i] = rnd(avg[i] + static_cast<double>((bonus[i] / 2) * 3));
        }

        std::vector<int> grade(S); // 0=A 1=B 2=C 3=D 4=F
        for (int i = 0; i < S; ++i) {
            if (adjAvg[i] >= mean + sd) {
                grade[i] = 0;
            } else if (adjAvg[i] >= mean) {
                grade[i] = 1;
            } else if (adjAvg[i] >= mean - sd) {
                grade[i] = 2;
            } else {
                grade[i] = 3;
            }

            if (absent[i] == 0) {
                grade[i] = std::max(0, grade[i] - 1);
            } else {
                grade[i] = std::min(4, grade[i] + absent[i] / 4);
            }
        }

        double totalPoints = 0.0;
        for (int i = 0; i < S; ++i) {
            totalPoints += (4 - grade[i]);
        }
        double avgGradePoint = rnd(totalPoints / S);

        output << avgGradePoint << "\n";
    }

    output << "END OF OUTPUT\n";
    std::cout << output.str();
}