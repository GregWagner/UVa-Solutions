#include <algorithm>
#include <climits>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Window {
    long long x, y, w, h;
};

static bool overlapLL(long long ax, long long aw, long long bx, long long bw) {
    return ax < bx + bw && bx < ax + aw;
}

static bool rectsOverlap(const Window& a, const Window& b) {
    return overlapLL(a.x, a.w, b.x, b.w) && overlapLL(a.y, a.h, b.y, b.h);
}

static bool fits(const Window& nw, const std::vector<Window>& windows,
                 long long xmax, long long ymax, int exclude = -1) {
    if (nw.x < 0 || nw.y < 0)
        return false;
    if (nw.x + nw.w > xmax || nw.y + nw.h > ymax)
        return false;
    if (nw.w <= 0 || nw.h <= 0)
        return false;
    for (int i = 0; i < (int)windows.size(); ++i) {
        if (i == exclude)
            continue;
        if (rectsOverlap(nw, windows[i]))
            return false;
    }
    return true;
}

// Generic 1D movement along an axis. pos/sz are the coordinate and size along
// the movement axis; cstart/csize are the coordinate and size along the cross
// axis. Returns the actual number of pixels moved (magnitude) in the requested
// direction.
static long long moveAxis(std::vector<long long>& pos,
                          std::vector<long long>& sz,
                          const std::vector<long long>& cstart,
                          const std::vector<long long>& csize, long long M,
                          int idx, long long D) {
    int n = (int)pos.size();
    if (D == 0 || n == 0)
        return 0;

    bool reflected = D < 0;
    long long mag = (D >= 0) ? D : -D;

    std::vector<long long> p = pos;
    std::vector<long long> s = sz;
    if (reflected) {
        for (int i = 0; i < n; ++i)
            p[i] = M - (p[i] + s[i]);
    }

    std::vector<long long> phase(n, -1);
    std::vector<char> moving(n, 0);
    phase[idx] = 0;
    moving[idx] = 1;

    auto crossOverlap = [&](int i, int j) -> bool {
        return cstart[i] < cstart[j] + csize[j] &&
               cstart[j] < cstart[i] + csize[i];
    };

    long long T = 0;
    while (true) {
        long long minCap = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            if (!moving[i])
                continue;
            long long cap = M - p[i] - s[i] + phase[i];
            if (cap < minCap)
                minCap = cap;
        }

        long long minTc = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            if (!moving[i])
                continue;
            for (int j = 0; j < n; ++j) {
                if (moving[j])
                    continue;
                if (!crossOverlap(i, j))
                    continue;
                if (p[j] < p[i] + s[i])
                    continue; // overlaps or left of i
                long long gap = p[j] - (p[i] + s[i]);
                long long tc = gap + phase[i];
                if (tc < minTc)
                    minTc = tc;
            }
        }

        long long nextEvent = mag;
        if (minCap < nextEvent)
            nextEvent = minCap;
        if (minTc < nextEvent)
            nextEvent = minTc;

        if (minTc <= mag && minTc <= minCap && minTc != LLONG_MAX) {
            // process all contacts happening at minTc
            std::vector<int> toMove;
            for (int i = 0; i < n; ++i) {
                if (!moving[i])
                    continue;
                for (int j = 0; j < n; ++j) {
                    if (moving[j])
                        continue;
                    if (!crossOverlap(i, j))
                        continue;
                    if (p[j] < p[i] + s[i])
                        continue;
                    long long gap = p[j] - (p[i] + s[i]);
                    long long tc = gap + phase[i];
                    if (tc == minTc)
                        toMove.push_back(j);
                }
            }
            for (int j : toMove) {
                if (!moving[j]) {
                    moving[j] = 1;
                    phase[j] = minTc;
                }
            }
            T = minTc;
        } else {
            T = nextEvent;
            if (T < 0)
                T = 0;
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (moving[i]) {
            long long disp = T - phase[i];
            if (disp < 0)
                disp = 0;
            p[i] += disp;
        }
    }

    if (reflected) {
        for (int i = 0; i < n; ++i)
            p[i] = M - (p[i] + s[i]);
    }

    for (int i = 0; i < n; ++i)
        pos[i] = p[i];
    return T;
}

static int findWindowAt(const std::vector<Window>& windows, long long x,
                        long long y) {
    for (int i = (int)windows.size() - 1; i >= 0; --i) {
        // topmost? Problem doesn't specify z-order; windows don't overlap, so
        // at most one contains point.
        if (x >= windows[i].x && x < windows[i].x + windows[i].w &&
            y >= windows[i].y && y < windows[i].y + windows[i].h) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    bool haveScreen = false;
    long long xmax = 0, ymax = 0;
    std::vector<Window> windows;
    int cmdNum = 0;

    std::string token;
    while (std::cin >> token) {
        if (token == "OPEN" || token == "CLOSE" || token == "RESIZE" ||
            token == "MOVE") {
            if (!haveScreen) {
                // malformed input; skip
                continue;
            }
            ++cmdNum;
            if (token == "OPEN") {
                long long x, y, w, h;
                std::cin >> x >> y >> w >> h;
                Window nw{x, y, w, h};
                if (!fits(nw, windows, xmax, ymax)) {
                    std::cout << "Command " << cmdNum
                              << ": OPEN - window does not fit\n";
                } else {
                    windows.push_back(nw);
                }
            } else if (token == "CLOSE") {
                long long x, y;
                std::cin >> x >> y;
                int idx = findWindowAt(windows, x, y);
                if (idx == -1) {
                    std::cout << "Command " << cmdNum
                              << ": CLOSE - no window at given position\n";
                } else {
                    windows.erase(windows.begin() + idx);
                }
            } else if (token == "RESIZE") {
                long long x, y, w, h;
                std::cin >> x >> y >> w >> h;
                int idx = findWindowAt(windows, x, y);
                if (idx == -1) {
                    std::cout << "Command " << cmdNum
                              << ": RESIZE - no window at given position\n";
                } else {
                    Window old = windows[idx];
                    Window nw{old.x, old.y, w, h};
                    if (!fits(nw, windows, xmax, ymax, idx)) {
                        std::cout << "Command " << cmdNum
                                  << ": RESIZE - window does not fit\n";
                    } else {
                        windows[idx].w = w;
                        windows[idx].h = h;
                    }
                }
            } else if (token == "MOVE") {
                long long x, y, dx, dy;
                std::cin >> x >> y >> dx >> dy;
                int idx = findWindowAt(windows, x, y);
                if (idx == -1) {
                    std::cout << "Command " << cmdNum
                              << ": MOVE - no window at given position\n";
                } else {
                    long long actual = 0;
                    long long req = 0;
                    if (dx != 0) {
                        req = (dx >= 0) ? dx : -dx;
                        std::vector<long long> pos(windows.size()),
                            sz(windows.size()), cs(windows.size()),
                            cz(windows.size());
                        for (size_t i = 0; i < windows.size(); ++i) {
                            pos[i] = windows[i].x;
                            sz[i] = windows[i].w;
                            cs[i] = windows[i].y;
                            cz[i] = windows[i].h;
                        }
                        actual = moveAxis(pos, sz, cs, cz, xmax, idx, dx);
                        for (size_t i = 0; i < windows.size(); ++i)
                            windows[i].x = pos[i];
                    } else if (dy != 0) {
                        req = (dy >= 0) ? dy : -dy;
                        std::vector<long long> pos(windows.size()),
                            sz(windows.size()), cs(windows.size()),
                            cz(windows.size());
                        for (size_t i = 0; i < windows.size(); ++i) {
                            pos[i] = windows[i].y;
                            sz[i] = windows[i].h;
                            cs[i] = windows[i].x;
                            cz[i] = windows[i].w;
                        }
                        actual = moveAxis(pos, sz, cs, cz, ymax, idx, dy);
                        for (size_t i = 0; i < windows.size(); ++i)
                            windows[i].y = pos[i];
                    } else {
                        actual = 0;
                        req = 0;
                    }
                    if (req > 0 && actual < req) {
                        std::cout << "Command " << cmdNum << ": MOVE - moved "
                                  << actual << " instead of " << req << "\n";
                    }
                }
            }
        } else {
            // dimension line / new test case
            if (haveScreen) {
                std::cout << windows.size() << " window(s):\n";
                for (const auto& w : windows) {
                    std::cout << w.x << " " << w.y << " " << w.w << " " << w.h
                              << "\n";
                }
                windows.clear();
                cmdNum = 0;
            }
            xmax = std::stoll(token);
            std::cin >> ymax;
            haveScreen = true;
        }
    }

    if (haveScreen) {
        std::cout << windows.size() << " window(s):\n";
        for (const auto& w : windows) {
            std::cout << w.x << " " << w.y << " " << w.w << " " << w.h << "\n";
        }
    }
}