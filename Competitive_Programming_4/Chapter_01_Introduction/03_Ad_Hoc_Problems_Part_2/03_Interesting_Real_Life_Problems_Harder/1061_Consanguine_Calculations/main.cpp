#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

auto aboAlleles =
    [](const std::string& pheno) -> std::vector<std::pair<char, char>> {
    std::vector<std::pair<char, char>> res;
    std::string abo = pheno.substr(0, pheno.size() - 1);
    if (abo == "A") {
        res.push_back({'A', 'A'});
        res.push_back({'A', 'O'});
        res.push_back({'O', 'A'});
    } else if (abo == "B") {
        res.push_back({'B', 'B'});
        res.push_back({'B', 'O'});
        res.push_back({'O', 'B'});
    } else if (abo == "AB") {
        res.push_back({'A', 'B'});
        res.push_back({'B', 'A'});
    } else if (abo == "O") {
        res.push_back({'O', 'O'});
    }
    return res;
};

auto rhAlleles =
    [](const std::string& pheno) -> std::vector<std::pair<char, char>> {
    std::vector<std::pair<char, char>> res;
    char rh = pheno.back();
    if (rh == '+') {
        res.push_back({'+', '+'});
        res.push_back({'+', '-'});
        res.push_back({'-', '+'});
    } else {
        res.push_back({'-', '-'});
    }
    return res;
};

auto canProduce = [](const std::string& p1, const std::string& p2,
                     const std::string& child) -> bool {
    auto p1A = aboAlleles(p1);
    auto p2A = aboAlleles(p2);
    auto cA = aboAlleles(child);
    auto p1R = rhAlleles(p1);
    auto p2R = rhAlleles(p2);
    auto cR = rhAlleles(child);
    for (auto& g1 : p1A) {
        for (auto& g2 : p2A) {
            for (char a1 : std::array<char, 2>{g1.first, g1.second}) {
                for (char a2 : std::array<char, 2>{g2.first, g2.second}) {
                    for (auto& cg : cA) {
                        bool match = (a1 == cg.first && a2 == cg.second) ||
                                     (a1 == cg.second && a2 == cg.first);
                        if (!match)
                            continue;
                        for (auto& r1 : p1R) {
                            for (auto& r2 : p2R) {
                                for (char r1a :
                                     std::array<char, 2>{r1.first, r1.second}) {
                                    for (char r2a : std::array<char, 2>{
                                             r2.first, r2.second}) {
                                        for (auto& cr : cR) {
                                            bool rmatch = (r1a == cr.first &&
                                                           r2a == cr.second) ||
                                                          (r1a == cr.second &&
                                                           r2a == cr.first);
                                            if (rmatch)
                                                return true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
};

auto formatSet = [](const std::vector<std::string>& v) -> std::string {
    if (v.empty())
        return "IMPOSSIBLE";
    if (v.size() == 1)
        return v[0];
    std::string s = "{";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            s += ", ";
        s += v[i];
    }
    s += "}";
    return s;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const std::array<std::string, 8> types = {"A+",  "A-",  "B+", "B-",
                                              "AB+", "AB-", "O+", "O-"};
    std::string p1, p2, ch;
    int caseNo = 1;
    std::ostringstream out;
    while (std::cin >> p1 >> p2 >> ch) {
        if (p1 == "E" && p2 == "N" && ch == "D")
            break;
        std::vector<std::string> res1, res2, res3;
        if (p1 == "?") {
            for (auto& t : types) {
                if (canProduce(t, p2, ch))
                    res1.push_back(t);
            }
        } else {
            res1.push_back(p1);
        }
        if (p2 == "?") {
            for (auto& t : types) {
                if (canProduce(p1, t, ch))
                    res2.push_back(t);
            }
        } else {
            res2.push_back(p2);
        }
        if (ch == "?") {
            for (auto& t : types) {
                if (canProduce(p1, p2, t))
                    res3.push_back(t);
            }
        } else {
            res3.push_back(ch);
        }
        out << "Case " << caseNo++ << ": ";
        out << formatSet(res1) << ' ' << formatSet(res2) << ' '
            << formatSet(res3) << "\n";
    }
    std::cout << out.str();
}
