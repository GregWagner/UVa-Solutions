#include <iostream>
#include <sstream>
#include <vector>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int W, N;
        std::cin >> W >> N;

        std::vector<int> x(N), w(N);
        for (int i{}; i < N; ++i) {
            std::cin >> x[i] >> w[i];
        }

        long long totalDistance{};
        int currentWeight{};
        int currentPos{};

        for (int i{}; i < N; ++i) {
            // Move to the next pick-up point
            totalDistance += (x[i] - currentPos);
            currentPos = x[i];

            // Check if adding this garbage exceeds capacity
            if (currentWeight + w[i] > W) {
                totalDistance += 2 * currentPos;
                currentWeight = 0; // Dumped
            }

            currentWeight += w[i];

            if (currentWeight == W) {
                if (i + 1 < N) {
                    totalDistance += 2 * currentPos;
                    currentWeight = 0;
                }
            }
        }
        if (currentWeight > 0) {
            totalDistance += currentPos;
        }
        output << totalDistance << "\n";
    }
    std::cout << output.str();
}
