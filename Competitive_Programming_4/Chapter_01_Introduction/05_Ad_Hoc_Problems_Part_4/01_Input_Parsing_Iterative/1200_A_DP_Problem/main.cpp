#include <cctype>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

void parse(const std::string& s, int& A, int& B) {
    A = 0;
    B = 0;
    int g = 0, f = 0, neg = 1;
    for (size_t i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (c == 'x' || c == 'X') {
            if (g) A += neg * f;
            else A += neg;
            g = 0;
            f = 0;
            neg = 1;
        } else {
            if (c == '-') {
                if (g) B += neg * f;
                g = 0;
                f = 0;
                neg = -1;
            } else if (c == '+') {
                if (g) B += neg * f;
                g = 0;
                f = 0;
                neg = 1;
            } else if (std::isdigit(static_cast<unsigned char>(c))) {
                f = f * 10 + (c - '0');
                g = 1;
            }
        }
    }
    if (g) B += neg * f;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
    char buf[100000];
    while (t--) {
        std::string line;
        while (true) {
            if (!fgets(buf, sizeof(buf), stdin)) return 0;
            line = buf;
            while (!line.empty() && (line.back() == '\n' || line.back() == '\r')) line.pop_back();
            std::string cleaned;
            for (char c : line) {
                if (!std::isspace(static_cast<unsigned char>(c))) cleaned.push_back(c);
            }
            if (!cleaned.empty()) {
                line = cleaned;
                break;
            }
        }
        size_t eqPos = line.find('=');
        std::string leftStr = line.substr(0, eqPos);
        std::string rightStr = (eqPos == std::string::npos) ? "" : line.substr(eqPos + 1);

        int la, lb, ra, rb;
        parse(leftStr, la, lb);
        parse(rightStr, ra, rb);

        if (la == ra && lb == rb) {
            printf("IDENTITY\n");
        } else if (la == ra && lb != rb) {
            printf("IMPOSSIBLE\n");
        } else {
            printf("%d\n", (int)floor((double)(rb - lb) / (la - ra)));
        }
    }
    return 0;
}