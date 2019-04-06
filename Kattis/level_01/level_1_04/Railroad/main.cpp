/*
 * Railroad
 * even Y and odd x
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int x, y;
    std::cin >> x >> y;

    std::cout << (y % 2 == 0 ?  "possible\n" : "impossible\n");
}
