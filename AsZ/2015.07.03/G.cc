#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 105;
const int MO = 242121643;
int a[N];

int c[N][N];

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}


void init() {
    REPP(i, 0, N - 1) {
        c[i][0] = c[i][i] = 1;
        REPP(j, 1, i - 1) {
            c[i][j] = c[i - 1][j - 1];
            add(c[i][j], c[i - 1][j]);
        }
    }
}

int C(int x, int y) {
    if (x < y || x < 0 || y < 0) return 0;
    return c[x][y];
}

int main() {
    //freopen("game.in", "r", stdin);
    //freopen("game.out", "w", stdout);
    ios :: sync_with_stdio(0);
    init();

    int n, k;
    while (cin >> n >> k, n | k) {
        int cnt = 0;
        REPP(i, 1, n) {
            int x;
            cin >> x;
            if (x == 1) cnt++;
        }
        int ans = 0;
        for (int i = 1; i <= cnt; i += 2) {
            add(ans, 1LL * C(cnt, i) * C(n - cnt, k - i) % MO);
        }
        cout << ans << endl;
    }

    return 0;
}
