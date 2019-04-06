/*
 * 10424 - Love Calculator
 */

#include <iostream>
#include <sstream>
#include <map>

std::map<char, int> a;

int sumDigits(int number)
{
    int result = 0;
    while (number >= 10) {
        result += (number % 10);
        number /= 10;
    }
    return result += number;
}

int calc(std::string name) {
    int results = 0;

    for (size_t i = 0; i < name.size(); ++i) {
        results += a[std::tolower(name[i])];
    }
    while (results >= 10) {
        results = sumDigits(results);
    }
    return results;
}

int main() {
    std::ostringstream output;
    output.precision(2);
    std::string first, second;

    int i = 1;
    for (char c = 'a'; c <= 'z'; ++c) {
        a[c] = i++;
    }

    while (std::getline(std::cin, first)) {
        std::getline(std::cin, second);

        int one = calc(first);
        int two = calc(second);
        double result;
        if (two > one) {
            result = ((double)one / two) * 100;
        } else {
            result = ((double)two / one) * 100;
        }
        if (one == 0 && two == 0) {
            output << '\n';
        } else if (result >= 100) {
            output << "100.00 %\n";
        } else {
            output << std::fixed << result << " %\n";
        }
    }
    std::cout << output.str();
}
