// 158 Calendar
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

auto isLeap(int year) -> bool {
    if (year % 400 == 0) {
        return true;
    }
    if (year % 100 == 0) {
        return false;
    }
    return year % 4 == 0;
}

auto getDaysInMonth(int year, int month) -> int {
    static const int days[] = {0,  31, 28, 31, 30, 31, 30,
                               31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeap(year)) {
        return 29;
    }
    return days[month];
}

auto dateToDays(int y, int m, int d) -> long long {
    long long days{};
    for (int year{1}; year < y; ++year) {
        days += (isLeap(year) ? 366 : 365);
    }
    for (int month{1}; month < m; ++month) {
        days += getDaysInMonth(y, month);
    }
    days += (d - 1);
    return days;
}

struct Anniv {
    int day{};
    int month{};
    int priority{};
    std::string desc{};
    int order{};
};

struct Query {
    int day{};
    int month{};
};

struct Active {
    int day{};
    int month{};
    std::string desc{};
    int stars{};
    long long occAbs{};
    int order{};
    bool isToday{};
};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int year{};
    std::string firstLine;
    if (!std::getline(std::cin, firstLine)) {
        return 0;
    }
    // extract first integer from possibly prefixed line
    {
        std::size_t pos = firstLine.find_first_of("0123456789");
        if (pos != std::string::npos) {
            std::istringstream iss(firstLine.substr(pos));
            iss >> year;
        } else {
            return 0;
        }
    }
    std::string line;

    std::vector<Anniv> annivs;
    std::vector<Query> queries;
    int orderIdx{};

    while (std::getline(std::cin, line)) {
        if (line.empty())
            continue;
        if (line[0] == '#')
            break;
        if (line[0] == 'A') {
            std::istringstream iss(line);
            char type{};
            int d{}, m{}, p{};
            iss >> type >> d >> m >> p;
            std::string desc;
            std::getline(iss, desc);
            // trim leading whitespace
            size_t start = desc.find_first_not_of(" \t\r\n");
            if (start != std::string::npos)
                desc = desc.substr(start);
            Anniv a{};
            a.day = d;
            a.month = m;
            a.priority = p;
            a.desc = desc;
            a.order = orderIdx++;
            annivs.push_back(a);
        } else if (line[0] == 'D') {
            std::istringstream iss(line);
            char type{};
            int d{0}, m{0};
            iss >> type >> d >> m;
            Query q{};
            q.day = d;
            q.month = m;
            queries.push_back(q);
        }
    }

    for (size_t qi{}; qi < queries.size(); ++qi) {
        const Query& q{queries[qi]};
        long long queryAbs{dateToDays(year, q.month, q.day)};
        std::vector<Active> active;
        for (const auto& a : annivs) {
            long long annivThis{dateToDays(year, a.month, a.day)};
            long long occAbs{annivThis >= queryAbs
                                 ? annivThis
                                 : dateToDays(year + 1, a.month, a.day)};
            long long daysAhead{occAbs - queryAbs};
            if (daysAhead < 0)
                continue;
            if (daysAhead == 0) {
                Active e{};
                e.day = a.day;
                e.month = a.month;
                e.desc = a.desc;
                e.occAbs = occAbs;
                e.order = a.order;
                e.isToday = true;
                active.push_back(e);
            } else if (daysAhead <= a.priority) {
                int stars{a.priority - static_cast<int>(daysAhead - 1)};
                if (stars > 0) {
                    Active e{};
                    e.day = a.day;
                    e.month = a.month;
                    e.desc = a.desc;
                    e.stars = stars;
                    e.occAbs = occAbs;
                    e.order = a.order;
                    e.isToday = false;
                    active.push_back(e);
                }
            }
        }
        std::sort(active.begin(), active.end(),
                  [](const Active& x, const Active& y) {
                      if (x.occAbs != y.occAbs)
                          return x.occAbs < y.occAbs;
                      int sx = x.isToday ? 1000 : x.stars;
                      int sy = y.isToday ? 1000 : y.stars;
                      if (sx != sy)
                          return sx > sy;
                      return x.order < y.order;
                  });

        output << "Today is:" << std::setw(3) << q.day << std::setw(3)
               << q.month << "\n";
        for (const auto& e : active) {
            output << std::setw(3) << e.day << std::setw(3) << e.month << ' ';
            std::string starField;
            if (e.isToday) {
                starField = "*TODAY*";
            } else {
                starField = std::string(e.stars, '*');
            }
            output << std::left << std::setw(7) << starField << std::right << ' ' << e.desc << "\n";
        }
        if (qi + 1 < queries.size())
            output << "\n";
    }
    std::cout << output.str();
}
