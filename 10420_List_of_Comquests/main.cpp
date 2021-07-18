#include <iostream>
#include <sstream>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ostringstream output;
    std::map<std::string, int> m;

    int n {};
    std::cin >> n;
    std::string input;
    std::getline(std::cin, input);
    while (n--) {
        std::getline(std::cin, input);
        std::stringstream ss(input);
        ss >> input;
        if (m[input]) {
            ++m[input];
        } else {
            m[input] = 1;
        }
    }
    for (const auto &e : m) {
        output << e.first << ' ' << e.second << '\n';
    }
    std::cout << output.str();
}
