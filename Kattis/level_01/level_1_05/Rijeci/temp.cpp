/*
 * Rijeci (generates answers)
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string s {"A"};
    for (int z {45}; z <= 45; ++z) {
        s  = "A";
        std::string newString {};
        int n {z};
        while (n--) {
            newString = "";
            for (size_t i {}; i < s.length(); ++i) {
                newString += (s[i] == 'A' ? "B" : "BA");
            }
            s = newString;
        }
        int aCount {};
        int bCount {};
        for (size_t i {}; i < s.length(); ++i) {
            if (s[i] == 'A') {
                ++aCount;
            } else {
                ++bCount;
            }
        }
        std::cout << z << " " << aCount << ' ' << bCount << std::endl;
    }
}
