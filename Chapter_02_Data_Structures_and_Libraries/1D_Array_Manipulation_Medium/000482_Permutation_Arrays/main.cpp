#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    int testCases {};
    std::cin >> testCases;
    std::string s;
    std::getline(std::cin, s);
    while (testCases--) {
        std::getline(std::cin, s);

        std::string permutations;
        std::getline(std::cin, permutations);

        std::string s;
        std::getline(std::cin, s);
        std::stringstream ss(s);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> array(begin, end);

        std::vector<std::string> results(array.size());

        std::istringstream is(permutations);
        int n;
        for (size_t i {}; i < array.size(); ++i) {
            is >> n;
            results[n - 1] = array[i];
        }

        for (const std::string& e : results) {
            output << e << '\n';
        }
        if (testCases > 0) {
            output << '\n';
        }
    }
    std::cout << output.str();
}
