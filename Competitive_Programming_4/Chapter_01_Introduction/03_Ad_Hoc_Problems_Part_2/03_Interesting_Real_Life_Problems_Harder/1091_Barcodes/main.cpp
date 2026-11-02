// 1091 - Barcodes
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

auto mapToCharacter(int number) -> int {
    int encoded[] = {1, 17, 9, 24, 5, 20, 12, 3, 18, 16, 4, 6};
    for (int i{}; i < 12; ++i) {
        if (number == encoded[i]) {
            return i;
        }
    }
    return -1;
}

auto goodWidths(const std::vector<int>& readings, double separator) -> bool {
    int lowest{201}, highest{};
    for (int i{}; i < (int)readings.size(); ++i) {
        int val{readings[i]};
        if (val < separator) {
            val *= 2;
        }
        if (val < lowest) {
            lowest = val;
        }
        if (val > highest) {
            highest = val;
        }
    }
    return lowest >= 95.0 * highest / 105.0;
}

auto decode(const std::vector<int>& readings, int pos, double separator)
    -> int {
    int num{};
    for (int i{pos}; i < pos + 5; ++i) {
        num = (num << 1) | (readings[i] >= separator ? 1 : 0);
    }
    return mapToCharacter(num);
}

auto transform(const std::vector<int>& readings, double separator,
               std::vector<int>& transformed) -> bool {
    int start_stop_count{};
    for (int i{}; i < (int)readings.size(); i += 6) {
        int character = decode(readings, i, separator);
        if (character == -1) {
            return false;
        }
        if (character == 11) {
            ++start_stop_count;
        }
        transformed.push_back(character);
        if (i + 5 < (int)readings.size() && readings[i + 5] >= separator) {
            return false;
        }
    }
    return start_stop_count == 2 && transformed.front() == 11 &&
           transformed.back() == 11;
}

auto checkC(const std::vector<int>& transformed, int c) -> bool {
    int expected{};
    int n{(int)transformed.size() - 4};
    for (int i{1}; i <= n; ++i) {
        expected += ((n - i) % 10 + 1) * transformed[i];
    }
    return expected % 11 == c;
}

auto checkK(const std::vector<int>& transformed, int c, int k) -> bool {
    int expected{};
    int n{(int)transformed.size() - 4};
    for (int i{1}; i <= n; ++i) {
        expected += ((n - i + 1) % 9 + 1) * transformed[i];
    }
    expected += c;
    return expected % 11 == k;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int m{}, case_number{};
    while (std::cin >> m && m != 0) {
        std::vector<int> readings(m);
        int lowest{201};
        for (int i{}; i < m; ++i) {
            std::cin >> readings[i];
            if (readings[i] < lowest) {
                lowest = readings[i];
            }
        }

        output << "Case " << ++case_number << ": ";

        if ((m + 1) % 6 != 0 || (m + 1) / 6 < 5) {
            output << "bad code\n";
            continue;
        }

        double separator = lowest * 1.5;
        if (!goodWidths(readings, separator)) {
            output << "bad code\n";
            continue;
        }

        if (readings[1] >= separator) {
            std::reverse(readings.begin(), readings.end());
        }

        std::vector<int> transformed;
        if (!transform(readings, separator, transformed)) {
            output << "bad code\n";
            continue;
        }

        int c{transformed[(int)transformed.size() - 3]};
        int k{transformed[(int)transformed.size() - 2]};

        if (!checkC(transformed, c)) {
            output << "bad C\n";
        } else if (!checkK(transformed, c, k)) {
            output << "bad K\n";
        } else {
            for (int i{1}; i < (int)transformed.size() - 3; ++i) {
                if (transformed[i] == 10) {
                    output << '-';
                } else {
                    output << transformed[i];
                }
            }
            output << '\n';
        }
    }
    std::cout << output.str();
}
