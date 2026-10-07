#include <iostream>
#include <sstream>
#include <stack>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);

    std::ostringstream output;
    int testCases{};
    std::cin >> testCases;
    while (testCases--) {
        std::string s;
        std::cin >> s;
        std::stack<int> st;
        long long water = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == '\\') {
                st.push(static_cast<int>(i));
            } else if (s[i] == '/' && !st.empty()) {
                int j = st.top();
                st.pop();
                water += static_cast<int>(i) - j;
            }
        }
        output << water << '\n';
    }
    std::cout << output.str();
}
