#include <iostream>
#include <string>
#include <vector>

auto getVal(char c) -> long long {
    switch (c) {
    case 'B': return 1;
    case 'U': return 10;
    case 'S': return 100;
    case 'P': return 1000;
    case 'F': return 10000;
    case 'T': return 100000;
    case 'M': return 1000000;
    default: return -1;
    }
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int testCases;
    if (!(std::cin >> testCases)) return 0;
    while (testCases--) {
        std::string s;
        std::cin >> s;

        bool error = false;
        long long counts[256] = {0};
        std::vector<long long> vals;
        vals.reserve(s.size());

        for (char c : s) {
            long long v = getVal(c);
            if (v == -1) {
                error = true;
                break;
            }
            vals.push_back(v);
            counts[(unsigned char)c]++;
        }

        if (!error) {
            // check more than nine equal characters
            if (counts[(unsigned char)'B'] > 9) error = true;
            if (counts[(unsigned char)'U'] > 9) error = true;
            if (counts[(unsigned char)'S'] > 9) error = true;
            if (counts[(unsigned char)'P'] > 9) error = true;
            if (counts[(unsigned char)'F'] > 9) error = true;
            if (counts[(unsigned char)'T'] > 9) error = true;
            if (counts[(unsigned char)'M'] > 9) error = true;
        }

        if (!error) {
            bool nonDecreasing = true;
            bool nonIncreasing = true;
            for (size_t i = 0; i + 1 < vals.size(); ++i) {
                if (vals[i] > vals[i + 1]) nonDecreasing = false;
                if (vals[i] < vals[i + 1]) nonIncreasing = false;
            }
            if (!nonDecreasing && !nonIncreasing) error = true;
        }

        if (error) {
            std::cout << "error\n";
        } else {
            long long total = 0;
            for (long long v : vals) total += v;
            std::cout << total << "\n";
        }
    }
    return 0;
}
