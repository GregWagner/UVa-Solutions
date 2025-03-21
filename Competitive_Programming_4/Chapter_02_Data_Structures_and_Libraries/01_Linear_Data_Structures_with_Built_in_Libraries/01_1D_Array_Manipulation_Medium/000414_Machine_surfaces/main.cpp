#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;
    std::vector<int> spacesInWord(15);

    int n;
    std::string s;
    while (std::cin >> n && n != 0) {
        std::getline(std::cin, s);
        if (n == 1) {
            std::getline(std::cin, s);
            output << "0\n";
            continue;
        }
        int minSpaces{25};
        for (int i = 0; i < n; ++i) {
            std::getline(std::cin, s);
            spacesInWord[i] = 0;
            for (size_t index{}; index < s.size(); ++index) {
                if (s[index] == ' ') {
                    ++spacesInWord[i];
                }
            }
            minSpaces = std::min(minSpaces, spacesInWord[i]);
        }
        int answer{};
        for (int i = 0; i < n; ++i) {
            answer += spacesInWord[i] - minSpaces;
        }
        output << answer << '\n';
    }
    std::cout << output.str();
}
