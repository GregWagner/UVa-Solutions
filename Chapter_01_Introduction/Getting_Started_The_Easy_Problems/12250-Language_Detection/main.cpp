/*
 * 12250 Language Detection
 */
#include <iostream>
#include <sstream>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::unordered_map<std::string, std::string> hash {
        {"HELLO", "ENGLISH"},
        {"HOLA", "SPANISH"},
        {"HALLO", "GERMAN"},
        {"BONJOUR", "FRENCH"},
        {"CIAO", "ITALIAN"},
        {"ZDRAVSTVUJTE", "RUSSIAN"},
    };

    std::ostringstream output;
    std::string input;
    int testCase {};
    while (std::cin >> input) {
        if (input == "#") {
            break;
        }
        output << "Case " << ++testCase << ": " << 
            (hash.count(input) == 0 ? "UNKNOWN" : hash[input]) << '\n';
    }
    std::cout << output.str();
}
