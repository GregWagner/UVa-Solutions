// 740_Baudot_Data_Communication_Code
#include <iostream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string downShift, upShift;
    bool firstCase{true};

    while (true) {
        // skip empty lines before downShift
        bool gotDown{false};
        while (std::getline(std::cin, downShift)) {
            if (!downShift.empty()) {
                gotDown = true;
                break;
            }
        }
        if (!gotDown)
            break;
        if (!std::getline(std::cin, upShift))
            break;
        if (!firstCase) {
            std::cout << "\n";
        }
        firstCase = false;

        bool firstMsg{true};
        std::string bits;
        while (std::getline(std::cin, bits)) {
            if (bits.empty()) {
                break; // end of this test case
            }
            bool isUpShift{false};
            std::string message;
            for (std::size_t i{}; i + 5 <= bits.size(); i += 5) {
                int value{};
                for (std::size_t j{}; j < 5; ++j) {
                    char c{bits[i + j]};
                    if ((c != '0') && (c != '1')) {
                        value = -1;
                        break;
                    }
                    value = value * 2 + (c - '0');
                }
                if (value < 0) {
                    continue;
                }
                if (value == 27) {
                    isUpShift = false;
                } else if (value == 31) {
                    isUpShift = true;
                } else {
                    if (value >= 0 &&
                        value < static_cast<int>(downShift.size()) &&
                        value < static_cast<int>(upShift.size())) {
                        message +=
                            isUpShift ? upShift[value] : downShift[value];
                    }
                }
            }
            if (!firstMsg)
                std::cout << "\n";
            firstMsg = false;
            std::cout << message;
        }
        std::cout << "\n";
    }
}
