/*
 * Datum
 */
#include <iostream>


unsigned calcDayNumFromDate(unsigned y, unsigned m, unsigned d) {
    m = (m + 9) % 12;
    y -= m / 10;
    unsigned dn = 365*y + y/4 - y/100 + y/400 + (m*306 + 5)/10 + (d - 1);

    return dn;
}

std::string calcDayOfWeek(int y, unsigned m, unsigned d) {
    std::string day[] = {"Wednesday", "Thursday", "Friday", "Saturday",
        "Sunday", "Monday", "Tuesday"};

    unsigned dn = calcDayNumFromDate(y, m, d);

    return day[dn % 7];
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int day, month;
    std::cin >> day >> month;
    std::cout << calcDayOfWeek(2009, month, day) << '\n';
}
