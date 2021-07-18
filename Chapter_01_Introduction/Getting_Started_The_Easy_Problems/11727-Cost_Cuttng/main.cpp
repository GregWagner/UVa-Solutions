/*
 * 11727 Cost Cutting
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    std::vector<int> a(3);
    int testCase {};
    int testCases {};
    std::cin >> testCases;
    while (testCases-- != 0) {
        std::cin >> a[0] >> a[1] >> a[2];
        std::sort(a.begin(), a.end());
        output << "Case " << ++testCase << ": " << a[1] << '\n';
    }
    std::cout << output.str();
}
