#include <algorithm>
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    bool done{};
    while (!done) {
        int a{}, b{}, c{};
        std::cin >> a >> b >> c;
        if (a == 0) {
            done = true;
            break;
        }

        // check for set
        if ((a == b) && (b == c)) {
            if (a == 13) {
                output << '*' << '\n';
            } else {
                int d = a + 1;
                output << d << ' ' << d << ' ' << d << '\n';
            }
            continue;
        }

        // check for a pair
        if ((a == b) || (b == c) || (a == c)) {
            int first{};
            int second{};
            int kicker{};
            if (a == b) {
                first = a;
                second = b;
                kicker = c + 1;
            } else if (b == c) {
                first = b;
                second = c;
                kicker = a + 1;
            } else {
                first = a;
                second = c;
                kicker = b + 1;
            }
            if (first == kicker) {
                ++kicker;
            }
            if (kicker <= 13) {
                int result[3]{first, second, kicker};
                std::sort(result, result + 3);
                output << result[0] << ' ' << result[1] << ' ' << result[2] << '\n';
            } else if (first < 13) {
                output << 1 << ' ' << first + 1 << ' ' << second + 1 << '\n';
            } else {
                // best pair (13 13 12): any set beats it, so the weakest set is next
                output << "1 1 1\n";
            }
            continue;
        }

        // three different cards: every pair beats this hand, so weakest pair is next
        output << "1 1 2\n";
    }
    std::cout << output.str();
}
