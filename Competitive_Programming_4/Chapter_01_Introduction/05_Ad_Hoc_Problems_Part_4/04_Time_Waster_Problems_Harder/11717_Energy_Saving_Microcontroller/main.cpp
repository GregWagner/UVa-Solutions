#include <iostream>
#include <sstream>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    if (!(std::cin >> testCases)) return 0;
    for (int caseNum = 1; caseNum <= testCases; ++caseNum) {
        long long n, i_val, k;
        if (!(std::cin >> n >> i_val >> k))
            return 0;

        long long numInactive = 0;
        long long numIgnored = 0;
        long long activeTime = 0; // end of current active / wake-up period

        for (long long j = 0; j < n; ++j) {
            long long t;
            std::cin >> t;
            if (t >= activeTime + i_val) {
                ++numInactive;
                activeTime = t + k;
            } else if (t < activeTime) {
                ++numIgnored;
            } else {
                activeTime = t;
            }
        }
        output << "Case " << caseNum << ": " << numInactive << ' ' << numIgnored << '\n';
    }
    std::cout << output.str();
}
