#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int testCases {};
    std::cin >> testCases;
    while (testCases--) {
        std::string s;
        std::cin >> s;
        if (s.size() < 10) {
            output << s << '\n';
        } else {
            output << s[0] << (s.size() - 2) << s[s.size() -1] << '\n';
        }
    }
    std::cout << output.str();
}
