/*
 * Skocimis
 */
#include <iostream>

void sort(int &a, int &b, int &c) {
    if (a < b && b < c) {
        return;
    }
    int tempA = std::min(a, std::min(b, c));
    int tempC = std::max(a, std::max(b, c));
    int tempB = (a + b + c) - tempA - tempC;
    a = tempA;
    b = tempB;
    c = tempC;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int a, b, c;
    std::cin >> a >> b >> c;
    sort(a, b, c);
    int origA = a;
    int origB = b;
    int origC = c;
    int firstCount {};
    bool moveMade {true};
    while (moveMade) {
        moveMade = false;
        if (c - b > 1) {
            int temp  = b;
            b = c - 1;
            a = temp;
            ++firstCount;
            moveMade = true;
        }
        if (b - a > 1) {
            int temp = b;
            b = a + 1;
            c = temp;
            ++firstCount;
            moveMade = true;
        }
    }

    a = origA;
    b = origB;
    c = origC;
    int secondCount {};
    moveMade = true;
    while (moveMade) {
        moveMade = false;
        if (b - a > 1) {
            int temp = b;
            b = a + 1;
            c = temp;
            ++secondCount;
            moveMade = true;
        }
        if (c - b > 1) {
            int temp  = b;
            b = c - 1;
            a = temp;
            ++secondCount;
            moveMade = true;
        }
    }
    std::cout << std::max(firstCount, secondCount) << '\n';
}
