#include <iostream>
#include <sstream>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int numberOfSamples;
    while (std::cin >> numberOfSamples && numberOfSamples != 0) {
        std::vector<int> samples(numberOfSamples);
        int sample;
        for (int i{}; i < numberOfSamples; ++i) {
            std::cin >> sample;
            samples[i] = sample;
        }
        int peakCount{};
        for (int i{}; i < numberOfSamples; ++i) {
            int previous = samples[(i - 1 + numberOfSamples) % numberOfSamples];
            int current = samples[i];
            int next = samples[(i + 1) % numberOfSamples];
            if ((current > previous && current > next) ||
                (current < previous && current < next)) {
                ++peakCount;
            }
        }
        output << peakCount << '\n';
    }
    std::cout << output.str();
}
