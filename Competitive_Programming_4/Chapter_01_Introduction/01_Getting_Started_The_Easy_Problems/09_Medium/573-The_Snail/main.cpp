/*
 * 573 The Snail
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    double wallHeight {};
    while (std::cin >> wallHeight && wallHeight != 0) {
        double climbHeight {}, slideHeight {}, fatigueFactor {};
        std::cin >> climbHeight >> slideHeight >> fatigueFactor;
        double fatigueHeight = climbHeight * (fatigueFactor / 100.0);
        bool done {};
        int day {};
        double height {};
        while (!done) {
            ++day;
            height += climbHeight;
            if (height > wallHeight) {
                done = true;
                continue;
            }
            height -= slideHeight;
            if (height < 0) {
                done = true;
                continue;
            }
            climbHeight -= fatigueHeight;
            climbHeight = (climbHeight < 0 ? 0 : climbHeight);
        }
        output << (height > wallHeight ? "success" : "failure") 
            << " on day " << day << '\n';
    }
    std::cout << output.str();
}
