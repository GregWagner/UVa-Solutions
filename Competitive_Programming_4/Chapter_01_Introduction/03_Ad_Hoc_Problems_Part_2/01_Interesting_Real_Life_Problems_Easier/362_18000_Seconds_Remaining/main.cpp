// 362 - 18,000 Seconds Remaining
#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int totalBytes{};
    int dataSet{1};
    while (std::cin >> totalBytes && totalBytes != 0) {
        std::cout << "Output for data set " << dataSet++ << ", " << totalBytes
                  << " bytes:\n";

        int transferred{};
        int seconds{};
        int lastFive{};
        while (transferred < totalBytes) {
            int bytesThisSecond{};
            std::cin >> bytesThisSecond;
            transferred += bytesThisSecond;
            lastFive += bytesThisSecond;
            ++seconds;

            if (seconds % 5 == 0) {
                if (lastFive == 0) {
                    std::cout << "   Time remaining: stalled\n";
                } else {
                    long long remaining = totalBytes - transferred;
                    long long est = (remaining * 5 + lastFive - 1) / lastFive;
                    std::cout << "   Time remaining: " << est << " seconds\n";
                }
                lastFive = 0;
            }
        }
        std::cout << "Total time: " << seconds << " seconds\n\n";
    }
}
