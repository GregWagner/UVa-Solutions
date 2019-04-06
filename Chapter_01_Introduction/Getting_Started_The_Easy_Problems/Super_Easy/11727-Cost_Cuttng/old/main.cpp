/*
 * Problem 11727 - Cost Cutting
 */
#include <iostream>
#include <sstream>
#include <algorithm>

int main()
{
    std::ostringstream output;

    int a[3];
    int test = 1;
    int testCases;
    std::cin >> testCases;

    while (testCases--) {
        std::cin >> a[0] >> a[1] >> a[2];
        std::sort(a, a + 3);

        output << "Case " << test++ << ": " << a[1] << '\n';
    }
    std::cout << output.str();
}
