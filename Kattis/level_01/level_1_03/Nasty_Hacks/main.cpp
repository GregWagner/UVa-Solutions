/*
 * Nasty Hacks
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int with, without, cost;
        std::cin >> without >> with >> cost;
        if (with - cost == without) {
            output << "does not matter\n";
        } else {
            output << (with - cost > without ? "" : "do not ")
                << "advertise\n";
        }
    }
    std::cout << output.str();
}
