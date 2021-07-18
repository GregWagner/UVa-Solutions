/*
 * 12289 One-Two-Three
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int testCases {};
    std::cin >> testCases;
    while (testCases-- != 0) {
        std::string s;
        std::cin >> s;
        if (s.size() == 5) {
            output << "3\n";
        } else if (s[0] == 'o') {
            if (s[1] == 'n' || s[2] == 'e') {
                output << "1\n";
            } 
        } else if (s[1] == 'n') {
            if (s[0] == 'o' || s[2] == 'e') {
                output << "1\n";
            } 
        } else if (s[3] == 'e') {
            if (s[0] == 'o' || s[1] == 'n') {
                output << "1\n";
            } 
        } else {
            output << "2\n";
        }
    }
    std::cout << output.str();
}
