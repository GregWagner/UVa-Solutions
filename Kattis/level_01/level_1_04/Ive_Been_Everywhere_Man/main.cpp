/*
 * I've Been everywhere, Man
 */
#include <iostream>
#include <sstream>
#include <set>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        std::set<std::string> s;
        int trips;
        std::cin >> trips;
        while (trips--) {
            std::string city;
            std::cin >> city;
            s.insert(city);
        }
        output << s.size() << '\n';
    }
    std::cout << output.str();
}
