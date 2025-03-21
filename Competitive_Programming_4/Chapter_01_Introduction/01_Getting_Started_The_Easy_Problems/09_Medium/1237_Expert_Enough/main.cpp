#include <iostream>
#include <sstream>
#include <unordered_map>

struct Range {
    int start;
    int end;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ostringstream output;
    int testCases {};
    std::cin >> testCases;
    bool first {true};
    while (testCases--) {
        if (first) {
            first = false;
        } else {
            output << '\n';
        }
        std::unordered_map<std::string, Range> m;
        int dbSize {};
        std::cin >> dbSize;
        while (dbSize--) {
            std::string model;
            int start {};
            int end {};
            std::cin >> model >> start >> end;
            Range r {start, end};
            if (m.find(model) != m.end()) {
                model = "*" + model;
            }
            m[model] = r;
        }

        int queries {};
        std::cin >> queries;
        while (queries--) {
            std::string model;
            int count {};
            int q {};
            std::cin >> q;
            for (const auto & e : m) {
                if (q >= e.second.start && q <= e.second.end) {
                    model = e.first;
                    ++count;
                }
            }
            if (model[0] == '*') {
                model = model.substr(1);
            }
            output << (count == 1 ? model : "UNDETERMINED") << '\n';
        }
    }
    std::cout << output.str();
}
