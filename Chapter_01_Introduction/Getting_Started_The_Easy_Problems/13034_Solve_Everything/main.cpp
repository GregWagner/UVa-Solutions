#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ostringstream output;
    int testCases {};
    std::cin >> testCases;
    int testCase {};
    while (testCases--) {
        bool valid {true};
        for (int i {}; i < 13; ++i) {
            int temp;
            std::cin >> temp;
            if (temp == 0) {
                valid = false;
            }
        }
        output << "Set #" << ++testCase << ": ";
        output << (valid ? "Yes" : "No") << '\n';
    }
    std::cout << output.str();
}
