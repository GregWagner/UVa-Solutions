// 139 - Telephone Tangles
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

struct Tariff {
    std::string areaCode;
    std::string location;
    int costInCents;
};

static auto trim(const std::string& s) -> std::string {
    auto start = s.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) return {};
    auto end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output{};

    std::unordered_map<std::string, Tariff> tariffMap{};
    std::string line{};
    while (std::getline(std::cin, line)) {
        if (line == "000000") break;
        if (line.empty()) continue;
        auto dollarPos = line.find('$');
        if (dollarPos == std::string::npos) continue;
        auto before = line.substr(0, dollarPos);
        auto priceStr = line.substr(dollarPos + 1);
        auto firstSpace = before.find(' ');
        if (firstSpace == std::string::npos) continue;
        auto code = before.substr(0, firstSpace);
        auto location = trim(before.substr(firstSpace + 1));
        auto cents = std::stoi(trim(priceStr));
        tariffMap[code] = {code, location, cents};
    }

    std::string number{};
    int duration{};
    while (std::cin >> number) {
        if (number == "#") break;
        if (!(std::cin >> duration)) break;

        std::string location{};
        std::string subscriber{};
        int rate{-1};

        if (!number.empty() && number[0] != '0') {
            location = "Local";
            subscriber = number;
            rate = 0;
        } else {
            bool found{false};
            auto n = static_cast<int>(number.size());
            auto maxI = std::min(n, 6);
            for (auto i = 2; i <= maxI; ++i) {
                auto subLen = n - i;
                if (subLen < 4) continue;
                auto maxSub = ((n > 1 && number[1] != '0') || i == 2) ? 7 : 10;
                if (subLen > maxSub) continue;
                auto code = number.substr(0, i);
                auto it = tariffMap.find(code);
                if (it != tariffMap.end()) {
                    location = it->second.location;
                    subscriber = number.substr(i);
                    rate = it->second.costInCents;
                    found = true;
                    break;
                }
            }
            if (!found) {
                location = "Unknown";
                subscriber = {};
                rate = -1;
            }
        }

        output << std::left << std::setw(16) << number;
        output << std::left << std::setw(25) << location;
        output << std::right << std::setw(10) << subscriber;
        output << std::right << std::setw(5) << duration;
        if (rate >= 0) {
            auto pricePerMin = rate / 100.0;
            auto total = pricePerMin * duration;
            output << std::right << std::setw(6) << std::fixed << std::setprecision(2) << pricePerMin;
            output << std::right << std::setw(7) << std::fixed << std::setprecision(2) << total;
        } else {
            output << std::right << std::setw(6) << "";
            output << std::right << std::setw(7) << std::fixed << std::setprecision(2) << -1.00;
        }
        output << "\n";
    }
    std::cout << output.str();
}
