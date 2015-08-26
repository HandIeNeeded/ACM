#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 10005;
const int MO = 1e9 + 9;

bool test(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int dp[N][100];
int mp[100][10];

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

void init() {
    REPP(i, 10, 100) {
        REP(j, 10) {
            if (test(i * 10 + j)) {
                mp[i][j] = (i * 10 + j) % 100;
            }
            else mp[i][j] = 0;
        }
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    init();
    REPP(i, 100, 999) {
        if (test(i)) {
            dp[3][i % 100]++;
        }
    }
    int n;
    scanf("%d", &n);
    REPP(i, 1, n - 1) {
        REP(j, 100) if (dp[i][j]) {
            REP(k, 10) {
                if (mp[j][k]) {
                    add(dp[i + 1][mp[j][k]], dp[i][j]);
                }
            }
        }
    }
    int ans = 0;
    REP(i, 100) add(ans, dp[n][i]);
    printf("%d\n", ans);

    return 0;
}

