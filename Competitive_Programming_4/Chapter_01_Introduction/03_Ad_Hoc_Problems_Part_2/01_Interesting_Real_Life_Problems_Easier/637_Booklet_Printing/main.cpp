// 637 Booklet Printing
#include <iostream>
#include <sstream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ostringstream output;

    int n;
    while (std::cin >> n && n != 0) {
        output << "Printing order for " << n << " pages:\n";

        int totalSheets{(n + 3) / 4};

        // slot numbers beyond n are printed as Blank
        auto label = [n](int slot) -> std::string {
            return slot <= n ? std::to_string(slot) : "Blank";
        };

        int lowPage{1};
        int highPage{totalSheets * 4};

        for (int sheetNum{1}; sheetNum <= totalSheets; ++sheetNum) {
            // front side: outer (high) on the left, inner (low) on the right
            int frontLeft = highPage--;
            int frontRight = lowPage++;
            output << "Sheet " << sheetNum << ", front: " << label(frontLeft)
                   << ", " << label(frontRight) << '\n';

            // back side: low on the left, high on the right
            int backLeft = lowPage++;
            int backRight = highPage--;
            std::string backL = label(backLeft);
            std::string backR = label(backRight);
            // a fully blank back side (only happens for n == 1) is not printed
            if (backL != "Blank" || backR != "Blank") {
                output << "Sheet " << sheetNum << ", back : " << backL << ", "
                       << backR << '\n';
            }
        }
    }
    std::cout << output.str();
}
