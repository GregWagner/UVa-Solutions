#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int testCases;
    std::cin >> testCases;
    int caseNum = 1;
    while (testCases--) {
        int sh1, sm1, eh1, em1;
        char colon;
        std::cin >> sh1 >> colon >> sm1;
        std::cin >> eh1 >> colon >> em1;

        int sh2, sm2, eh2, em2;
        std::cin >> sh2 >> colon >> sm2;
        std::cin >> eh2 >> colon >> em2;

        int start1 = sh1 * 60 + sm1;
        int end1 = eh1 * 60 + em1;
        int start2 = sh2 * 60 + sm2;
        int end2 = eh2 * 60 + em2;

        bool overlap = !(end1 < start2 || end2 < start1);
        if (overlap) {
            output << "Case " << caseNum << ": Mrs Meeting\n";
        } else {
            output << "Case " << caseNum << ": Hits Meeting\n";
        }
        ++caseNum;
    }
    std::cout << output.str();
}
