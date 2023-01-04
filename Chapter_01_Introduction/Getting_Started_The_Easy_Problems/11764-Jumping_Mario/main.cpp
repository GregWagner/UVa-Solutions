#include <iostream>
#include <sstream>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    int test_case {};
    int t {};
    std::cin >> t;
    while (t--) {
        int high_jumps {};
        int low_jumps {};
        int current_height {-1};
        int number_of_walls {};
        std::cin >> number_of_walls;
        while (number_of_walls--) {
            int wall_height {};
            std::cin >> wall_height;
            if (current_height == -1) {
                current_height = wall_height;
                continue;
            }
            if (current_height != wall_height) {
                current_height > wall_height ? ++low_jumps : ++high_jumps;
            }
            current_height = wall_height;
        }
        output << "Case " << ++test_case << ": " << high_jumps
            << ' ' << low_jumps << '\n';
    }
    std::cout << output.str();
}
