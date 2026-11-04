#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

struct Edge {
    int to;
    std::vector<int> times;
};

auto next_meeting(long long cur, int instant) -> long long {
    long long next{(cur / 100) * 100 + instant};
    if (next < cur) {
        next += 100;
    }
    return next;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    for (int testNum{}; testNum < testCases; ++testNum) {
        int M, K;
        std::cin >> M >> K;
        std::vector<std::vector<Edge>> adj(M + 1);
        for (int i{}; i < K; ++i) {
            int g1, g2, v;
            std::cin >> g1 >> g2 >> v;
            std::vector<int> inst(v);
            for (int j{}; j < v; ++j) {
                std::cin >> inst[j];
            }
            adj[g1].push_back({g2, inst});
            adj[g2].push_back({g1, inst});
        }
        const long long INF{(1LL << 60)};
        std::vector<long long> dist(M + 1, INF);
        dist[1] = 0;
        using P = std::pair<long long, int>;
        std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
        pq.emplace(0, 1);
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            long long d{top.first};
            int u = top.second;
            if (d != dist[u]) {
                continue;
            }
            for (auto& e : adj[u]) {
                int v{e.to};
                long long best{LLONG_MAX};
                for (int inst : e.times) {
                    long long t{next_meeting(d, inst)};
                    if (t < best) {
                        best = t;
                    }
                }
                if (best < dist[v]) {
                    dist[v] = best;
                    pq.emplace(best, v);
                }
            }
        }
        bool ok{true};
        long long ans{};
        for (int i{1}; i <= M; ++i) {
            if (dist[i] == INF) {
                ok = false;
                break;
            }
            ans = std::max(ans, dist[i]);
        }
        if (!ok)
            output << -1;
        else
            output << ans;
        if (testNum + 1 < testCases)
            output << '\n';
    }
    std::cout << output.str() << '\n';
}