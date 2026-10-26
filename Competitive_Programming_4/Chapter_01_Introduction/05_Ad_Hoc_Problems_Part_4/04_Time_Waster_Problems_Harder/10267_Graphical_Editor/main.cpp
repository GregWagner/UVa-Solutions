// 10267 Graphical Editor
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int M = 0, N = 0;                 // M columns, N rows
    char a[300][300];

    auto clear_canvas = [&]() {
        for (int x = 1; x <= M; ++x)
            for (int y = 1; y <= N; ++y)
                a[x][y] = 'O';
    };

    char op;
    while (std::cin >> op) {
        if (op == 'X') break;

        if (op == 'I') {
            std::cin >> M >> N;
            clear_canvas();
        } else if (op == 'C') {
            clear_canvas();
        } else if (op == 'L') {
            int x, y; char c;
            std::cin >> x >> y >> c;
            if (M && N) a[x][y] = c;
        } else if (op == 'V') {
            int x, y1, y2; char c;
            std::cin >> x >> y1 >> y2 >> c;
            int s = std::min(y1, y2), e = std::max(y1, y2);
            for (int y = s; y <= e; ++y) a[x][y] = c;
        } else if (op == 'H') {
            int x1, x2, y; char c;
            std::cin >> x1 >> x2 >> y >> c;
            int s = std::min(x1, x2), e = std::max(x1, x2);
            for (int x = s; x <= e; ++x) a[x][y] = c;
        } else if (op == 'K') {
            int x1, y1, x2, y2; char c;
            std::cin >> x1 >> y1 >> x2 >> y2 >> c;
            int xs = std::min(x1, x2), xe = std::max(x1, x2);
            int ys = std::min(y1, y2), ye = std::max(y1, y2);
            for (int y = ys; y <= ye; ++y)
                for (int x = xs; x <= xe; ++x)
                    a[x][y] = c;
        } else if (op == 'F') {
            int x, y; char c;
            std::cin >> x >> y >> c;
            if (M && N && a[x][y] != c) {
                char orig = a[x][y];
                std::queue<std::pair<int,int>> q;
                q.emplace(x, y);
                a[x][y] = c;
                while (!q.empty()) {
                    auto p = q.front(); q.pop();
                    int cx = p.first, cy = p.second;
                    const int dx[4] = {1, -1, 0, 0};
                    const int dy[4] = {0, 0, 1, -1};
                    for (int k = 0; k < 4; ++k) {
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];
                        if (nx >= 1 && nx <= M && ny >= 1 && ny <= N && a[nx][ny] == orig) {
                            a[nx][ny] = c;
                            q.emplace(nx, ny);
                        }
                    }
                }
            }
        } else if (op == 'S') {
            std::string name;
            std::cin >> name;
            std::cout << name << '\n';
            for (int y = 1; y <= N; ++y) {
                for (int x = 1; x <= M; ++x)
                    std::cout << a[x][y];
                std::cout << '\n';
            }
        } else {
            // ignore unknown command line
            std::string dummy;
            std::getline(std::cin, dummy);
        }
    }
}
