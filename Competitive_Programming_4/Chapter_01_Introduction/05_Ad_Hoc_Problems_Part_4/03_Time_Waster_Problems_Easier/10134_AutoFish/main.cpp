#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    if (!(cin >> testCases))
        return 0;
    string dummy;
    getline(cin, dummy); // end of line
    getline(cin, dummy); // blank line

    for (int tc = 0; tc < testCases; ++tc) {
        string action;
        int bait = 0;
        int totalFish = 0;
        int baitUnits = 0;
        int fishInstruction = 0;
        int instructionsAfterFish = 0;

        while (getline(cin, action) && !action.empty()) {
            if (action == "lunch" || (baitUnits == 3 && action == "bait") ||
                (baitUnits == 0 && action == "fish")) {
                if (totalFish > 0)
                    ++instructionsAfterFish;
            } else if (action == "bait") {
                if (++bait == 2) {
                    bait = 0;
                    ++baitUnits;
                }
                if (totalFish > 0)
                    ++instructionsAfterFish;
            } else if (action == "fish") {
                if (totalFish == 0) {
                    --baitUnits;
                    ++totalFish;
                } else {
                    ++fishInstruction;
                    ++instructionsAfterFish;
                    if (fishInstruction > 2 && instructionsAfterFish > 6) {
                        --baitUnits;
                        ++totalFish;
                        fishInstruction = 0;
                        instructionsAfterFish = 0;
                    }
                }
            }
        }
        cout << totalFish << "\n";
        if (tc + 1 < testCases)
            cout << "\n";
    }
}
