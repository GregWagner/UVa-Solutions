/*
 * Problem 119 Greedy Gift Givers
 */
#include <iostream>
#include <sstream>
#include <vector>

struct People {
    std::string name;
    int worth;
};

People people[12];
int groupSize {};

void update(std::string name, int amount) {
    for (int i = 0; i < groupSize; ++i) {
        if (people[i].name == name) {
            people[i].worth += amount;
            return;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    bool first {true};
    while (std::cin >> groupSize) {
        for (int i = 0; i < groupSize; ++i) {
            std::cin >> people[i].name;
            people[i].worth = 0;
        }

        for (int i = 0; i < groupSize; ++i) {
            std::string from;
            int amount, count;
            std::cin >> from >> amount >> count;
            int forEach = (count == 0 ? 0 : amount / count);
            update(from, -(forEach * count));
            for (int j = 0; j < count; ++j) {
                std::string to;
                std::cin >> to;
                update(to, forEach);
            }
        }
        output << (first ? "" : "\n");
        first = false;
        for (int i = 0; i < groupSize; ++i) {
            output << people[i].name << ' ' << people[i].worth << '\n';
        }
    }
    std::cout << output.str();
}
