// 12019 Doms Day Algorithm
#include <array>
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    constexpr std::array<int, 12> doomsDays{10, 21, 7, 4, 9, 6, 11, 8, 5, 10, 7, 12};
    const std::array<const char*, 7> dayNames{
        "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    std::ostringstream output;

    int testCases{};
    std::cin >> testCases;
    while (testCases--) {
        int month, day;
        std::cin >> month >> day;
        auto diff{day - doomsDays[month - 1]};
        auto dayOfWeek = ((diff % 7) + 7) % 7;
        output << dayNames[dayOfWeek] << '\n';
    }
    std::cout << output.str();
}
