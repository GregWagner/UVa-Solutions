/*
 * Problem 278 - Chess
 */
#include <iostream>
#include <sstream>
#include <cmath>

int k[7][7] = {{ 8, 10, 12, 14, 16, 18, 20},
    {10, 13, 15, 18, 20, 23, 25},
    {12, 15, 18, 21, 24, 27, 30},
    {14, 18, 21, 25, 28, 32, 35},
    {16, 20, 24, 28, 32, 36, 40},
    {18, 23, 27, 32, 36, 41, 45},
    {20, 25, 30, 35, 40, 45, 50}};

int r[7][7] = { {4, 4, 4, 4, 4, 4, 4},
    {4, 5, 5, 5, 5, 5, 5},
    {4, 5, 6, 6, 6, 6, 6},
    {4, 5, 6, 7, 7, 7, 7},
    {4, 5, 6, 7, 8, 8, 8},
    {4, 5, 6, 7, 8, 9, 9},
    {4, 5, 6, 7, 8, 9, 10}};

int main()
{
    std::ios::sync_with_stdio(false);
    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        char p;
        int x, y;
        std::cin >> p >> x >> y;

        if (p == 'r') {
            output << r[x - 4][y - 4]<< '\n';
        } else if (p == 'k') {
            output << k[x - 4][y - 4]<< '\n';
        } else if (p == 'Q') {
            if (x > y) {
                output << y << '\n';
            } else {
                output << x << '\n';
            }
        } else if (p == 'K') {
            output << ((std::ceil(x / 2.0) * std::ceil(y / 2.0))) << '\n';
        }
    }
    std::cout << output.str();
}
