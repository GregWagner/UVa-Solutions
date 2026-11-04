#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Period {
    long long duration;
    long long temp;
};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    for (int caseNum{1}; caseNum <= testCases; ++caseNum) {
        long long M, S;
        std::cin >> M >> S;

        std::vector<long long> thresholds(4);
        for (int i{}; i < 4; ++i) {
            std::cin >> thresholds[i];
        }

        int C;
        std::cin >> C;

        std::vector<bool> enabled(4);
        std::vector<bool> isHighTrigger(4);
        for (int i{}; i < 4; ++i) {
            enabled[i] = (C & (1 << i)) != 0;
            isHighTrigger[i] = (C & (1 << (i + 4))) != 0;
        }

        int K;
        std::cin >> K;
        std::vector<Period> periods(K);
        long long totalDuration{};
        for (int i{}; i < K; ++i) {
            std::cin >> periods[i].duration >> periods[i].temp;
            totalDuration += periods[i].duration;
        }

        std::vector<bool> triggered(4, false);

        long long cum = 0;
        long long prevCum = -1;
        for (const auto& p : periods) {
            cum += p.duration;
            long long L = std::max(S, prevCum + 1);
            long long R = std::min(cum, totalDuration);
            if (L <= R && M > 0) {
                long long first;
                if (L <= S) {
                    first = S;
                } else {
                    long long delta = L - S;
                    long long k = (delta + M - 1) / M;
                    first = S + k * M;
                }
                if (first <= R) {
                    long long temp = p.temp;
                    for (int i{}; i < 4; ++i) {
                        if (!enabled[i] || triggered[i]) continue;
                        if (isHighTrigger[i]) {
                            if (temp > thresholds[i]) {
                                triggered[i] = true;
                            }
                        } else {
                            if (temp < thresholds[i]) {
                                triggered[i] = true;
                            }
                        }
                    }
                }
            }
            prevCum = cum;
            // early exit if all enabled alarms are already triggered
            bool allDone = true;
            for (int i{}; i < 4; ++i) {
                if (enabled[i] && !triggered[i]) {
                    allDone = false;
                    break;
                }
            }
            if (allDone) break;
        }

        output << "Case " << caseNum << ":";
        for (int i{}; i < 4; ++i) {
            output << (triggered[i] ? " yes" : " no");
        }
        output << "\n";
    }
    std::cout << output.str();
}
