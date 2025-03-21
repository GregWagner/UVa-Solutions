#include <iostream>
#include <sstream>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    int number_of_streets {};
    int number_of_integers {};
    int test_case {1};
    while (std::cin >> number_of_streets >> number_of_integers && number_of_streets != 0 && number_of_integers != 0) {
        int answer {number_of_streets / number_of_integers};
        if (answer * number_of_integers == number_of_streets) {
            --answer;
        }
        if (answer <= 26) {
            output << "Case " << test_case++ << ": " << answer << '\n';
        } else {
            output << "Case " << test_case++ << ": impossible\n";
        }
    }
    std::cout << output.str();
}
