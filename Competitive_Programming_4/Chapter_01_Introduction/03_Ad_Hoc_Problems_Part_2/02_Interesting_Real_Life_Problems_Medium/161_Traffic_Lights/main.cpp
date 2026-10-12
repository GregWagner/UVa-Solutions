// 161 Traffic Lights
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

void solve(const std::vector<int>& times, std::ostringstream& output) {
    auto allGreen = [&times](int t) {
        for (int v : times) {
            if (t % (2 * v) >= v - 5) {
                return false;
            }
        }
        return true;
    };

    for (int t = 1; t <= 18000; ++t) {          // 5 hours
        if (allGreen(t) && !allGreen(t - 1)) {  // skip the initial all-green phase
            output << std::setfill('0')
                   << std::setw(2) << t / 3600 << ':'
                   << std::setw(2) << (t % 3600) / 60 << ':'
                   << std::setw(2) << t % 60 << '\n';
            return;
        }
    }
    output << "Signals fail to synchronise in 5 hours\n";
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::vector<int> times;
    int zeroCount{};
    int time;
    while (std::cin >> time) {
        if (time == 0) {
            if (++zeroCount == 3) {
                break;                // three consecutive zeros => end of input
            }
            if (!times.empty()) {     // a lone 0 ends one configuration
                solve(times, output);
                times.clear();
            }
        } else {
            zeroCount = 0;
            times.push_back(time);    // only non-zero values belong to a set
        }
    }

    std::cout << output.str();
}
