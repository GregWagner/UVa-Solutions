// 647 Chutes and Ladders
#include <iostream>
#include <sstream>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    // The die list is shared by every game and restarts at the first throw each
    // game.
    std::vector<int> dice;
    for (int x; std::cin >> x && x != 0;) {
        dice.push_back(x);
    }

    int players;
    while (std::cin >> players && players != 0) {
        int to[101];
        bool lose[101] = {};
        bool extra[101] = {};
        for (int i{}; i <= 100; ++i) {
            to[i] = i;
        }

        int a, b;
        while (std::cin >> a >> b && (a != 0 || b != 0)) {
            to[a] = b;
        }

        for (int x; std::cin >> x && x != 0;) {
            (x < 0 ? lose[-x] : extra[x]) = true;
        }

        std::vector<int> pos(players, 0);
        std::vector<bool> skip(players, false);

        int winner{};
        int cur{};
        int di{};

        while (winner == 0) {
            if (skip[cur]) { // miss a turn: no die is consumed
                skip[cur] = false;
                cur = (cur + 1) % players;
                continue;
            }

            int roll = dice[di];
            int target = pos[cur] + roll;

            if (target == 100) {
                winner = cur + 1;
                break;
            }
            if (target < 100) {      // otherwise the throw is ignored
                int sq = to[target]; // chute or ladder (identity if none)
                pos[cur] = sq;
                if (lose[sq]) {
                    skip[cur] =
                        true; // their turn ends now; skip is served next round
                }
                if (!extra[sq]) {
                    cur = (cur + 1) % players;
                }
            } else {
                cur = (cur + 1) % players;
            }
            ++di;
        }
        output << winner << '\n';
    }
    std::cout << output.str();
}
