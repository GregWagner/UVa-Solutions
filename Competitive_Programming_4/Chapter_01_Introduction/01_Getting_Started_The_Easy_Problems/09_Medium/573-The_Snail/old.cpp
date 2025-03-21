/*
 * Problem 573 - The Snail
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int height;
    while (std::cin >> height && height != 0) {
        double climbingDistance;
        double slidingDistance, fatigueFactor;
        std::cin >> climbingDistance >> slidingDistance >> fatigueFactor;
        int day {};
        double currentHeight {};
        double fatigue = climbingDistance * (fatigueFactor / 100.0);
        while (true) {
            ++day;
            currentHeight += climbingDistance;
            if (currentHeight > height) {
                output << "success on day " << day << '\n';
                break;
            }
            currentHeight -= slidingDistance;
            if (currentHeight < 0) {
                output << "failure on day " << day << '\n';
                break;
            }
            climbingDistance -= fatigue;
            climbingDistance = (climbingDistance < 0 ? 0 : climbingDistance);
        }
    }
    std::cout << output.str();
}
