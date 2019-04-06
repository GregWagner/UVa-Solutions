/*
 * The Easiest Problem is this One
 */
#include <iostream>
#include <sstream>

int sumOfDigits(int n) {
    int sum {};
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int n;
    while (std::cin >> n) {
        if (n == 0) {
            break;
        }
        int goal = sumOfDigits(n);
        int index {11};
        while (true) {
            if (sumOfDigits(index * n) == goal) {
                output << index << '\n';
                break;
            }
            ++index;
        }
    }
    std::cout << output.str();
}
