#include <cctype>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>

auto gcd(long long a, long long b) -> long long {
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }
    std::string dummy;
    std::getline(std::cin, dummy); // Consume rest of the line

    while (n--) {
        std::string line;
        if (!std::getline(std::cin, line)) {
            break;
        }

        long long totalNum{1};
        long long totalDen{1};

        size_t i{0};
        const size_t len{line.size()};
        while (i < len) {
            if (!std::isdigit(static_cast<unsigned char>(line[i]))) {
                ++i;
                continue;
            }

            size_t j{i};
            while (j < len && std::isdigit(static_cast<unsigned char>(line[j])))
                ++j;

            // try mixed fraction: a-b/c
            if (j < len && line[j] == '-' && j + 1 < len &&
                std::isdigit(static_cast<unsigned char>(line[j + 1]))) {
                size_t k{j + 1};
                while (k < len &&
                       std::isdigit(static_cast<unsigned char>(line[k])))
                    ++k;
                if (k < len && line[k] == '/' && k + 1 < len &&
                    std::isdigit(static_cast<unsigned char>(line[k + 1]))) {
                    size_t l{k + 1};
                    while (l < len &&
                           std::isdigit(static_cast<unsigned char>(line[l])))
                        ++l;

                    long long a{std::stoll(line.substr(i, j - i))};
                    long long b{std::stoll(line.substr(j + 1, k - (j + 1)))};
                    long long c{std::stoll(line.substr(k + 1, l - (k + 1)))};
                    if (c == 0)
                        c = 1;
                    long long num{a * c + b};
                    long long den{c};

                    totalNum *= num;
                    totalDen *= den;
                    i = l;
                    continue;
                }
            }

            // try simple fraction: a/b
            if (j < len && line[j] == '/' && j + 1 < len &&
                std::isdigit(static_cast<unsigned char>(line[j + 1]))) {
                size_t l{j + 1};
                while (l < len &&
                       std::isdigit(static_cast<unsigned char>(line[l])))
                    ++l;

                long long a{std::stoll(line.substr(i, j - i))};
                long long b{std::stoll(line.substr(j + 1, l - (j + 1)))};
                if (b == 0)
                    b = 1;
                totalNum *= a;
                totalDen *= b;
                i = l;
                continue;
            }

            // integer
            long long a{std::stoll(line.substr(i, j - i))};
            totalNum *= a;
            i = j;
        }

        long long g{gcd(totalNum, totalDen)};
        if (g == 0)
            g = 1;
        totalNum /= g;
        totalDen /= g;

        if (totalDen == 1) {
            output << totalNum << '\n';
        } else if (totalNum < totalDen) {
            output << totalNum << '/' << totalDen << '\n';
        } else {
            long long whole{totalNum / totalDen};
            long long rem{totalNum % totalDen};
            if (rem == 0) {
                output << whole << '\n';
            } else {
                output << whole << '-' << rem << '/' << totalDen << '\n';
            }
        }
    }

    std::cout << output.str();
}
