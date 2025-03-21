/*
 * 119 Greedy Giftgivers
 */
#include <iostream>
#include <sstream>
#include <map>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    bool first {true};
    std::string name;
    int size {};
    while (std::cin >> size) {
        std::vector<std::string> names;
        std::map<std::string, int> d;
        for (int i = 0; i < size; ++i) {
            std::cin >> name;
            d[name] = 0;
            names.push_back(name);
        }
        for (int i {}; i < size; ++i) {
            int amount {};
            int people {};
            std::cin >> name >> amount >> people;
            int amountPerPerson = (people ? amount / people : 0);
            for (int j {}; j < people; ++j) {
                std::string to;
                std::cin >> to;
                d[to] += amountPerPerson;
                d[name] -= amountPerPerson;
            }
        }
        output << (first ? "" : "\n");
        first = false;
        for (const auto &name : names) {
            output << name << ' ' << d[name] << '\n';
        }
    }
    std::cout << output.str();
}
