#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1005;
const int MO = 1e9 + 7;
int C[N][N];

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

void init() {
    REPP(i, 0, N - 1) {
        C[i][0] = C[i][i] = 1;
        REPP(j, 1, i - 1) {
            C[i][j] = C[i - 1][j];
            add(C[i][j], C[i - 1][j - 1]);
        }
    }
}

int dp[N][N], son[N];
int tmp[N];
vector<int> edge[N];

void dfs(int x, int p = 0) {
    int &a = son[x];
    for (auto &y: edge[x]) {
        if (y != p) {
            dfs(y, x);
            int b = son[y];
            if (a == 0) {
                REP(i, b + 1) tmp[i] = dp[y][i];
            }
            else {
                REP(i, a + 1) {
                    REP(j, b + 1) {
                        add(tmp[i + j], 1LL * C[a + b][a] * dp[x][i] % MO * dp[y][j] % MO);
                    }
                }
            }
            a += b;
            REP(i, a + 1) dp[x][i] = tmp[i], tmp[i] = 0;//clear the tmp
        }
    }
    if (a == 0) {
        dp[x][1] = 1;
    }
    else {
        for (int i = a + 1; i >= 1; i--) {//a + 1
            dp[x][i] = 1LL * a * dp[x][i] % MO;
            add(dp[x][i], dp[x][i - 1]);
        }
    }
    a++;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    init();

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        REPP(i, 1, n) edge[i].clear(), son[i] = 0;
        REPP(i, 1, n - 1) {
            int x, y;
            scanf("%d%d", &x, &y);
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        REPP(j, 1, n) REPP(k, 0, n) dp[j][k] = 0;
        dfs(1);
        printf("Case #%d: %d\n", ca++, dp[1][k]);
    }

    return 0;
}
