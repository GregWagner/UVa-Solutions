#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    if (!(std::cin >> T))
        return 0;

    for (int tc = 0; tc < T; ++tc) {
        int R, C, P;
        if (!(std::cin >> R >> C >> P))
            break;

        std::vector<std::string> target(R);
        for (int i = 0; i < R; ++i) {
            std::cin >> target[i];
        }

        // store target star positions in a set for O(1) lookup
        std::set<std::pair<int, int>> tstars;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (target[i][j] == '*') {
                    tstars.insert({i, j});
                }
            }
        }

        for (int k = 0; k < P; ++k) {
            int r, c;
            std::cin >> r >> c;
            std::vector<std::string> shape(r);
            for (int i = 0; i < r; ++i) {
                std::cin >> shape[i];
            }

            // collect piece star positions
            std::vector<std::pair<int, int>> pstars;
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    if (shape[i][j] == '*') {
                        pstars.push_back({i, j});
                    }
                }
            }

            bool possible = false;
            if (pstars.empty()) {
                possible = true;
            } else if (!tstars.empty()) {
                // use first piece star as reference
                int pi0 = pstars[0].first;
                int pj0 = pstars[0].second;
                for (const auto& ts : tstars) {
                    int dx = ts.first - pi0;
                    int dy = ts.second - pj0;
                    bool ok = true;
                    for (const auto& ps : pstars) {
                        int ni = ps.first + dx;
                        int nj = ps.second + dy;
                        if (ni < 0 || ni >= R || nj < 0 || nj >= C) {
                            ok = false;
                            break;
                        }
                        if (target[ni][nj] != '*') {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        possible = true;
                        break;
                    }
                }
            }
            std::cout << (possible ? "Yes" : "No") << "\n";
        }
        std::cout << "\n";
    }
}
