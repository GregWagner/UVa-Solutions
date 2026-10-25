// 11219 How old are you
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testNumber{};
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        output << "Case #" << ++testNumber << ": ";
        // First date line is the CURRENT date; second is the BIRTH date.
        int todayDay, todayMonth, todayYear;
        char delimiter;
        std::cin >> todayDay >> delimiter >> todayMonth >> delimiter >>
            todayYear;

        int birthDay, birthMonth, birthYear;
        std::cin >> birthDay >> delimiter >> birthMonth >> delimiter >>
            birthYear;

        if (birthYear > todayYear ||
            (birthYear == todayYear && birthMonth > todayMonth) ||
            (birthYear == todayYear && birthMonth == todayMonth &&
             birthDay > todayDay)) {
            output << "Invalid birth date\n";
            continue;
        }
        auto age = todayYear - birthYear;
        if (todayMonth < birthMonth ||
            (todayMonth == birthMonth && todayDay < birthDay)) {
            age--;
        }

        if (age > 130) {
            output << "Check birth date\n";
        } else {
            output << age << "\n";
        }
    }
    std::cout << output.str();
}
