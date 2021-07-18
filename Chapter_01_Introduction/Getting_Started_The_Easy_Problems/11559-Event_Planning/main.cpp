/*
 * 11559 Event Planning
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int numberOfParticipants {};
    int budget {};
    int numberOfHotels {};
    int numberOfWeeks {};
    while (std::cin >> numberOfParticipants) {
        std::cin >> budget >> numberOfHotels >> numberOfWeeks;
        int lowestCost {20000};
        for (int i {}; i < numberOfHotels; ++i) {
            int cost {};
            std::cin >> cost;
            bool roomsAvailable {};
            for (int j {}; j < numberOfWeeks; ++j) {
                int rooms {};
                std::cin >> rooms;
                if (rooms >= numberOfParticipants) {
                    roomsAvailable = true;
                }
            }
            if (roomsAvailable && cost * numberOfParticipants <= budget
                    && cost < lowestCost) {
                lowestCost = cost;
            }
        }
        if (lowestCost == 20000) {
            output << "stay home\n";
        } else {
            output << lowestCost * numberOfParticipants << '\n';
        }
    }
    std::cout << output.str();
}
