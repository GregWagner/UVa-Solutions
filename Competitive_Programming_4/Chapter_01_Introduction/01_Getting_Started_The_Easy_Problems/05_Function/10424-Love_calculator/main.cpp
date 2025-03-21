/*
 * 10424  Love Calculator
 */
#include <iostream>
#include <sstream>
#include <iomanip>

int sumDigits(int n) {
    int sum {};
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int score(std::string &s) {
    int n {};
    for (auto c : s) {
        if (isalpha(c)) {
            n += tolower(c) - 'a' + 1;
        }
    }
    do {
        n = sumDigits(n);
    } while (n > 9);

//  std::cout << "score: " << n << '\n';
    return n;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    output << std::fixed << std::setprecision(2);

    std::string a;
    std::string b;
    while (std::getline(std::cin, a) && std::getline(std::cin, b)) {
        if (a.empty() || b.empty()) {
            continue;
        }
        int scoreA = score(a);
        int scoreB = score(b);
        output << (static_cast<double>(std::min(scoreA, scoreB)) / std::max(scoreA, scoreB)) * 100.0
            << " %\n";
    }
    std::cout << output.str();
}
