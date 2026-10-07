#include <iostream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::string dna;
    std::cin >> dna;

    if (dna.find("COV") != std::string::npos) {
        std::cout << "Veikur!\n";
    } else {
        std::cout << "Ekki veikur!\n";
    }
}