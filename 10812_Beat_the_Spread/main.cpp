#include <iostream>
#include <sstream>

void check(long long sum, long long difference, std::ostringstream &output) {
    for (long long i {}; i < sum; ++i) {
        for (long long j {}; j < sum; ++j) {
            if (i + j == sum && std::abs(i -j) == difference) {
                output << i << ' ' << j << '\n';
                return;
            }
        }
    }
    output << "impossible\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ostringstream output;

    int testCases {};
    std::cin >> testCases;
    while (testCases--) {
        long long sum {};
        long long difference {};
        std::cin >> sum >> difference;
        check(sum, difference, output);
    }

    std::cout << output.str();
}
