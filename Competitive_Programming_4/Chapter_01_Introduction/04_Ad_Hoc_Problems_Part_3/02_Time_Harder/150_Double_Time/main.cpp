#include <array>
#include <iostream>
#include <sstream>
#include <string>

struct Date {
    int d{0};
    int m{0};
    int y{0};
};

auto monthNameToNumber(const std::string& name) -> int {
    static const std::array<std::string, 12> months{
        {"January", "February", "March", "April", "May", "June", "July",
         "August", "September", "October", "November", "December"}};
    for (int i{0}; i < 12; ++i) {
        if (months[i] == name) {
            return i + 1;
        }
    }
    return 1;
}

auto monthNumberToName(int m) -> std::string {
    static const std::array<std::string, 12> months{
        {"January", "February", "March", "April", "May", "June", "July",
         "August", "September", "October", "November", "December"}};
    if (m >= 1 && m <= 12) {
        return months[m - 1];
    }
    return "";
}

auto dowNameToIndex(const std::string& name) -> int {
    if (name == "Monday")
        return 0;
    if (name == "Tuesday")
        return 1;
    if (name == "Wednesday")
        return 2;
    if (name == "Thursday")
        return 3;
    if (name == "Friday")
        return 4;
    if (name == "Saturday")
        return 5;
    if (name == "Sunday")
        return 6;
    return -1;
}

auto jdnFromGregorian(int y, int m, int d) -> long long {
    long long a{(14 - m) / 12};
    long long yy{y + 4800 - static_cast<int>(a)};
    long long mm{m + 12 * a - 3};
    return static_cast<long long>(d) + (153 * mm + 2) / 5 + 365 * yy + yy / 4 -
           yy / 100 + yy / 400 - 32045;
}

auto jdnFromJulian(int y, int m, int d) -> long long {
    long long a{(14 - m) / 12};
    long long yy{y + 4800 - static_cast<int>(a)};
    long long mm{m + 12 * a - 3};
    return static_cast<long long>(d) + (153 * mm + 2) / 5 + 365 * yy + yy / 4 -
           32083;
}

auto gregorianFromJdn(long long jdn) -> Date {
    long long a{jdn + 32044};
    long long b{(4 * a + 3) / 146097};
    long long c{a - (146097 * b) / 4};
    long long d{(4 * c + 3) / 1461};
    long long e{c - (1461 * d) / 4};
    long long mm{(5 * e + 2) / 153};
    Date res{};
    res.d = static_cast<int>(e - (153 * mm + 2) / 5 + 1);
    res.m = static_cast<int>(mm + 3 - 12 * (mm / 10));
    res.y = static_cast<int>(b * 100 + d - 4800 + mm / 10);
    return res;
}

auto julianFromJdn(long long jdn) -> Date {
    long long c{jdn + 32082};
    long long d{(4 * c + 3) / 1461};
    long long e{c - (1461 * d) / 4};
    long long mm{(5 * e + 2) / 153};
    Date res{};
    res.d = static_cast<int>(e - (153 * mm + 2) / 5 + 1);
    res.m = static_cast<int>(mm + 3 - 12 * (mm / 10));
    res.y = static_cast<int>(d - 4800 + mm / 10);
    return res;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    std::string dowStr;
    while (std::cin >> dowStr) {
        if (dowStr == "#") {
            break;
        }
        int dayNum{0};
        std::string monStr;
        int yearNum{0};
        std::cin >> dayNum >> monStr >> yearNum;
        int monthNum{monthNameToNumber(monStr)};
        int dowIdx{dowNameToIndex(dowStr)};

        long long jdnGreg{jdnFromGregorian(yearNum, monthNum, dayNum)};
        long long jdnJul{jdnFromJulian(yearNum, monthNum, dayNum)};
        long long dowGregIdx{jdnGreg % 7};
        long long dowJulIdx{jdnJul % 7};

        if (dowIdx == dowGregIdx) {
            Date jul{julianFromJdn(jdnGreg)};
            output << dowStr << ' ' << jul.d << '*' << ' '
                   << monthNumberToName(jul.m) << ' ' << jul.y << '\n';
        } else if (dowIdx == dowJulIdx) {
            Date greg{gregorianFromJdn(jdnJul)};
            output << dowStr << ' ' << greg.d << ' '
                   << monthNumberToName(greg.m) << ' ' << greg.y << '\n';
        } else {
            // Fallback: assume Gregorian
            Date jul{julianFromJdn(jdnGreg)};
            output << dowStr << ' ' << jul.d << '*' << ' '
                   << monthNumberToName(jul.m) << ' ' << jul.y << '\n';
        }
    }
    std::cout << output.str();
}
