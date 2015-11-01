#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

char mp[10][10];

int go(int x, int y, int d) {
    int cnt = 0;
    if (d == -1) {
        while (x > 0 && mp[x - 1][y] == '.') x += d, cnt++;
        return x == 0 ? cnt : 1000;
    }
    else {
        while (x < 7 && mp[x + 1][y] == '.') x += d, cnt++;
        return x == 7 ? cnt : 1000;
    }
}

int main() {
    ios::sync_with_stdio(0);
    REP(i, 8) cin >> mp[i];
    int ans = 1000, res = 1000;
    REP(i, 8) {
        REP(j, 8) {
            if (mp[i][j] == 'W') {
                ans = min(ans, go(i, j, -1));
            }
            else if (mp[i][j] == 'B') {
                res = min(res, go(i, j, 1));
            }
        }
    }
    if (ans <= res) cout << 'A' << endl;
    else cout << 'B' << endl;

    return 0;
}


