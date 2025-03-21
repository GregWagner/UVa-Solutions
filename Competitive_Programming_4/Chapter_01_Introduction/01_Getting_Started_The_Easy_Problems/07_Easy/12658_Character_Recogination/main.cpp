#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ostringstream output;
    int n {};
    std::cin >> n;
    
    std::string first_line;
    std::getline(std::cin, first_line);
    std::getline(std::cin, first_line);
    
    std::string next_line;
    std::getline(std::cin, next_line);
    std::getline(std::cin, next_line);
    std::getline(std::cin, next_line);

    int index {};
    for (int i {0}; i < n; ++i) {
        if (first_line[2 + index] == '.') {
            output << 1;
        } else if (next_line[index] == '*') {
            output << 2;
        } else {
            output << 3;
        }
        index += 4;
    }
    std::cout << output.str() << '\n';
}
