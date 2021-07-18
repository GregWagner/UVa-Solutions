#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ostringstream output;
    output << std::setprecision(12);
    int p {};
    int a {};
    int b {};
    int c {};
    int d {};
    int n {};
    while (std::cin >> p >> a >> b >> c >> d >> n) {
        double max_diff {};
        double max_value {std::numeric_limits<double>::min()};
        for (int k {}; k < n; ++k) {
            double price = p * (sin(a * (k + 1) + b) + cos(c * (k + 1) + d) + 2);
            max_diff = std::max(max_diff, max_value - price);
            max_value = std::max(max_value, price);
        }
        output << max_diff << '\n';
    }
}
