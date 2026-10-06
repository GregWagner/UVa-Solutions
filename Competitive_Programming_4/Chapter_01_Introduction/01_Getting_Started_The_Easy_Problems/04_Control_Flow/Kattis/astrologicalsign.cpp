#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    for (int i{}; i < n; ++i) {
        int day;
        std::string month;
        std::cin >> day >> month;
        if ((month == "Mar" && day >= 21) || (month == "Apr" && day <= 20)) {
            std::cout << "Aries\n";
        } else if ((month == "Apr" && day >= 21) || (month == "May" && day <= 20)) {
            std::cout << "Taurus\n";
        } else if ((month == "May" && day >= 21) || (month == "Jun" && day <= 21)) {
            std::cout << "Gemini\n";
        } else if ((month == "Jun" && day >= 22) || (month == "Jul" && day <= 22)) {
            std::cout << "Cancer\n";
        } else if ((month == "Jul" && day >= 23) || (month == "Aug" && day <= 22)) {
            std::cout << "Leo\n";
        } else if ((month == "Aug" && day >= 23) || (month == "Sep" && day <= 21)) {
            std::cout << "Virgo\n";
        } else if ((month == "Sep" && day >= 22) || (month == "Oct" && day <= 22)) {
            std::cout << "Libra\n";
        } else if ((month == "Oct" && day >= 23) || (month == "Nov" && day <= 22)) {
            std::cout << "Scorpio\n";
        } else if ((month == "Nov" && day >= 23) || (month == "Dec" && day <= 21)) {
            std::cout << "Sagittarius\n";
        } else if ((month == "Dec" && day >= 22) || (month == "Jan" && day <= 20)) {
            std::cout << "Capricorn\n";
        } else if ((month == "Jan" && day >= 21) || (month == "Feb" && day <= 19)) {
            std::cout << "Aquarius\n";
        } else {
            std::cout << "Pisces\n";
        }
    }
}