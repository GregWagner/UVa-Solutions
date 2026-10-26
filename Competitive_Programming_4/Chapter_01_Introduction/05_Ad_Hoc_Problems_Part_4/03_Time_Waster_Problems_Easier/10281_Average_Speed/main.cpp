// 10281 Average Speed
#include <iomanip>
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    double distance{};
    int previousTime{};
    double currentSpeed{};

    std::string input;
    while (std::getline(std::cin, input)) {
        if (input.empty()) {
            continue;
        }

        int hour, minute, second;
        char colon;

        std::stringstream ss(input);
        ss >> hour >> colon >> minute >> colon >> second;
        int currentTime = (hour * 3600) + (minute * 60) + second;
        int timeElapsed = currentTime - previousTime;

        distance += currentSpeed * (timeElapsed / 3600.0);
        previousTime = currentTime;

        // has speed value also provided
        double newSpeed;
        if (ss >> newSpeed) {
            currentSpeed = newSpeed;
        } else {
            output << std::setfill('0') << std::setw(2) << hour << ":"
                   << std::setw(2) << minute << ":" << std::setw(2) << second
                   << " " << std::fixed << std::setprecision(2) << distance
                   << " km\n";
        }
    }
    std::cout << output.str();
}
