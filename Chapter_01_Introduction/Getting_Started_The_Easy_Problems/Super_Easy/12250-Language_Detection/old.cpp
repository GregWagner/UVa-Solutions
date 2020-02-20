/*
 * Problem 12250 - Language Detection
 */
#include <iostream>
#include <sstream>
#include <map>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    std::map<std::string, std::string> dict;

    dict["HELLO"] = "ENGLISH";
    dict["HOLA"] = "SPANISH";
    dict["HALLO"] = "GERMAN";
    dict["BONJOUR"] = "FRENCH";
    dict["CIAO"] = "ITALIAN";
    dict["ZDRAVSTVUJTE"] = "RUSSIAN";

    std::string input;
    int test {1};
    while (std::cin >> input && input != "#") {
        output << "Case " << test++ << ": "
            << (dict.count(input) ? dict[input] : "UNKNOWN") << '\n';
    }
    std::cout << output.str();
}
