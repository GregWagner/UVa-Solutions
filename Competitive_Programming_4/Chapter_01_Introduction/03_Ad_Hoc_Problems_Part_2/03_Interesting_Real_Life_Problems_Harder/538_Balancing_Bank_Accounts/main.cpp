#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, t;
    int caseNo = 1;
    while (cin >> n >> t) {
        if (n == 0 && t == 0) break;
        vector<string> names(n);
        map<string,int> idx;
        for (int i = 0; i < n; ++i) {
            cin >> names[i];
            idx[names[i]] = i;
        }
        vector<long long> bal(n, 0);
        for (int i = 0; i < t; ++i) {
            string a, b;
            long long amt;
            cin >> a >> b >> amt;
            int u = idx[a];
            int v = idx[b];
            bal[u] += amt;
            bal[v] -= amt;
        }
        cout << "Case #" << caseNo++ << "\n";
        int hub = 0;
        for (int i = 1; i < n; ++i) {
            if (bal[i] == 0) continue;
            if (bal[i] > 0) {
                cout << names[hub] << ' ' << names[i] << ' ' << bal[i] << "\n";
            } else {
                cout << names[i] << ' ' << names[hub] << ' ' << -bal[i] << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
