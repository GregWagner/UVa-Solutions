#include <iostream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    while (n--) {
        std::string name;
        std::string dateBegan;
        std::string dateOfBirth;
        int courses;
        std::cin >> name >> dateBegan >> dateOfBirth >> courses;

        int yearBegan = std::stoi(dateBegan.substr(0, 4));
        if (yearBegan >= 2010) {
            std::cout << name << " eligible\n";
            continue; // skip to the next contestant
        }

        int yearBorn = std::stoi(dateOfBirth.substr(0, 4));
        if (yearBorn >= 1991) {
            std::cout << name << " eligible\n";
            continue; // skip to the next contestant
        }

        if (courses > 40) {
            std::cout << name << " ineligible\n";
            continue; // skip to the next contestant
        }

        std::cout << name << " coach petitions\n";
    }
}
