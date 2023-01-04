#include <iostream>
#include <sstream>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    int n {};
    std::cin >> n;
    while (n--) {
        int budget {};
        int number_of_farmers {};
        std::cin >> number_of_farmers;
        while (number_of_farmers--) {
            int size {};
            int number_of_animals {};
            int friendliness {};
            std::cin >> size >> number_of_animals >> friendliness;
            budget += size * friendliness;
        }
        output << budget << '\n';
    }
    std::cout << output.str();
}
