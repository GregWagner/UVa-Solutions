#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    string dummy;
    getline(cin, dummy);

    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        string s;
        getline(cin, s);
        if (s.empty()) {
            getline(cin, s);
        }
        int a = 0, b = 0;
        size_t i = 0;
        while (i < s.size() && isdigit((unsigned char)s[i])) {
            a = a * 10 + (s[i] - '0');
            ++i;
        }
        while (i < s.size()) {
            if (isdigit((unsigned char)s[i])) {
                b = s[i] - '0';
                break;
            }
            ++i;
        }
        long long hundredths = (long long)a * 50 + (long long)b * 5;
        long long ip = hundredths / 100;
        long long rem = hundredths % 100;
        if (rem < 0)
            rem += 100;
        cout << "Case " << caseNum << ": ";
        if (rem == 0) {
            cout << ip;
        } else if (rem % 50 == 0 && rem % 100 == 50) {
            // x.5
            cout << ip << ".5";
        } else if (rem % 10 == 0) {
            // ends in 0, e.g. 60 -> should be .6
            cout << ip << "." << (rem / 10);
        } else {
            cout << ip << "." << (rem / 10) << (rem % 10);
        }
        cout << '\n';
    }
}
