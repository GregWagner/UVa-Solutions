/*
 * Problem 12372 - Packing for Holiday
 */
#include <iostream>
#include <sstream>

int main() {
    constexpr int SIZE {20};
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int test {1};

    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int length, width, height;
        std::cin >> length >> width >> height;
        output <<  "Case " << test++ << ": "
            << (length <= SIZE && width <= SIZE && height <= SIZE ?
                "good\n" : "bad\n");
    }
    std::cout << output.str();
}
