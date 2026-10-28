// 448 - OOPS
#include <iostream>
#include <sstream>

const std::string OP_NAMES[] = {"ADD",  "SUB",  "MUL",  "DIV",  "MOV",  "BREQ",
                                "BRLE", "BRLS", "BRGE", "BRGR", "BRNE", "BR",
                                "AND",  "OR",   "XOR",  "NOT"};

const int OP_COUNT[] = {2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1};

const std::string MODE_PREFIX[] = {"R", "$", "PC+", ""};

auto hexValue(char c) -> int {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    return 0;
}

auto parseOperand(const std::string& hex4) -> std::string {
    int value16{};
    for (char c : hex4) {
        value16 = (value16 << 4) | hexValue(c);
    }
    int mode{(value16 >> 14) & 3};
    int value{value16 & 0x3FFF};

    return MODE_PREFIX[mode] + std::to_string(value);
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string hexStream{};
    char c;

    // read all non-whitespace hex characters
    while (std::cin >> c) {
        if (isxdigit(c)) {
            hexStream += c;
        }
    }

    size_t index{};
    while (index < hexStream.size()) {
        int opcode = hexValue(hexStream[index++]);
        int numberOfOperands = OP_COUNT[opcode];

        output << OP_NAMES[opcode];
        for (int i{}; i < numberOfOperands; ++i) {
            std::string hex4 = hexStream.substr(index, 4);
            index += 4;

            output << (i > 0 ? ',' : ' ');

            output << parseOperand(hex4);
        }
        output << '\n';
    }
    std::cout << output.str();
}
