#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 55;
const int MO = 1e9 + 7;
LL bit[N];
int cnt[N], vis[N], pw[N], n, m;
int dp[N][2][2], f[N][2][2][2];

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

void get2(int a, int b) {
    MST(dp, 0), dp[0][0][0] = 1;
    REPP(i, 1, m) {
        int p = (bit[i] >> a) & 1, q = (bit[i] >> b) & 1;
        REP(x, 2) {
            REP(y, 2) {
                add(dp[i][x][y], dp[i - 1][x][y]);
                add(dp[i][x ^ p][y ^ q], dp[i - 1][x][y]);
            }
        }
    }
}

void get3(int a, int b, int c) {
    //cout << a << ' ' << b << ' ' << c << endl;
    MST(f, 0), f[0][0][0][0] = 1;
    REPP(i, 1, m) {
        int p = (bit[i] >> a) & 1, q = (bit[i] >> b) & 1, r = (bit[i] >> c) & 1;
        REP(x, 2) {
            REP(y, 2) {
                REP(z, 2) {
                    add(f[i][x][y][z], f[i - 1][x][y][z]);
                    add(f[i][x ^ p][y ^ q][z ^ r], f[i - 1][x][y][z]);
                }
            }
        }
    }
}

int main() {
#ifdef HOME
    freopen("F.in", "r", stdin);
#endif
    pw[0] = 1;
    REPP(i, 1, N - 1) pw[i] = pw[i - 1] * 2LL % MO;
    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        MST(vis, 0);
        REPP(i, 1, m) bit[i] = 0;
        REPP(i, 1, m) {
            scanf("%d", cnt + i);
            REP(j, cnt[i]) {
                int x;
                scanf("%d", &x);
                vis[--x] = 1;
                bit[i] |= (1LL << x);
            }
        }
        int ans = 0; 
        REP(i, n) if (vis[i]) add(ans, pw[m - 1]);
        //cout << ans << endl;
        REP(i, n) {
            REPP(j, i + 1, n - 1) {
                get2(i, j);
                add(ans, 6LL * dp[m][1][1] % MO);
                //cout << "hehe" << ans << endl;
            }
        }
        //REPP(i, 1, m) {
        //    cout << i << ' ' << bit[i] << endl;
        //}
        REP(i, n) {
            REPP(j, i + 1, n - 1) {
                REPP(k, j + 1, n - 1) {
                    get3(i, j, k);
                    add(ans, 6LL * f[m][1][1][1] % MO);
                    //cout << "hehe" << ans << endl;
                }
            }
        }
        printf("Case #%d: %d\n", ca++, ans);
    }

    return 0;
}


