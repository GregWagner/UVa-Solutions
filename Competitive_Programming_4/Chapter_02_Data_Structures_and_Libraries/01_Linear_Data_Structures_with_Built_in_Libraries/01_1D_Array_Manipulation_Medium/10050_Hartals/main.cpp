#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    int testCases{};
    std::cin >> testCases;
    while (testCases--) {
        int numberOfDays{};
        int numberOfParties{};
        std::cin >> numberOfDays >> numberOfParties;

        std::vector<bool> a(numberOfDays + 1, false);

        for (int i{}; i < numberOfParties; ++i) {
            int parameter{};
            std::cin >> parameter;
            for (int j{parameter}; j <= numberOfDays; j += parameter) {
                a[j] = true;
            }
        }
        int dayOfWeek{1};
        int count{};
        for (int i{1}; i <= numberOfDays; ++i) {
            if (dayOfWeek != 6 && dayOfWeek != 7) {
                count += a[i];
            }
            ++dayOfWeek;
            if (dayOfWeek > 7) {
                dayOfWeek = 1;
            }
        }
        output << count << '\n';
    }
    std::cout << output.str();
}
