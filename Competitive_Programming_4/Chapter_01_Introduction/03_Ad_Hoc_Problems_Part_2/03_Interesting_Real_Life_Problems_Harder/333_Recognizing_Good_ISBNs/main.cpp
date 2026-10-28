// 333 Recognizing Good ISBNs
#include <iostream>
#include <sstream>
#include <vector>

auto trim(std::string& s) -> std::string {
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);
    return s;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string input;
    while (std::getline(std::cin, input)) {
        std::string isbn = trim(input);

        std::vector<int> digits;
        bool validIsbn{true};

        for (char c : isbn) {
            if (c == '-' || c == ' ') {
                continue;
            }
            if (isdigit(c)) {
                digits.push_back(c - '0');
            } else if (c == 'X') {
                // X can only be the last character
                if (digits.size() == 9) {
                    digits.push_back(10);
                } else {
                    validIsbn = false;
                    break;
                }
            } else if (c == 'x') {
                // lowercase x is incorrect per sample 15
                validIsbn = false;
                break;
            } else {
                // invalid character
                validIsbn = false;
                break;
            }
        }
        if (digits.size() != 10) {
            validIsbn = false;
        }

        // if format is correct - validate checksum
        if (validIsbn) {
            int s{}, t{};
            for (int d : digits) {
                s += d;
                t += s;
            }
            if (t % 11 != 0) {
                validIsbn = false;
            }
        }

        output << isbn << " is "
               << (validIsbn ? "correct.\n" : "incorrect.\n");
    }
    std::cout << output.str();
}
