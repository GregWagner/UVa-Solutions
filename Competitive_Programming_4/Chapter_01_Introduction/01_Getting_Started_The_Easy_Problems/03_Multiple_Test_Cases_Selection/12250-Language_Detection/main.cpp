#include <iostream>
#include <sstream>
#include <unordered_map>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::ostringstream output;
    std::unordered_map<std::string, std::string> m {
        {"HELLO", "ENGLISH"},
        {"HOLA", "SPANISH"},
        {"HALLO", "GERMAN"},
        {"BONJOUR", "FRENCH"},
        {"CIAO", "ITALIAN"},
        {"ZDRAVSTVUJTE", "RUSSIAN"}
    };

    int test_case {};
    std::string input;
    while (std::cin >> input && input != "#") {
        output << "Case " << ++test_case << ": " << 
            (m.count(input) == 0 ? "UNKNOWN" : m[input]) << '\n';
    }
    std::cout << output.str();
}
