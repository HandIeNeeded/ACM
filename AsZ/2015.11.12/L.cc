#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 105;
int mp[N][N], r, c;

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
bool in(int x, int y) {
    return x >= 1 && x <= r && y >= 1 && y <= c;
}

int calc(int x, int y) {
    int ans = 0;
    REP(d, 4) {
        int good = 1;
        int tx = x + dx[d], ty = y + dy[d];
        while (in(tx, ty)) {
            if (mp[tx][ty] >= mp[x][y]) {
                good = 0;
                break;
            }
            tx += dx[d], ty += dy[d];
        }
        ans += good;
    }
    return ans;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    freopen("lucky.in", "r", stdin);
    freopen("lucky.out", "w", stdout);

    cin >> r >> c;
    REPP(i, 1, r) {
        REPP(j, 1, c) {
            cin >> mp[i][j];
        }
    }

    int ans = 0;
    REPP(i, 1, r) REPP(j, 1, c) ans += calc(i, j);
    cout << ans << endl;

    return 0;
}


