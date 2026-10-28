#include <iomanip>
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string input;
    while (std::getline(std::cin, input)) {
        if (input.empty()) {
            break;
        }

        int hour = std::stoi(input.substr(0, 2));
        int minute = std::stoi(input.substr(2, 2));
        int second = std::stoi(input.substr(4, 2));
        int cc = std::stoi(input.substr(6, 2));

        // computer total standard units
        long long stdHundreds = ((hour * 3600LL) + (minute * 60LL) + second) * 100LL + cc;

        // conver to decimal units:
        long long decHundreds = (stdHundreds * 125LL) / 108LL;

        // extract answer
        long long dh = decHundreds / 1000000LL;
        long long dm = (decHundreds / 10000LL) % 100LL;
        long long ds = (decHundreds / 100LL) % 100LL;
        long long dc = (decHundreds % 100LL);

        output << dh << std::setfill('0') << std::setw(2) << dm
               << std::setfill('0') << std::setw(2) << ds << std::setfill('0')
               << std::setw(2) << dc << '\n';
    }
    std::cout << output.str();
}
