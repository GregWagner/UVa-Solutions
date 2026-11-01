// 12808 Banning Balconing
#include <cmath>
#include <iostream>
#include <sstream>

auto main() -> int {
    const double g{9810.0}; // mm/s^2 (9.81 m/s^2)

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        long long poolLength, horizontalDistance, height, speed;
        std::cin >> poolLength >> horizontalDistance >> height >> speed;

        // time to fall from height H (mm): t = sqrt(2*H/g)
        double time = std::sqrt(2.0 * static_cast<double>(height) / g);

        // horizontal landing distance in mm
        double landingDistance = static_cast<double>(speed) * time;

        double nearEdge = std::fabs(landingDistance -
                                    static_cast<double>(horizontalDistance));
        double farEdge =
            std::fabs(landingDistance -
                      static_cast<double>(horizontalDistance + poolLength));

        if (nearEdge <= 500.0 + 1e-6 || farEdge <= 500.0 + 1e-6) {
            output << "EDGE\n";
        } else if (landingDistance > static_cast<double>(horizontalDistance) &&
                   landingDistance <
                       static_cast<double>(horizontalDistance + poolLength)) {
            output << "POOL\n";
        } else {
            output << "FLOOR\n";
        }
    }
    std::cout << output.str();
}