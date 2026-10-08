/* 
 * The Key Insight
 * Because performing an AND operation with additional numbers can only
 * decrease (or keep equal) your current score, your best strategy is to
 * pick only ONE card — specifically, the card with the LARGEST number!
*/

#include <iostream>
#include <sstream>
#include <algorithm>
#include <climits>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);

    std::ostringstream output;
    int testCases{};
    int test = 0;
    std::cin >> testCases;
    while (testCases--) {
        output << "Case " << ++test << ": ";
        int numberOfCards{};
        std::cin >> numberOfCards;
        long long maxVal = LLONG_MIN;
        for (int i = 0; i < numberOfCards; ++i) {
            long long val{};
            std::cin >> val;
            if (val > maxVal) {
                maxVal = val;
            }
        }
        output << maxVal << '\n';
    }
    std::cout << output.str();
}
