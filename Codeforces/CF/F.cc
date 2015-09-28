#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 5005;
const int INF = 0x3f3f3f3f;

vector<int> edge[N];
int dp[N][2][N], tmp[2][N], cnt;
int son[N], n;

void update(int &x, int y) {
    if (x > y) x = y;
}

void dfs(int x, int p) {
    REP(i, 2) {
        REPP(j, 0, cnt) {
            dp[x][i][j] = tmp[i][j] = INF;
        }
    }
    if (edge[x].size() == 1u) {
        son[x]++;
        dp[x][0][0] = 0;
        dp[x][1][1] = 0;
        return ;
    }
    REP(i, 2) dp[x][i][0] = 0;
    for (auto &y: edge[x]) {
        if (y != p) {
            dfs(y, x);
            REP(a, 2) {
                REPP(d, 0, son[x]) {
                    REP(b, 2) {
                        REPP(c, 0, son[y]) if (dp[y][b][c] != INF) {
                            if (d + c <= cnt) update(tmp[a][d + c], dp[x][a][d] + dp[y][b][c] + (a != b));
                        }
                    }
                }
            }
            son[x] += son[y];
            son[x] = min(cnt, son[x]);
            REP(i, 2) {
                REPP(j, 0, son[x]) {
                    dp[x][i][j] = tmp[i][j];
                    tmp[i][j] = INF;
                }
            }
        }
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    cin >> n;
    if (n == 2) {
        cout << 1 << endl;
        return 0;
    }
    REPP(i, 1, n - 1) {
        int x, y;
        scanf("%d%d", &x, &y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    REPP(i, 1, n) if (edge[i].size() == 1u) {
        cnt++;
    }
    cnt >>= 1;
    int ans = 0;
    REPP(i, 1, n) if (edge[i].size() > 1u) {
        dfs(i, 0);
        ans = min(dp[i][0][cnt], dp[i][1][cnt]);
        break;
    }
    cout << ans << endl;
    return 0;
}
