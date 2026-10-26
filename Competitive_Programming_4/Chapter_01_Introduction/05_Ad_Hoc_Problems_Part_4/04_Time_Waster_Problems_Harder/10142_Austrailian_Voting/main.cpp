// 10142 Australian Voting
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Candidate {
    std::string name;
    int votes{};
    bool eliminated{};
};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int numberOfCases;
    std::cin >> numberOfCases;
    std::cin.ignore();

    for (int caseNum{}; caseNum < numberOfCases; ++caseNum) {
        if (caseNum > 0) {
            output << '\n';
        }

        int numberOfCandiates;
        std::cin >> numberOfCandiates;
        std::cin.ignore();

        std::vector<Candidate> canidates(numberOfCandiates + 1);
        std::vector<std::vector<int>> ballots;

        for (int i{1}; i <= numberOfCandiates; ++i) {
            std::getline(std::cin, canidates[i].name);
        }

        std::string input;
        while (std::getline(std::cin, input) && !input.empty()) {
            std::stringstream ss(input);
            std::vector<int> ballot;
            int preferred;
            while (ss >> preferred) {
                ballot.push_back(preferred);
            }
            ballots.push_back(ballot);
        }

        int totalVoters = ballots.size();
        if (totalVoters == 0) {
            continue;
        }

        int remainingCandidates = numberOfCandiates;
        int maxVotes = 0;
        int winner = -1;

        while (remainingCandidates > 0) {
            // Reset votes
            for (int i{1}; i <= numberOfCandiates; ++i) {
                canidates[i].votes = 0;
            }

            // Count first-choice votes
            for (const auto& ballot : ballots) {
                for (int pref : ballot) {
                    if (pref >= 1 && pref <= numberOfCandiates &&
                        !canidates[pref].eliminated) {
                        canidates[pref].votes++;
                        break;
                    }
                }
            }

            // Find max votes
            maxVotes = 0;
            for (int i{1}; i <= numberOfCandiates; ++i) {
                if (!canidates[i].eliminated && canidates[i].votes > maxVotes) {
                    maxVotes = canidates[i].votes;
                }
            }

            // Check if someone has > 50%
            if (maxVotes * 2 > totalVoters) {
                for (int i{1}; i <= numberOfCandiates; ++i) {
                    if (!canidates[i].eliminated &&
                        canidates[i].votes == maxVotes) {
                        output << canidates[i].name << '\n';
                    }
                }
                break;
            }

            // Find min votes among remaining
            int minVotes = totalVoters + 1;
            for (int i{1}; i <= numberOfCandiates; ++i) {
                if (!canidates[i].eliminated && canidates[i].votes < minVotes) {
                    minVotes = canidates[i].votes;
                }
            }

            // Check for tie (all remaining have same votes)
            bool isTie = true;
            for (int i{1}; i <= numberOfCandiates; ++i) {
                if (!canidates[i].eliminated &&
                    canidates[i].votes != maxVotes) {
                    isTie = false;
                    break;
                }
            }

            if (isTie) {
                for (int i{1}; i <= numberOfCandiates; ++i) {
                    if (!canidates[i].eliminated) {
                        output << canidates[i].name << '\n';
                    }
                }
                break;
            }

            // Eliminate candidate(s) with min votes
            for (int i{1}; i <= numberOfCandiates; ++i) {
                if (!canidates[i].eliminated &&
                    canidates[i].votes == minVotes) {
                    canidates[i].eliminated = true;
                    --remainingCandidates;
                }
            }
        }
    }

    std::cout << output.str();
}
