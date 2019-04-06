/* 
 * Problem 11661 Burger Time ?
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int length;
    while (std::cin >> length && length != 0) {
        bool seenR {};
        bool seenD {};
        int start {};
        unsigned long distance {2000010};
        std::string street;
        std::cin >> street;
        for (size_t i {}; i < street.size(); ++i) {
            if (street[i] == 'Z') {
                distance = 0;
                break;
            }
            if (street[i] == 'R') {
                if (!seenR && !seenD) {
                    seenR = true;
                    start = i;
                } else if (seenR) {
                    start = i;
                } else {
                    if (i - start < distance) {
                        distance = i - start;
                    }
                    seenD = false;
                    seenR = true;
                    start = i;
                }
            } else if (street[i] == 'D') {
                if (!seenR && !seenD) {
                    seenD = true;
                    start = i;
                } else if (seenD) {
                    start = i;
                } else {
                    if (i - start < distance) {
                        distance = i - start;
                    }
                    seenR = false;
                    seenD = true;
                    start = i;
                }
            }
        }
        output << distance << '\n';
    }
    std::cout << output.str();
}
