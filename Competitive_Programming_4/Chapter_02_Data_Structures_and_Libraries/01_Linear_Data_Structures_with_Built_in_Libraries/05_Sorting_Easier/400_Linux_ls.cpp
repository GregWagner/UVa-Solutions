#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    while (std::cin >> n) {
        std::vector<std::string> v(n);
        size_t maxLength{};
        for (int i{}; i < n; ++i) {
            std::cin >> v[i];
            maxLength = std::max(maxLength, v[i].length());
        }
        maxLength += 2; // Add padding for spacing  
        if (maxLength > 60) {
            maxLength = 60; // Limit the maximum length to 60 characters
        }

        std::sort(v.begin(), v.end());

        int numberOfColumns{ 62 / (static_cast<int>(maxLength)) };
        int numberOfRows{ (n - 1) / numberOfColumns + 1 };

        // Print out the filenames in the desired grid format
        std::cout << "------------------------------------------------------------\n";
        for (int i{}; i < numberOfRows; ++i) {
            for (int j{i}; j < n; j += numberOfRows) {
              // Print the filename, with padding to ensure proper column alignment
              std::cout << v[j];
              if (j + numberOfRows < n) {
                for (size_t k{ v[j].length() }; k < maxLength; ++k) {
                  std::cout << ' ';
                }
              }
            }
            std::cout << '\n';
        }
    }
}
