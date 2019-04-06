/*
 * Rijeci
 */
#include <iostream>
#include <map>
#include <utility>

std::map<int, std::pair<int, int>> a {
    {1, std::make_pair(0, 1)},
    {2, std::make_pair(1, 1)},
    {3, std::make_pair(1, 2)},
    {4, std::make_pair(2, 3)},
    {5, std::make_pair(3, 5)},
    {6, std::make_pair(5, 8)},
    {7, std::make_pair(8, 13)},
    {8, std::make_pair(13, 21)},
    {9, std::make_pair(21, 34)},
    {10, std::make_pair(34, 55)},
    {11, std::make_pair(55, 89)},
    {12, std::make_pair(89, 144)},
    {13, std::make_pair(144, 233)},
    {14, std::make_pair(233, 377)},
    {15, std::make_pair(377, 610)},
    {16, std::make_pair(610, 987)},
    {17, std::make_pair(987, 1597)},
    {18, std::make_pair(1597, 2584)},
    {19, std::make_pair(2584, 4181)},
    {20, std::make_pair(4181, 6765)},
    {21, std::make_pair(6765, 10946)},
    {22, std::make_pair(10946, 17711)},
    {23, std::make_pair(17711, 28657)},
    {24, std::make_pair(28657, 46368)},
    {25, std::make_pair(46368, 75025)},
    {26, std::make_pair(75025, 121393)},
    {27, std::make_pair(121393, 196418)},
    {28, std::make_pair(196418, 317811)},
    {29, std::make_pair(317811, 514229)},
    {30, std::make_pair(514229, 832040)},
    {31, std::make_pair(832040, 1346269)},
    {32, std::make_pair(1346269, 2178309)},
    {33, std::make_pair(2178309, 3524578)},
    {34, std::make_pair(3524578, 5702887)},
    {35, std::make_pair(5702887, 9227465)},
    {36, std::make_pair(9227465, 14930352)},
    {37, std::make_pair(14930352, 24157817)},
    {38, std::make_pair(24157817, 39088169)},
    {39, std::make_pair(39088169, 63245986)},
    {40, std::make_pair(63245986, 102334155)},
    {41, std::make_pair(102334155, 165580141)},
    {42, std::make_pair(165580141, 267914296)},
    {43, std::make_pair(267914296, 433494437)},
    {44, std::make_pair(433494437, 701408733)},
    {45, std::make_pair(701408733, 1134903170)}};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::cout << a[n].first << ' ' << a[n].second << '\n';
}
