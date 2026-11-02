// 10339 Watching Watches
#include <iomanip>
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    long long k, m;
    const long long SECS_PER_DAY{86400};
    const long long SECS_PER_12H{43200};
    while (std::cin >> k >> m) {
        if (k == m) {
            output << k << ' ' << m << " 12:00\n";
            continue;
        }
        long long diff{std::llabs(k - m)};
        long long numerator{SECS_PER_12H * (SECS_PER_DAY - k)};
        long long denomMod{diff * SECS_PER_12H};
        long long mod{numerator % denomMod};
        long long diff60{diff * 60};
        long long totalMinutes{(2 * mod + diff60) / (2 * diff60)};
        if (totalMinutes >= 720) {
            totalMinutes %= 720;
        }
        long long hour{(totalMinutes / 60) % 12};
        long long minute{totalMinutes % 60};
        if (hour == 0) {
            hour = 12;
        }

        output << k << ' ' << m << ' ' << std::setw(2) << std::setfill('0')
               << hour << ':' << std::setw(2) << std::setfill('0') << minute
               << "\n";
        output << std::setfill(' ');
    }
    std::cout << output.str();
}
