/*
 * Problem 10114 - Loansome Car Buyer
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;

    double deprecition[110];

    int loanDuration;
    double downPayment;
    double loanAmount;
    int numberOfRecords;

    while (true) {
        std::cin >> loanDuration >> downPayment >> loanAmount >> numberOfRecords;
        if (loanDuration < 0) {
            break;
        }
        for (int record {}; record < numberOfRecords; ++record) {
            double percent;
            int month;
            std::cin >> month >> percent;
            for (int i = month; i < 105; ++i) {
                deprecition[i] = percent;
            }
        }

        double carWorth {downPayment + loanAmount};
        carWorth -= carWorth * deprecition[0];
        double payment {loanAmount / loanDuration};

        int month {};
        while (carWorth < loanAmount) {
            ++month;
            carWorth -= carWorth * deprecition[month];
            loanAmount -= payment;
        }
        output << month << (month == 1 ? " month\n" : " months\n");
    }
    std::cout << output.str();
}
