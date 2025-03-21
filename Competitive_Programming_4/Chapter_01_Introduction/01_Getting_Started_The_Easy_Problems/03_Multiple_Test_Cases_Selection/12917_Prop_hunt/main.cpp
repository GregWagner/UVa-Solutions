#include <iostream>
#include <sstream>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;
    int props {};
    int hunters {};
    int objects {};
    while (std::cin >> props >> hunters >> objects) {
        output << (objects - props < hunters ? "Hunters" : "Props")
            << " win!\n";
    }
    std::cout << output.str();
}
