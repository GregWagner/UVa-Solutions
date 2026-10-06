#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::ostringstream output;
    std::string input;
    int test_case {};
    while (std::cin >> input && input != "*") {
        output << "Case " << ++test_case << ": Hajj-e-"
            << (input == "Hajj" ? "Akbar" : "Asghar") << '\n';
    }
    std::cout << output.str();
}
