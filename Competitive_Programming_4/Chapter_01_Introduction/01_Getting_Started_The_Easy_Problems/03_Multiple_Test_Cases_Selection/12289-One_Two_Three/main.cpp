#include <iostream>
#include <sstream>

bool is_one(const std::string &s) {
    if (s[0] == 'o' && (s[1] == 'n' || s[2] == 'e')) {
        return true;
    }
    if (s[1] == 'n' && (s[0] == 'o' || s[2] == 'e')) {
        return true;
    }
    return false;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    int n {};
    std::cin >> n;
    while (n--) {
        std::string input;
        std::cin >> input;
        if (input.size() != 3) {
            output << "3\n";
        } else {
            output << (is_one(input) ? "1\n" : "2\n");
        }
    }
    std::cout << output.str();
}
