/*
 * Problem 10325 - Zeros and Ones
 */
#include <iostream>
#include <sstream>

bool arr[1000005];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int test {};
    std::string s;
    while (std::cin >> s) {
        output << "Case " << ++test << ":\n";
        for (size_t i {}; i < s.size(); ++i) {
            arr[i] = s[i] == '0';
        }
        int numberOfQueries;
        std::cin >> numberOfQueries;
        for (int i {}; i < numberOfQueries; ++i) {
            int a, b;
            std::cin >> a >> b;
            int start = std::min(a, b);
            int end = std::max(a, b);
            bool match {true};
            while (start <= end) {
                if (arr[start] != arr[end]) {
                    match = false;
                    break;
                }
                ++start;
            }
            output << (match ? "Yes" : "No") << '\n';
        }
    }
    std::cout << output.str();
}
