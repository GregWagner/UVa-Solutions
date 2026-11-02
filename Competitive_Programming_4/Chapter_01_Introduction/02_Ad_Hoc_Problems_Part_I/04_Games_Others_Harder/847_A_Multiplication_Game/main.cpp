#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    while (cin >> n) {
        long long p = 1;
        bool stanTurn = true;
        while (p < n) {
            if (stanTurn) p *= 9;
            else p *= 2;
            if (p >= n) break;
            stanTurn = !stanTurn;
        }
        // Actually need to know who made last move
        // Simpler: simulate step by step tracking who moves
        p = 1;
        stanTurn = true;
        while (true) {
            if (stanTurn) p *= 9;
            else p *= 2;
            if (p >= n) break;
            stanTurn = !stanTurn;
        }
        if (stanTurn) cout << "Stan wins.\n";
        else cout << "Ollie wins.\n";
    }
    return 0;
}
