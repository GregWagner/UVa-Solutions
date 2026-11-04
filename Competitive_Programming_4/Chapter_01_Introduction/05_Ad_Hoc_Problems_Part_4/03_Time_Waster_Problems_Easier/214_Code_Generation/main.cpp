#include <iostream>
#include <sstream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string postfix;
    int t{};
    while (std::cin >> postfix) {
        if (t++) {
            output << "\n";
        }

        char operand{'\0'};
        int storageSize{};
        bool emptyStack{true};

        for (size_t i{}; i < postfix.length(); ++i) {
            if (postfix[i] == '+') {
                if (operand != '\0') {
                    output << "A " << operand << "\n";
                } else {
                    output << "A $" << --storageSize << "\n";
                }
                operand = '\0';
            } else if (postfix[i] == '-') {
                if (operand != '\0') {
                    output << "S " << operand << "\n";
                } else {
                    output << "N\n" << "A $" << --storageSize << "\n";
                }
                operand = '\0';
            } else if (postfix[i] == '*') {
                if (operand != '\0') {
                    output << "M " << operand << "\n";
                } else {
                    output << "M $" << --storageSize << "\n";
                }
                operand = '\0';
            } else if (postfix[i] == '/') {
                if (operand != '\0') {
                    output << "D " << operand << "\n";
                } else {
                    output << "ST $" << storageSize++ << "\n";
                    output << "L $" << storageSize - 2 << "\n";
                    output << "D $" << --storageSize << "\n";
                    storageSize--;
                }
                operand = '\0';
            } else if (postfix[i] == '@') {
                if (operand != '\0') {
                    if (!emptyStack) {
                        output << "ST $" << storageSize++ << "\n";
                    }
                    output << "L " << operand << "\n";
                    operand = '\0';
                    emptyStack = false;
                }
                output << "N\n";
            } else {
                if (operand != '\0') {
                    if (!emptyStack) {
                        output << "ST $" << storageSize++ << "\n";
                    }
                    emptyStack = false;
                    output << "L " << operand << "\n";
                }
                operand = postfix[i];
            }
        }

        if (operand != '\0') {
            if (!emptyStack) {
                output << "ST $" << storageSize++ << "\n";
            }
            emptyStack = true;
            output << "L " << operand << "\n";
        }
    }
    std::cout << output.str();
}