/*
 * 579 Clock Hands
 */
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ostringstream output;

    int hour{}, min{};
    char colon;
    while (std::cin >> hour >> colon >> min && (hour != 0 || min != 0)) {
        double minuteAngle{6.0 * min};
        double hourAngle{30.0 * hour + 0.5 * min};
        double diff{std::fabs(hourAngle - minuteAngle)};
        if (diff > 180) {
            diff = 360 - diff;
        }
        output << std::fixed << std::setprecision(3) << diff << '\n';
    }

    std::cout << output.str();
}
