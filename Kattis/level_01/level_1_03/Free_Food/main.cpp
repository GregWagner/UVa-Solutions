/*
 * Free Food
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    bool food[370] {};
    int n;
    std::cin >> n;
    while (n--) {
        int start, end;
        std::cin >> start >> end;
        for (int i {start}; i <= end; ++i) {
            food[i] = true;
        }
    }
    int count {};
    for (int i = 0; i < 370; ++i) {
        if (food[i]) {
            ++count;
        }
    }
    std::cout << count << '\n';
}
