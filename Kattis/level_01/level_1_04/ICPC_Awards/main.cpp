/*
 * ICPC Awards
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::vector<std::string> a;

    std::ostringstream output;
    int n;
    std::cin >> n;
    for (int i {}; i < n; ++i) {
        std::string college, dept;
        std::cin >> college >> dept;
        if (a.size() < 12) {
            if (std::find(a.begin(), a.end(), college) == a.end()) {
                a.push_back(college);
                output << college << ' ' << dept << '\n';
            }
        }
    }
    std::cout << output.str();
}
