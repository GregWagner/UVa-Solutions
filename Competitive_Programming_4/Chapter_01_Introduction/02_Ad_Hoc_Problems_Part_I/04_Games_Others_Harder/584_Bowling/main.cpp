/*
 * 584 Bowling
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string input;
    while (std::getline(std::cin, input)) {
        if (input == "Game Over") {
            break;
        }

        // Parse the line into pin counts ("/" depends on the previous roll).
        std::vector<int> rolls;
        std::istringstream tokens(input);
        std::string token;
        while (tokens >> token) {
            if (token == "X") {
                rolls.push_back(10);
            } else if (token == "/") {
                rolls.push_back(10 - rolls.back());
            } else {
                rolls.push_back(token[0] - '0');
            }
        }

        int score{};
        std::size_t idx{};
        for (int frame{}; frame < 10; ++frame) {
            if (rolls[idx] == 10) { // strike
                score += 10 + rolls[idx + 1] + rolls[idx + 2];
                idx += 1;
            } else if (rolls[idx] + rolls[idx + 1] == 10) { // spare
                score += 10 + rolls[idx + 2];
                idx += 2;
            } else { // open frame
                score += rolls[idx] + rolls[idx + 1];
                idx += 2;
            }
        }
        output << score << '\n';
    }
    std::cout << output.str();
}
