/*
 * Goat Rope
 */
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int x, y, x1, y1, x2, y2;
    std::cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    int rightX = std::max(x1, x2);
    int leftX = std::min(x1, x2);
    int bottomY = std::min(y1, y2);
    int topY = std::max(y1, y2);

    double distance {};
       
    if (x >= rightX && y <= topY && y >= bottomY) {
        distance = x - rightX;
    } else if (x <= leftX && y <= topY && y >= bottomY) {
        distance = leftX - x;
    } else if (y <= bottomY && x >= leftX && x <= rightX) {
        distance = bottomY - y;
    } else if (y >= topY  && x >= leftX && x <= rightX) {
        distance = y - topY;
    } else if (x > rightX && y > topY) {
        double xDistance = std::abs(x - rightX);
        double yDistance = std::abs(topY - y);
        distance = std::sqrt((xDistance * xDistance) + (yDistance * yDistance));
    } else if (x > rightX && y < bottomY) {
        double xDistance = std::abs(x - rightX);
        double yDistance = std::abs(bottomY - y);
        distance = std::sqrt((xDistance * xDistance) + (yDistance * yDistance));
    } else if (x < leftX && y > topY) {
        double xDistance = std::abs(x - leftX);
        double yDistance = std::abs(topY - y);
        //std::cout << "3: " << xDistance << ", " << yDistance << '\n';
        distance = std::sqrt((xDistance * xDistance) + (yDistance * yDistance));
    } else if (x < leftX && y < bottomY) {
        double xDistance = std::abs(x - leftX);
        double yDistance = std::abs(bottomY - y);
        //std::cout << "4: " << xDistance << ", " << yDistance << '\n';
        distance = std::sqrt((xDistance * xDistance) + (yDistance * yDistance));
    }

    std::cout << std::setprecision(10) << distance << '\n';
}
