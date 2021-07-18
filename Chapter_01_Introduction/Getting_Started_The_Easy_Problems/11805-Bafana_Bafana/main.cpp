/*
 * 11805 Bafana Bafama
 */
#include <ios>
#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int testCase {};
    int testCases {};
    std::cin >> testCases;
    while (testCases-- != 0) {
        int n {};
        int k {};
        int p {};
        std::cin >> n >> k >> p;
        int lastPlayer = (k + p) % n;
        output << "Case " << ++testCase << ": " << 
            (lastPlayer ? lastPlayer : n) << '\n';
    }
    std::cout << output.str();
}
