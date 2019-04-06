/*
 * Line Them Up
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string a[20] {};
    bool increasing {true};
    bool decreasing {true};
    int n;
    std::cin >> n;
    int index {};
    while (n--) {
        std::string temp;
        std::cin >> temp;
        a[index++] = temp;
    }
    for (int i {}; i < index - 1; ++i) {
        if (a[i] > a[i+1]) {
            increasing = false;
        }
        if (a[i] < a[i+1]) {
            decreasing = false;
        }
    }
    if (increasing) {
        std::cout << "INCREASING\n";
    } else if (decreasing) {
        std::cout << "DECREASING\n";
    } else {
        std::cout << "NEITHER\n";
    }
}
