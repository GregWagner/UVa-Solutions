// 444 - Encoder and Decoder
#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string input;
    while (std::getline(std::cin, input)) {
        if (input.empty()) {
            output << '\n';
            continue;
        }
        // Check if all digits
        bool isDigits = true;
        for (char c : input) {
            if (!std::isdigit(static_cast<unsigned char>(c))) {
                isDigits = false;
                break;
            }
        }
        if (isDigits) {
            // Decode: reverse the line, then parse 2 or 3 digit groups as ASCII
            // codes
            std::reverse(input.begin(), input.end());
            std::string outputString;
            size_t i = 0;
            while (i < input.size()) {
                if (i + 2 < input.size() && input[i] == '1') {
                    // Try 3-digit code starting with '1' (ASCII 100-126)
                    int code = (input[i] - '0') * 100 +
                               (input[i + 1] - '0') * 10 + (input[i + 2] - '0');
                    if (code >= 32 && code <= 126) {
                        outputString += static_cast<char>(code);
                        i += 3;
                        continue;
                    }
                }
                if (i + 1 < input.size()) {
                    int code = (input[i] - '0') * 10 + (input[i + 1] - '0');
                    if (code >= 32 && code <= 126) {
                        outputString += static_cast<char>(code);
                        i += 2;
                        continue;
                    }
                }
                // Unreachable for well-formed input: every code is 2-3 digits.
                break;
            }
            output << outputString << '\n';
        } else {
            // Encode: reverse the string, for each char reverse its ASCII code
            // digits and concatenate
            std::reverse(input.begin(), input.end());
            std::string outputString;
            for (char c : input) {
                int code = static_cast<unsigned char>(c);
                std::string codeStr = std::to_string(code);
                std::reverse(codeStr.begin(), codeStr.end());
                outputString += codeStr;
            }
            output << outputString << '\n';
        }
    }
    std::cout << output.str();
}
