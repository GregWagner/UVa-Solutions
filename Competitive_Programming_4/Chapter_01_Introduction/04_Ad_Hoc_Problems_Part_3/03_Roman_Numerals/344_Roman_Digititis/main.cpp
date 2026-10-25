// 344 roman Digitits
#include <iostream>
#include <sstream>

auto getRoman(int n) -> std::string {
    std::string result;
    while (n > 0) {
        if (n >= 100) {
            result += "C";
            n -= 100;
        } else if (n >= 90) {
            result += "XC";
            n -= 90;
        } else if (n >= 50) {
            result += "L";
            n -= 50;
        } else if (n >= 40) {
            result += "XL";
            n -= 40;
        } else if (n >= 10) {
            result += "X";
            n -= 10;
        } else if (n >= 9) {
            result += "IX";
            n -= 9;
        } else if (n >= 5) {
            result += "V";
            n -= 5;
        } else if (n >= 4) {
            result += "IV";
            n -= 4;
        } else if (n >= 1) {
            result += "I";
            n -= 1;
        }
    }
    return result;
}

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ostringstream output;
    int n;
    while (std::cin >> n && n != 0) {

        int frequencyCounter[] = {0, 0, 0, 0, 0};
        for (int i{1}; i <= n; ++i) {
            std::string roman = getRoman(i);
            for (char c : roman) {
                if (c == 'I') {
                    ++frequencyCounter[0];
                } else if (c == 'V') {
                    ++frequencyCounter[1];
                } else if (c == 'X') {
                    ++frequencyCounter[2];
                } else if (c == 'L') {
                    ++frequencyCounter[3];
                } else if (c == 'C') {
                    ++frequencyCounter[4];
                }
            }
        }

        output << n << ": " << frequencyCounter[0] << " i, "
               << frequencyCounter[1] << " v, " << frequencyCounter[2] << " x, "
               << frequencyCounter[3] << " l, " << frequencyCounter[4] << " c\n";
    }

    std::cout << output.str();
}