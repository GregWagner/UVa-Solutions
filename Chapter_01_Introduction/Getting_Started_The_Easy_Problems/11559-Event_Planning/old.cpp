/*
 * Problem 11559 - Event Planning
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio();
    std::cin.tie(0);

    std::ostringstream output;
    int participants;
    int budget;
    int hotels;
    int weeks;
    while (std::cin >> participants >> budget >> hotels >> weeks) {
        int cheapest = budget + 1;
        for (int i = 0; i < hotels; ++i) {
            int pricePerPerson;
            std::cin >> pricePerPerson;
            int cost {pricePerPerson * participants};
            bool inBudget = cost <= budget;
            bool vacancy {};
            for (int j = 0; j < weeks; ++j) {
                int rooms;
                std::cin >> rooms;
                if (rooms >= participants) {
                    vacancy = true;
                }
            }
            cheapest = (inBudget && vacancy && cost < cheapest) ? cost : cheapest;
        }
        if (cheapest > budget) {
            output << "stay home\n";
        } else {
            output << cheapest << '\n';
        }
    }
    std::cout << output.str();
}
