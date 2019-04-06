/*
 * Cudoviste
 */
#include <iostream>
#include <sstream>

// #    building
// x    parked car
// .    free space

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    char a[50][50] {};

    std::ostringstream output;
    int row, column;
    std::cin >> row >> column;
    for (int i {}; i < row; ++i) {
        for (int j {}; j < column; ++j) {
            char c;
            std::cin >> c;
            a[i][j] = c;
        }
    }
    int counts[10] {};
    int free;
    int car;
    bool building {};
    for (int i {}; i < row - 1; ++i) {
        for (int j {}; j < column - 1; ++j) {

//            std::cout << "Checking " << i << ", " << j << '\n';
            free = 0;
            car = 0;
            building = false;

            if (a[i][j] == '#') {
//                std::cout << "Building at " << i << ": " << j << '\n';
                building = true;
                continue;
            } else if (a[i][j] == '.') {
//                std::cout << "Free at " << i << ": " << j << '\n';
                ++free;
            } else {
//                std::cout << "Car at " << i << ": " << j << '\n';
                ++car;
            }
            if (a[i][j+1] == '#') {
//                std::cout << "Building at " << i << ": " << j+1 << '\n';
                building = true;
                continue;
            } else if (a[i][j+1] == '.') {
//                std::cout << "Free at " << i << ": " << j+1 << '\n';
                ++free;
            } else {
//                std::cout << "Car at " << i << ": " << j+1 << '\n';
                ++car;
            }
            if (a[i+1][j] == '#') {
//                std::cout << "Building at " << i+1 << ": " << j << '\n';
                building = true;
                continue;
            } else if (a[i+1][j] == '.') {
//                std::cout << "Free at " << i+1 << ": " << j << '\n';
                ++free;
            } else {
//                std::cout << "Car at " << i+1 << ": " << j << '\n';
                ++car;
            }
            if (a[i+1][j+1] == '#') {
//                std::cout << "Building at " << i+1 << ": " << j+1 << '\n';
                building = true;
                continue;
            } else if (a[i+1][j+1] == '.') {
//                std::cout << "Free at " << i+1 << ": " << j+1 << '\n';
                ++free;
            } else {
//                std::cout << "Car at " << i+1 << ": " << j+1 << '\n';
                ++car;
            }
            if (!building) {
                if (free == 4) {
//                    std::cout << "All 4 free\n";
                    ++counts[0];
                } else {
//                    std::cout << car << " cars to crush\n";
                    ++counts[car];
                }
            }
        }
    }
    for (int i {}; i <= 4; ++i) {
        output << counts[i] << '\n';
    }
    std::cout << output.str();
}
