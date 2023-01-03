#include <iostream>
#include <sstream>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    int n {};
    std::cin >> n;
    while (n--) {
        int a {};
        int b {};
        std::cin >> a >> b;
        if (a < b) {
            output << "<\n";
        } else if (a > b) {
            output << ">\n";
        } else {
            output << "=\n";
        }
    }
    std::cout << output.str();
}
