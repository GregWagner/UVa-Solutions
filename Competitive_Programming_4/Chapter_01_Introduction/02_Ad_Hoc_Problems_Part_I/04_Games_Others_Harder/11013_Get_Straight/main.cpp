// 11013 Get Straight
#include <algorithm>
#include <array>
#include <iostream>
#include <string>

namespace {

// A=0, 2=1, 3=2, ..., 9=8, T=9, J=10, Q=11, K=12 (consecutive modulo 13).
auto cardValue(char c) -> int {
    switch (c) {
    case 'A': return 0;
    case 'T': return 9;
    case 'J': return 10;
    case 'Q': return 11;
    case 'K': return 12;
    default: return c - '1';
    }
}

auto popcount(int mask) -> int {
    int n = 0;
    for (; mask; mask &= mask - 1) {
        ++n;
    }
    return n;
}

// Does the subset of cards in `mask` form one run (distinct, consecutive mod 13)?
auto isRun(const std::array<int, 5>& v, int mask) -> bool {
    bool seen[13] = {};
    int n = 0;
    for (int i = 0; i < 5; ++i) {
        if (!(mask >> i & 1)) {
            continue;
        }
        if (seen[v[i]]) {
            return false; // repeated value: not a run
        }
        seen[v[i]] = true;
        ++n;
    }
    if (n < 2) {
        return false;
    }
    for (int start = 0; start < 13; ++start) {
        bool ok = true;
        for (int k = 0; k < n && ok; ++k) {
            if (!seen[(start + k) % 13]) {
                ok = false;
            }
        }
        if (ok) {
            return true;
        }
    }
    return false;
}

auto runPayment(int length) -> int {
    switch (length) {
    case 5: return 100; // Straight
    case 4: return 10;  // Invite-the-Neighbours
    case 3: return 3;   // Menage-a-Trois
    default: return 0;  // Dutch (run of 2)
    }
}

// Highest-paying combination the five card values can be arranged into.
auto bestPayment(const std::array<int, 5>& v) -> int {
    int best = 0; // Dummy
    for (int m = 1; m < 32; ++m) {
        if (isRun(v, m)) {
            best = std::max(best, runPayment(popcount(m)));
        }
    }
    for (int m1 = 1; m1 < 32; ++m1) {
        if (!isRun(v, m1)) {
            continue;
        }
        for (int m2 = m1 + 1; m2 < 32; ++m2) {
            if ((m1 & m2) || !isRun(v, m2)) {
                continue;
            }
            int lo = std::min(popcount(m1), popcount(m2));
            int hi = std::max(popcount(m1), popcount(m2));
            if (lo == 2 && hi == 3) {
                best = std::max(best, 5); // Bed-and-Breakfast
            } else if (lo == 2 && hi == 2) {
                best = std::max(best, 1); // Double Dutch
            }
        }
    }
    return best;
}

} // namespace

auto solve(std::istream& input, std::ostream& output) -> void {
    for (;;) {
        std::string token;
        if (!(input >> token) || token == "#") {
            break;
        }

        std::array<std::string, 5> cards;
        std::array<int, 5> v;
        cards[0] = token;
        v[0] = cardValue(token[0]);
        for (int i = 1; i < 5; ++i) {
            input >> cards[i];
            v[i] = cardValue(cards[i][0]);
        }

        int count[13] = {};
        for (int x : v) {
            ++count[x];
        }

        // Earnings are compared as fractions with denominator 47, so stay with
        // integers: stay = 47 * (payment - 1), exchange = expectedPayout - 94.
        long long bestEarn = 47LL * (bestPayment(v) - 1);
        int bestCard = -1; // -1 means stay

        for (int i = 0; i < 5; ++i) {
            std::array<int, 4> kept;
            int k = 0;
            for (int j = 0; j < 5; ++j) {
                if (j != i) {
                    kept[k++] = v[j];
                }
            }

            long long total = 0;
            for (int val = 0; val < 13; ++val) {
                int available = 4 - count[val]; // unseen copies of this value
                if (available <= 0) {
                    continue;
                }
                std::array<int, 5> next{kept[0], kept[1], kept[2], kept[3], val};
                total += (long long)available * bestPayment(next);
            }

            long long earn = total - 94;
            if (earn > bestEarn) {
                bestEarn = earn;
                bestCard = i;
            }
        }

        if (bestCard < 0) {
            output << "Stay\n";
        } else {
            output << "Exchange " << cards[bestCard] << '\n';
        }
    }
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve(std::cin, std::cout);
}
