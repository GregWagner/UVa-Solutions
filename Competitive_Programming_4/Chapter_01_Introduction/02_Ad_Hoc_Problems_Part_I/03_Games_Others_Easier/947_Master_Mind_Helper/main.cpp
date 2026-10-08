#include <algorithm>
#include <iostream>
#include <sstream>

auto matchesFeedback(const std::string& candidate, const std::string& guess,
                     int targetStrong, int targetWeak) -> bool {
    int strong = 0;
    int guessCount[10] = {};
    int candidateCount[10] = {};

    // Pass 1: exact-position matches (strong). Remaining digits are tallied.
    for (size_t i = 0; i < guess.size(); ++i) {
        if (candidate[i] == guess[i]) {
            ++strong;
        } else {
            ++guessCount[guess[i] - '0'];
            ++candidateCount[candidate[i] - '0'];
        }
    }

    // Pass 2: shared digits in wrong positions (weak), with multiplicity.
    int weak = 0;
    for (int d = 1; d <= 9; ++d) {
        weak += std::min(guessCount[d], candidateCount[d]);
    }

    return strong == targetStrong && weak == targetWeak;
}

auto countCandidates(std::string& current, const std::string& guess,
                     int targetStrong, int targetWeak) -> int {
    // base case: full candidate generated
    if (current.length() == guess.length()) {
        return matchesFeedback(current, guess, targetStrong, targetWeak) ? 1 : 0;
    }
    // recursive case: generate candidates
    int count = 0;
    for (char c = '1'; c <= '9'; ++c) {
        current.push_back(c);
        count += countCandidates(current, guess, targetStrong, targetWeak);
        current.pop_back(); // backtrack
    }
    return count;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int testCases{};
    std::cin >> testCases;
    while (testCases--) {
        std::string guess;
        int strong{}, weak{};
        std::cin >> guess >> strong >> weak;

        std::string current;
        int count = countCandidates(current, guess, strong, weak);
        output << count << '\n';
    }
    std::cout << output.str();
}
