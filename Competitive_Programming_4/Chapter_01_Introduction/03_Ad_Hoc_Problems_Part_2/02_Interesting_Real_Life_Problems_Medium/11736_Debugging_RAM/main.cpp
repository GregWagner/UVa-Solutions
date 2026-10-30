#include <iostream>
#include <map>
#include <sstream>
#include <vector>

struct Variable {
    std::string name;
    int numberOfBytes;
    unsigned long long value;
};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int bitsInByte, numberOfVariables;
    while (std::cin >> bitsInByte >> numberOfVariables) {
        std::vector<Variable> variables(numberOfVariables);
        std::vector<int> bitLengths(numberOfVariables);

        for (int i{}; i < numberOfVariables; ++i) {
            std::cin >> variables[i].name >> variables[i].numberOfBytes;
            bitLengths[i] = variables[i].numberOfBytes * bitsInByte;
        }

        // read in memory stream corresponding to each varaible
        for (int i{}; i < numberOfVariables; ++i) {
            unsigned long long currentValue{};
            for (int index{}; index < bitLengths[i]; ++index) {
                char bitChar{};
                std::cin >> bitChar;
                int bit{bitChar - '0'};
                currentValue = (currentValue << 1) | bit;
            }
            variables[i].value = currentValue;
        }
        std::map<std::string, unsigned long long> lookup;
        for (int i{}; i < numberOfVariables; ++i) {
            lookup[variables[i].name] = variables[i].value;
        }

        int query;
        std::cin >> query;
        for (int i{}; i < query; ++i) {
            std::string queryName;
            std::cin >> queryName;
            output << queryName << '=';
            if (lookup.find(queryName) == lookup.end())
                output << '\n';
            else
                output << lookup[queryName] << '\n';
        }
    }
    std::cout << output.str();
}
