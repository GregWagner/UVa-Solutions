/*
 * 11799 Horror Dash
 */
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);

    std::ostringstream output;
    int testCase {};
    int testCases {};
    std::cin >> testCases;
    while (testCases-- != 0) {
        int clownSpeed = {};
        int numberOfStudents {};
        std::cin >> numberOfStudents;
        while (numberOfStudents-- != 0) {
            int speed {};
            std::cin >> speed;
            clownSpeed = std::max(clownSpeed, speed);
        }
        output << "Case " << ++testCase << ": " << clownSpeed << '\n';
    }
    std::cout << output.str();
}
