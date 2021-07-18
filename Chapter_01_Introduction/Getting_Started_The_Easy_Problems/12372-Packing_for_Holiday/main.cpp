/*
 * 12372 Packing for Holiday
 */
#include <iostream>
#include <sstream>

int main() {
    const int MAX_SIZE {20};
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases {};
    std::cin >> testCases;
    int testCase {};
    while (testCases-- != 0) {
        int length {};
        int width {};;
        int height {};
        std::cin >> length >> width >> height;
        output << "Case " << ++testCase << ": "
            << (length <= MAX_SIZE && width <= MAX_SIZE && height <= MAX_SIZE
                    ? "good\n" : "bad\n");
    }
    std::cout << output.str();
}
