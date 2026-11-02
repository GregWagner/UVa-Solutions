#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    char c;
    bool processing{true};
    bool bold{};
    bool italic{};
    std::string fontSize{};

    while (std::cin.get(c)) {
        if (processing) {
            if (c == '\\') {
                char nc;
                if (!std::cin.get(nc)) {
                    break;
                }
                if (nc == 'b') {
                    bold = !bold;
                } else if (nc == 'i') {
                    italic = !italic;
                } else if (nc == 's') {
                    while (std::cin.peek() != EOF) {
                        char p = static_cast<char>(std::cin.peek());
                        if (std::isdigit(static_cast<unsigned char>(p)) || p == '.') {
                            std::cin.get(p);
                        } else {
                            break;
                        }
                    }
                    fontSize.clear();
                } else if (nc == '*') {
                    processing = !processing;
                } else {
                    output << nc;
                }
            } else {
                output << c;
            }
        } else {
            if (c == '\\') {
                char p = static_cast<char>(std::cin.peek());
                if (p == '*') {
                    std::cin.get(p);
                    processing = true;
                } else {
                    output << c;
                }
            } else {
                output << c;
            }
        }
    }
    std::cout << output.str();
}