/*
 * 11364 Parking
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int testCases {};
    std::cin >> testCases;
    while (testCases-- != 0) {
        int minStore {100};
        int maxStore {-1};
        int numberOfStores {};
        std::cin >> numberOfStores;
        while (numberOfStores-- != 0) {
            int store {};
            std::cin >> store;
            minStore = std::min(store, minStore);
            maxStore = std::max(store, maxStore);
        }
        output << 2 * (maxStore - minStore) << '\n';
    }
    std::cout << output.str();
}
