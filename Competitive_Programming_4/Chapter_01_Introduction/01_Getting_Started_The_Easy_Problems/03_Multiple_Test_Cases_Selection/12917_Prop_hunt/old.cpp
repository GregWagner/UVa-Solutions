#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::ostringstream output;
    int numberOfProps {};
    int numberOfHunters {};
    int objectsToDisguise {};
    while (std::cin >> numberOfProps >> numberOfHunters >> objectsToDisguise) {
        while (numberOfHunters != 0 && numberOfProps != 0) {
            if (objectsToDisguise > numberOfProps) {
                --numberOfHunters;
                --objectsToDisguise;
            } else {
                --numberOfProps;
                --objectsToDisguise;
            }
        }
        output << (numberOfProps == 0 ? "Hunters win!\n" : "Props win!\n");
    }
    std::cout << output.str();
}
