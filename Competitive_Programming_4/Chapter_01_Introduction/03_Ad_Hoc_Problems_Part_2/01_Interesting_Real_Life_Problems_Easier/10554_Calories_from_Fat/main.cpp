// 10554 Calories from Fat
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Calories per gram for: fat, protein, sugar, starch, alcohol.
    const int factor[5] = {9, 4, 4, 4, 7};

    std::ostringstream output;

    std::string line;
    bool inTest = false;
    double totalCal{};
    double totalFatCal{};

    while (std::getline(std::cin, line)) {
        if (line == "-") {
            if (!inTest) {
                break; // the extra '-' after the last test case ends input
            }

            output << std::lround(100.0 * totalFatCal / totalCal) << "%\n";
            inTest = false;
            totalCal = 0.0;
            totalFatCal = 0.0;
            continue;
        }

        inTest = true;

        // Each token is an integer value plus a unit: 'g', 'C', or '%'.
        double known{};      // calories we can compute directly on this line
        double percent{};    // sum of percentages on this line
        double fatKnown{};   // fat's directly-known calories
        double fatPercent{}; // fat's percentage, if given as '%'

        std::istringstream tokens(line);
        for (int i = 0; i < 5; ++i) {
            std::string token;
            tokens >> token;

            char unit = token.back();
            double value = std::stod(token.substr(0, token.size() - 1));

            if (unit == 'g') {
                double cal = value * factor[i];
                known += cal;
                if (i == 0) {
                    fatKnown += cal;
                }
            } else if (unit == 'C') {
                known += value;
                if (i == 0) {
                    fatKnown += value;
                }
            } else { // '%'
                percent += value;
                if (i == 0) {
                    fatPercent += value;
                }
            }
        }

        // Percentages are shares of this line's total, so the known
        // calories are the remaining share: known = lineCal * (1 -
        // percent/100).
        double lineCal = known / (1.0 - percent / 100.0);
        double lineFatCal = fatKnown + fatPercent / 100.0 * lineCal;

        totalCal += lineCal;
        totalFatCal += lineFatCal;
    }
    std::cout << output.str();
}
