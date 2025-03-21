/*
 * Problem 10141 - Request for Proposal
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    bool first {true};
    int test {};
    int numberOfRequirements;
    int numberOfProposels;
    while (std::cin >> numberOfRequirements >> numberOfProposels) {
        if (numberOfRequirements == 0 && numberOfProposels == 0) {
            break;
        }
        output << (first ? "" : "\n");
        first = false;
        std::string temp;
        std::getline(std::cin, temp);
        for (int i = 0; i < numberOfRequirements; i++) {
            std::getline(std::cin, temp);
        }
        std::string bestName = "";
        double bestPrice {};
        int bestRequirementsMet {};
        for (int i = 0; i < numberOfProposels; ++i) {
            std::string name;
            std::getline(std::cin, name);
            double price;
            int requirementsMet;
            std::cin >> price >> requirementsMet;
            std::getline(std::cin, temp);
            for (int j = 0; j < requirementsMet; ++j) {
                std::getline(std::cin, temp);
            }
            if (requirementsMet > bestRequirementsMet) {
                bestName = name;
                bestPrice = price;
                bestRequirementsMet = requirementsMet;
            } else if (requirementsMet == bestRequirementsMet &&
                    price < bestPrice) {
                bestName = name;
                bestPrice = price;
            }
        }
        output << "RFP #" << ++test << '\n' << bestName << '\n';
    }
    std::cout << output.str();
}
