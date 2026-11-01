#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const int W = 60;
const int H = 60;

using Canvas = std::vector<std::string>;

void initCanvas(Canvas& c) {
    c.assign(H, std::string(W, '.'));
}

bool inBounds(int r, int c) {
    return r >= 0 && r < H && c >= 0 && c < W;
}

static const std::string fontC5[26][5] = {
    {".***..", "*...*.", "*****..", "*...*.", "*...*."},
    {"****..", "*...*.", "****..", "*...*.", "****.."},
    {".****.", "*...*.", "*.....", "*.....", ".****."},
    {"****..", "*...*.", "*...*.", "*...*.", "****.."},
    {"*****.", "*.....", "***...", "*.....", "*****."},
    {"*****.", "*.....", "***...", "*.....", "*....."},
    {".****.", "*.....", "*..**.", "*...*.", ".***.."},
    {"*...*.", "*...*.", "*****..", "*...*.", "*...*."},
    {"*****.", "..*...", "..*...", "..*...", "*****."},
    {"..***.", "...*..", "...*..", "*..*..", ".**..."},
    {"*...*.", "*..*..", "***...", "*..*..", "*...*."},
    {"*.....", "*.....", "*.....", "*.....", "*****."},
    {"*...*.", "**.**.", "*.*.*.", "*...*.", "*...*."},
    {"*...*.", "**..*.", "*.*.*.", "*..**.", "*...*."},
    {".***..", "*...*.", "*...*.", "*...*.", ".***.."},
    {"****..", "*...*.", "****..", "*.....", "*....."},
    {".***..", "*...*.", "*...*.", "*..**.", ".****."},
    {"****..", "*...*.", "****..", "*..*..", "*...*."},
    {".****.", "*.....", ".***..", "....*.", "****.."},
    {"*****.", "*.*.*.", "..*...", "..*...", ".***.."},
    {"*...*.", "*...*.", "*...*.", "*...*.", ".***.."},
    {"*...*.", "*...*.", ".*.*..", ".*.*..", "..*..."},
    {"*...*.", "*...*.", "*.*.*.", "**.**.", "*...*."},
    {"*...*.", ".*.*..", "..*...", ".*.*..", "*...*."},
    {"*...*.", ".*.*..", "..*...", "..*...", "..*..."},
    {"*****.", "...*..", "..*...", ".*....", "*****."}};

void drawC5Char(Canvas& c, int r0, int c0, char ch) {
    if (ch == ' ' || ch < 'A' || ch > 'Z')
        return;
    int idx = ch - 'A';
    for (int dr = 0; dr < 5; ++dr) {
        const std::string& row = fontC5[idx][dr];
        for (int dc = 0; dc < 6; ++dc) {
            char pat = row[dc];
            if (pat == '*') {
                int r = r0 + dr;
                int col = c0 + dc;
                if (inBounds(r, col))
                    c[r][col] = '*';
            }
        }
    }
}

void drawC1Char(Canvas& c, int r, int col, char ch) {
    if (ch == ' ')
        return;
    if (inBounds(r, col))
        c[r][col] = ch;
}

void placeC1(Canvas& c, int row, int colStart, const std::string& s) {
    for (size_t i = 0; i < s.size(); ++i) {
        int col = colStart + (int)i;
        drawC1Char(c, row, col, s[i]);
    }
}

void placeC5(Canvas& c, int row, int colStart, const std::string& s) {
    for (size_t i = 0; i < s.size(); ++i) {
        int col = colStart + (int)i * 6;
        char ch = s[i];
        if (ch == ' ')
            continue;
        drawC5Char(c, row, col, ch);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Canvas canvas;
    initCanvas(canvas);

    std::string line;
    bool firstPage = true;
    while (std::getline(std::cin, line)) {
        if (line.empty())
            continue;
        if (line.rfind(".EOP", 0) == 0) {
            for (int r = 0; r < H; ++r) {
                std::cout << canvas[r] << "\n";
            }
            std::cout << "\n";
            for (int i = 0; i < W; ++i)
                std::cout << '-';
            std::cout << "\n\n";
            initCanvas(canvas);
            continue;
        }
        size_t p1 = line.find('|');
        if (p1 == std::string::npos)
            continue;
        size_t p2 = line.rfind('|');
        if (p2 == p1)
            continue;
        std::string prefix = line.substr(0, p1);
        std::string text = line.substr(p1 + 1, p2 - p1 - 1);

        std::istringstream iss(prefix);
        std::string cmd, font;
        int row = 0, col = 0;
        iss >> cmd >> font >> row;
        if (cmd == ".P") {
            iss >> col;
        }
        int r0 = row - 1;
        if (font == "C1") {
            if (cmd == ".P") {
                placeC1(canvas, r0, col - 1, text);
            } else if (cmd == ".L") {
                placeC1(canvas, r0, 0, text);
            } else if (cmd == ".R") {
                int start = W - (int)text.size();
                placeC1(canvas, r0, start, text);
            } else if (cmd == ".C") {
                int start = 30 - (int)text.size() / 2;
                placeC1(canvas, r0, start, text);
            }
        } else if (font == "C5") {
            if (cmd == ".P") {
                placeC5(canvas, r0, col - 1, text);
            } else if (cmd == ".L") {
                placeC5(canvas, r0, 0, text);
            } else if (cmd == ".R") {
                int start = W - (int)text.size() * 6;
                placeC5(canvas, r0, start, text);
            } else if (cmd == ".C") {
                int n = (int)text.size();
                int init = (n % 2 != 0) ? 27 : 30;
                int start = init - (n / 2) * 6;
                placeC5(canvas, r0, start, text);
            }
        }
    }
}
