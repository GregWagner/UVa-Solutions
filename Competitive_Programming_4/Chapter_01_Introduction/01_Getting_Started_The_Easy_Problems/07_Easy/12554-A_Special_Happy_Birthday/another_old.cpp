/*
 * Problem 12554 - A Special "Happy Birthday"
 */
#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    std::string a[] = {"Happy", "birthday", "to", "you", "Happy", 
        "birthday", "to", "you", "Happy", "birthday", "to", "Rujia",
        "Happy", "birthday", "to", "you"};

    std::vector<std::string> people;
    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        std::string name;
        std::cin >> name;
        people.push_back(name);
    }

    size_t index {};
    while (true) {
        output << people[index % people.size()] << ": "
            << a[index % 16] << '\n';
        ++index;
        if (index > people.size() && index % 16 == 0) {
            break;
        }
    }
    std::cout << output.str();
}
