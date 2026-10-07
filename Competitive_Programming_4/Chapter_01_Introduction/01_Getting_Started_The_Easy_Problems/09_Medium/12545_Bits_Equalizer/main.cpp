#include <algorithm>
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);

    std::ostringstream output;
    int testCases {};
    int test {};
    std::cin >> testCases;
    while (testCases--) {
        int changes {};
        output << "Case " << ++test << ": ";
        std::string start, end;
        std::cin >> start >> end;
        std::cout << "------------------------\n";
        std::cout << start << '\n' << end << '\n';

        bool done {};
        if (start == end) {
            done = true;
        }
        // first change the ?
        while(!done) {
            auto index = start.find("?");
            if (index == std::string::npos) {
                break;
            }
            ++changes;
            start[index] = end[index];
        }
        std::cout << "------------------------\n";
        std::cout << start << '\n' << end << '\n';
        if (start == end) {
            done = true;
        }

        while (!done) {
            for (size_t i {}; i < start.size(); ++i) {
                if (start[i] != end[i]) {

                }
            }
        }

        size_t ones = std::count(start.begin(), start.end(), '1');
        size_t zeros = std::count(start.begin(), start.end(), '0');
        output << changes << '\n';
    }
    std::cout << output.str();
}
