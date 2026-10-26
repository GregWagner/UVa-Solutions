// 10188 Automated Judge
#include <iostream>
#include <sstream>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int runNumber{1};
    int numberOfSolutions;
    while (std::cin >> numberOfSolutions) {
        if (numberOfSolutions == 0) break;

        std::string dummy;
        std::getline(std::cin, dummy); // consume end of line

        std::vector<std::string> solutions(numberOfSolutions);
        for (int i{}; i < numberOfSolutions; ++i) {
            std::getline(std::cin, solutions[i]);
            if (!solutions[i].empty() && solutions[i].back() == '\r') solutions[i].pop_back();
        }

        int numberOfTeamSolutions;
        std::cin >> numberOfTeamSolutions;
        std::getline(std::cin, dummy); // consume end of line

        std::vector<std::string> teamSolutions(numberOfTeamSolutions);
        for (int i{}; i < numberOfTeamSolutions; ++i) {
            std::getline(std::cin, teamSolutions[i]);
            if (!teamSolutions[i].empty() && teamSolutions[i].back() == '\r') teamSolutions[i].pop_back();
        }

        if (teamSolutions == solutions) {
            output << "Run #" << runNumber++ << ": Accepted\n";
        } else {
            std::string digitsA, digitsB;
            for (const auto& line : solutions)
                for (char c : line) if (c >= '0' && c <= '9') digitsA += c;
            for (const auto& line : teamSolutions)
                for (char c : line) if (c >= '0' && c <= '9') digitsB += c;
            bool digitsMatch = digitsA == digitsB;
            output << "Run #" << runNumber++ << ": "
                   << (digitsMatch ? "Presentation Error" : "Wrong Answer")
                   << '\n';
        }
    }

    std::cout << output.str();
}
