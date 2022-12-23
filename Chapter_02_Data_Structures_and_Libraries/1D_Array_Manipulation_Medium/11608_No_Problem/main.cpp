#include <iostream>
#include <sstream>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    int testNumber { 1 };
    int currentProblems {};
    while (std::cin >> currentProblems && currentProblems >= 0) {
        output << "Case " << testNumber++ << ":\n";
        std::string newProblems;
        std::string problemsNeeded;
        std::getline(std::cin, newProblems);
        std::getline(std::cin, newProblems);
        std::getline(std::cin, problemsNeeded);

        std::istringstream ss(newProblems);
        std::istringstream ss1(problemsNeeded);

        for (int i {}; i < 12; ++i) {
            int a, b;
            ss >> a;
            ss1 >> b;
            currentProblems -= b;
            if (currentProblems < 0) {
                output << "No problem. :(\n";
                currentProblems += b;
            } else {
                output << "No problem! :D\n";
            }
            currentProblems += a;
        }
    }
    std::cout << output.str();
}
