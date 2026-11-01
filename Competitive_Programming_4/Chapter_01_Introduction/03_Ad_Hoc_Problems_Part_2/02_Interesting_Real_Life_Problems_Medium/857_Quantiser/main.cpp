#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Event {
    int code; // 0 NoteOff, 1 NoteOn
    int note;
    long long absTime; // quantized absolute ticks
    int origIdx;
    long long origAbs; // not needed
};

long long toAbs(int m, int b, int t) {
    return (long long)(m - 1) * 4 * 480 + (long long)(b - 1) * 480 + t;
}
void fromAbs(long long absTime, int& m, int& b, int& t) {
    const long long perMeasure = 4LL * 480;
    m = int(absTime / perMeasure) + 1;
    long long rem = absTime % perMeasure;
    b = int(rem / 480) + 1;
    t = int(rem % 480);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        if (n == -1)
            break;
        vector<Event> ev;
        ev.reserve(n);
        for (int i = 0; i < n; ++i) {
            int code, note, m, b, t;
            cin >> code >> note >> m >> b >> t;
            long long absTime = toAbs(m, b, t);
            long long q =
                ((absTime + 30) / 60) * 60; // round to nearest 60, tie up
            ev.push_back({code, note, q, i, absTime});
        }
        // stable sort by quantized time then original index
        sort(ev.begin(), ev.end(), [](const Event& a, const Event& b) {
            if (a.absTime != b.absTime)
                return a.absTime < b.absTime;
            return a.origIdx < b.origIdx;
        });
        vector<char> keep(ev.size(), 1);
        map<int, vector<int>> stackMap; // note -> stack of indices in ev
        for (size_t i = 0; i < ev.size(); ++i) {
            int note = ev[i].note;
            if (ev[i].code == 1) {
                stackMap[note].push_back((int)i);
            } else {
                auto& st = stackMap[note];
                if (!st.empty()) {
                    int idxOn = st.back();
                    st.pop_back();
                    if (ev[idxOn].absTime == ev[i].absTime) {
                        keep[idxOn] = 0;
                        keep[i] = 0;
                    }
                }
            }
        }
        vector<Event> outEv;
        for (size_t i = 0; i < ev.size(); ++i)
            if (keep[i])
                outEv.push_back(ev[i]);
        cout << outEv.size() << "\n";
        for (auto& e : outEv) {
            int m, b, t;
            fromAbs(e.absTime, m, b, t);
            cout << e.code << ' ' << e.note << ' ' << m << ' ' << b << ' ' << t
                 << "\n";
        }
    }
    cout << "-1\n";
}
