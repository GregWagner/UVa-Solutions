#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string line;
    while (std::cin >> line) {
        std::map<char, int> charMap;
        int nextId{1};
        std::string result{};

        for (char c : line) {
            if (charMap.find(c) == charMap.end()) {
                charMap[c] = nextId++;
            }
            result += std::to_string(charMap[c]);
        }

        // Police swap digits: 2<->5 and 6<->9 in the resultant id.
        for (char& c : result) {
            if (c == '2')
                c = '5';
            else if (c == '5')
                c = '2';
            else if (c == '6')
                c = '9';
            else if (c == '9')
                c = '6';
        }

        output << result << "\n";
    }
    std::cout << output.str();
}
