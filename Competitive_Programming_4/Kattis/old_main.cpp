#include <iostream>

int main() {
    int nStu{};
    int nVis{};
    int nFac{};
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        std::string s, d;
        int count;
        std::cin >> s >> d >> count;
        if (d == "OUT") {
            count = -count;
        }
        if (s == "nStu") {
            nStu += count;
        } else if (s == "VIS") {
            nVis += count;
        } else if (s == "FAC") {
            nFac += count;
        }
    }
    int count = nStu + nVis + nFac;
    if (count == 0) {
        std::cout << "NO STRAGGLERS\n";
    } else {
        std::cout << count << '\n';
    }
}
