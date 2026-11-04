#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Date {
    int y, m, d;
};

struct Offense {
    Date date;
    int points;
};

static std::string trim(const std::string& s) {
    size_t a = s.find_first_not_of(" \t\r\n");
    if (a == std::string::npos)
        return "";
    size_t b = s.find_last_not_of(" \t\r\n");
    return s.substr(a, b - a + 1);
}

static Date parseDate(const std::string& s) {
    return {std::stoi(s.substr(0, 4)), std::stoi(s.substr(4, 2)),
            std::stoi(s.substr(6, 2))};
}

static bool lessDate(const Date& a, const Date& b) {
    if (a.y != b.y)
        return a.y < b.y;
    if (a.m != b.m)
        return a.m < b.m;
    return a.d < b.d;
}

static bool sameDate(const Date& a, const Date& b) {
    return a.y == b.y && a.m == b.m && a.d == b.d;
}

static Date addYears(const Date& dt, int n) {
    return {dt.y + n, dt.m, dt.d};
}

static std::string fmtDate(const Date& dt) {
    char buf[32];
    std::snprintf(buf, sizeof(buf), "%04d-%02d-%02d", dt.y, dt.m, dt.d);
    return std::string(buf);
}

static std::string pointsLine(const Date& dt, int D, int M) {
    std::string s = fmtDate(dt) + " ";
    if (D == 0 && M == 0) {
        s += "No merit or demerit points.";
    } else if (D > 0) {
        s += std::to_string(D) + " demerit point(s).";
    } else {
        s += std::to_string(M) + " merit point(s).";
    }
    return s;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    while (std::getline(std::cin, line)) {
        if (!trim(line).empty())
            break;
    }
    if (trim(line).empty())
        return 0;
    int T = std::stoi(trim(line));

    for (int tc = 0; tc < T; ++tc) {
        while (std::getline(std::cin, line)) {
            if (!trim(line).empty())
                break;
        }
        if (trim(line).empty())
            break;
        std::istringstream iss(line);
        std::string licStr;
        iss >> licStr;
        Date license = parseDate(licStr);

        std::vector<Offense> offs;
        while (std::getline(std::cin, line)) {
            if (trim(line).empty())
                break;
            std::istringstream iss2(line);
            std::string dstr;
            int pts;
            while (iss2 >> dstr >> pts) {
                offs.push_back({parseDate(dstr), pts});
            }
        }

        int D = 0;
        int M = 0;
        Date cleanStart = license;
        Date lastOffense = license;

        Date nextRed = {0, 0, 0};
        bool hasRed = false;
        Date nextMerit = addYears(license, 2);

        size_t idx = 0;

        // initial output
        std::cout << pointsLine(license, D, M) << "\n";

        while (true) {
            if (idx >= offs.size() && D == 0 && M == 5)
                break;

            // find min date among candidates
            bool hasMin = false;
            Date minDate = {0, 0, 0};
            if (hasRed) {
                if (!hasMin || lessDate(nextRed, minDate)) {
                    minDate = nextRed;
                    hasMin = true;
                }
            }
            if (D == 0 && M < 5) {
                if (!hasMin || lessDate(nextMerit, minDate)) {
                    minDate = nextMerit;
                    hasMin = true;
                }
            }
            if (idx < offs.size()) {
                if (!hasMin || lessDate(offs[idx].date, minDate)) {
                    minDate = offs[idx].date;
                    hasMin = true;
                }
            }
            if (!hasMin)
                break;

            int type = 3; // 1 red, 2 merit, 3 offense
            if (hasRed && sameDate(nextRed, minDate))
                type = 1;
            else if (D == 0 && M < 5 && sameDate(nextMerit, minDate))
                type = 2;
            else
                type = 3;

            if (type == 1) {
                // reduction
                if (D >= 4)
                    D = D / 2;
                else
                    D = std::max(0, D - 2);
                std::cout << pointsLine(minDate, D, M) << "\n";

                nextRed = addYears(nextRed, 1);
                if (D == 0) {
                    hasRed = false;
                    cleanStart = minDate;
                    if (M < 5) {
                        nextMerit = addYears(cleanStart, 2);
                    }
                }
            } else if (type == 2) {
                M++;
                std::cout << pointsLine(minDate, D, M) << "\n";
                nextMerit = addYears(nextMerit, 2);
                if (M >= 5) {
                }
            } else {
                // offense
                int P = offs[idx].points;
                if (M > 0) {
                    if (P > 2 * M) {
                        P = P - 2 * M;
                        M = 0;
                    } else {
                        M = M - (P / 2);
                        P = 0;
                    }
                }
                if (P > 0) {
                    D += P;
                }
                Date offDate = offs[idx].date;
                lastOffense = offDate;

                if (D > 0) {
                    hasRed = true;
                    nextRed = addYears(offDate, 1);
                } else {
                    hasRed = false;
                    cleanStart = offDate;
                    if (M < 5) {
                        nextMerit = addYears(cleanStart, 2);
                    } else {
                    }
                }
                std::cout << pointsLine(offDate, D, M) << "\n";
                idx++;
            }
        }

        if (tc + 1 < T)
            std::cout << "\n";
    }
}