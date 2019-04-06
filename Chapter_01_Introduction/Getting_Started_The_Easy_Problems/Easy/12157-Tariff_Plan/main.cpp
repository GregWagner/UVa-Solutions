/*
 * Problem 12157 - Tarriff Plan
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int test {};
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int mile {};
        int juice {};
        int numberOfCalls;
        std::cin >> numberOfCalls;
        for (int i = 0; i < numberOfCalls; ++i) {
            int call;
            std::cin >> call;
            mile += 1 + (call / 30);
            juice += 1 + (call / 60);
        }
        mile *= 10;
        juice *= 15;
        output << "Case " << ++test << ": ";
        if (mile == juice) {
            output << "Mile Juice " << mile << '\n';
        } else {
            output << (mile < juice ? "Mile " : "Juice ")
                    << std::min(mile, juice) << '\n';
        }
    }
    std::cout << output.str();
}
