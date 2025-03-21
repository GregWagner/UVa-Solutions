#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ostringstream output;
    int allowed {};
    int testCases {};
    std::cin >> testCases;
    while (testCases--) {
        double length {};
        double width {};
        double depth {};
        double weight {};
        std::cin >> length >> width >> depth >> weight;
        if (weight <= 7 && ((length <= 56 && width <= 45 && depth <= 25) ||
                length + width + depth <= 125)) {
            output << 1 << '\n';
            ++allowed;
        } else {
            output << 0 << '\n';
        }
    }
    output << allowed << '\n';
    std::cout << output.str();
}
