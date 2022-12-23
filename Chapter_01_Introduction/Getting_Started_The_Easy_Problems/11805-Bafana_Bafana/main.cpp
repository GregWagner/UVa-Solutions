#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ostringstream output;

    int test {};
    int test_cases {};
    std::cin >> test_cases;
    while (test_cases--) {
        int number_of_players {};
        int starting_player {};
        int number_of_passes {};
        std::cin >> number_of_players >> starting_player >> number_of_passes;

        int final_position = (starting_player + number_of_passes) % number_of_players;
        output << "Case " << ++test << ": "
            << (final_position == 0 ? number_of_players : final_position) << '\n';
    }
    std::cout << output.str();
}
