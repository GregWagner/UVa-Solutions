#include <iostream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::string month;
    int day;
    std::cin >> month >> day;
    if ((month == "OCT" && day == 31) || (month == "DEC" && day == 25)) {
        std::cout << "yup\n";
    } else {
        std::cout << "nope\n";
    }
}