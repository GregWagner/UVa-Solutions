/*
 * Problem 278 - Chess
 */
#include <iostream>
#include <sstream>

int rookOrQueen[][7] = {
    // anwer is the std::min(row, column)
    {4, 4, 4, 4, 4, 4, 4 },
    {4, 5, 5, 5, 5, 5, 5 },
    {4, 5, 6, 6, 6, 6, 6 },
    {4, 5, 6, 7, 7, 7, 7 },
    {4, 5, 6, 7, 8, 8, 8 },
    {4, 5, 6, 7, 8, 9, 9 },
    {4, 5, 6, 7, 8, 9, 10 }};

int knight[][7] = {
    // number of balck squares in the chess board
    {8, 10, 12, 14, 16, 18, 20},
    {10, 13, 15, 18, 20, 23, 25},
    {12, 15, 18, 21, 24, 27, 30},
    {14, 18, 21, 25, 28, 32, 35},
    {16, 20, 24, 28, 32, 36, 40},
    {18, 23, 27, 32, 36, 41, 45},
    {20, 25, 30, 35, 40, 45, 50}};

int king[][7] = {
    // same as knight but skip alternate row
    {4, 6, 6, 8, 8, 10, 10},
    {6, 9, 9, 12, 12, 15, 15},
    {6, 9, 9, 12, 12, 15, 15},
    {8, 12, 12, 16, 16, 20, 20},
    {8, 12, 12, 16, 16, 20, 20},
    {10, 15, 15, 20, 20, 25, 25},
    {10, 15, 15, 20, 20, 25, 25}};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int numberOfProblems;
    std::cin >> numberOfProblems;
    while (numberOfProblems--) {
        char piece;
        int x, y;
        std::cin >> piece >> x >> y;
        x -= 4;
        y -= 4;
        switch (piece) {
            case 'Q':
            case 'r':
                output << rookOrQueen[x][y] << '\n';
                break;
            case 'k':
                output << knight[x][y] << '\n';
                break;
            case 'K':
                output << king[x][y] << '\n';
                break;
        }
    }
    std::cout << output.str();
}
