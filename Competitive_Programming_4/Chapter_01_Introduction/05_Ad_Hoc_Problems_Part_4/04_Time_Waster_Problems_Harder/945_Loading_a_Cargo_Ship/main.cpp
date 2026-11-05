#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    bool firstDataset{true};

    int c{};
    while (std::cin >> c) {
        std::vector<int> capacities(c);
        for (int i{0}; i < c; ++i) {
            std::cin >> capacities[i];
        }

        int p{};
        std::cin >> p;
        std::vector<int> weights(p);
        for (int i{0}; i < p; ++i) {
            std::cin >> weights[i];
        }

        std::vector<std::vector<int>> holds(c);
        std::vector<int> counts(c, 0);
        std::vector<int> used(c, 0);

        int loadedWeight{0};
        int i{0};
        for (; i < p; ++i) {
            int w{weights[i]};

            int minCount{*std::min_element(counts.begin(), counts.end())};

            int best{-1};
            int bestAvail{0};
            for (int j{0}; j < c; ++j) {
                if (counts[j] != minCount) {
                    continue;
                }
                int avail{capacities[j] - used[j]};
                if (best == -1 || avail > bestAvail) {
                    best = j;
                    bestAvail = avail;
                }
            }

            if (bestAvail < w) {
                break;
            }

            holds[best].push_back(w);
            ++counts[best];
            used[best] += w;
            loadedWeight += w;
        }

        int unused{0};
        for (int j{0}; j < c; ++j) {
            unused += (capacities[j] - used[j]);
        }

        int unloaded{0};
        for (int k{i}; k < p; ++k) {
            unloaded += weights[k];
        }

        if (!firstDataset) {
            output << '\n';
        }
        firstDataset = false;

        int maxHeight{0};
        for (int j{0}; j < c; ++j) {
            if (static_cast<int>(holds[j].size()) > maxHeight) {
                maxHeight = static_cast<int>(holds[j].size());
            }
        }

        for (int level{maxHeight - 1}; level >= 0; --level) {
            for (int j{0}; j < c; ++j) {
                if (level < static_cast<int>(holds[j].size())) {
                    output << holds[j][level];
                } else {
                    output << ':';
                }
                if (j + 1 < c) {
                    output << ' ';
                }
            }
            output << '\n';
        }

        output << std::string(2 * c - 1, '=') << '\n';

        for (int j{0}; j < c; ++j) {
            output << (j + 1);
            if (j + 1 < c) {
                output << ' ';
            }
        }
        output << '\n';
        output << '\n';

        output << "cargo weight: " << loadedWeight << '\n';
        output << "unused weight: " << unused << '\n';
        output << "unloaded weight: " << unloaded << '\n';
    }

    std::cout << output.str();
}