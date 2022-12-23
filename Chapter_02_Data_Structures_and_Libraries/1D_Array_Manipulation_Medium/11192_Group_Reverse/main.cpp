#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    size_t numberOfGroups{};
    while (std::cin >> numberOfGroups && numberOfGroups != 0) {
        std::string s;
        std::cin >> s;
        size_t groupSize{s.length() / numberOfGroups};
        int index{};
        for (size_t i{}; i < numberOfGroups; ++i) {
            size_t frontOfGroup{};
            size_t backOfGroup{groupSize - 1};
            while (frontOfGroup < backOfGroup) {
                std::swap(s[index + frontOfGroup++], s[index + backOfGroup--]);
            }
            index += groupSize;
        }
        output << s << '\n';
    }
    std::cout << output.str();
}
