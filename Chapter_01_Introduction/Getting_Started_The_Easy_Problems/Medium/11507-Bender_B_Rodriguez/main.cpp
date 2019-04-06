/*
 * Problem 11507 - Bender B. Rodriguex
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int length;
    while (std::cin >> length && length != 0) {
        int x {1}, y {}, z {};
        for (int i = 1; i < length; ++i) {
            std::string op;
            std::cin >> op;

            // x = 1, y = 0, z = 0
            if (x == 1) {
                if (op == "+y") {
                    x = 0; y = 1;
                } else if (op == "-y") {
                    x = 0; y = -1;
                } else if (op == "+z") {
                    x = 0; z = 1;
                } else if (op == "-z") {
                    x = 0; z = -1;
                }

            // x = -1, y = 0, z = 0
            } else if (x == -1) {
                if (op == "+y") {
                    x = 0; y = -1;
                } else if (op == "-y") {
                    x = 0; y = 1;
                } else if (op == "+z") {
                    x = 0; z = -1;
                } else if (op == "-z") {
                    x = 0; z = 1;
                }

            // x = 0, y = 1, z = 0
            } else if (y == 1) {
                if (op == "+y") {
                    x = -1; y = 0;
                } else if (op == "-y") {
                    x = 1; y = 0;
                }

            // x = 0, y = -1, z = 0
            } else if (y == -1) {
                if (op == "+y") {
                    x = 1; y = 0;
                } else if (op == "-y") {
                    x = -1; y = 0;
                }

            // x = 0, y = 0, z = 1
            } else if (z == 1) {
                if (op == "+z") {
                    x = -1; z = 0;
                } else if (op == "-z") {
                    x = 1; z = 0;
                }

            // x = 0, y = 0, z = -1
            } else if (z == -1) {
                if (op == "+z") {
                    x = 1; z = 0;
                } else if (op == "-z") {
                    x = -1; z = 0;
                }
            }
        }

        if (x == 1) {
            output << "+x\n";
        } else if (x == -1) {
            output << "-x\n";
        } else if (y == 1) {
            output << "+y\n";
        } else if (y == -1) {
            output << "-y\n";
        } else if (z == 1) {
            output << "+z\n";
        } else if (z == -1) {
            output << "-z\n";
        }
    }
    std::cout << output.str();
}
