#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 21;
const int inf = 0x01010101;
int dp[2][N][N][N][N];
int need[2][205], n, A, B;

void update(int &x, int y) {
    if (x > y) x = y;
}

int main() {
#ifdef HOME
    freopen("B.in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &A, &B);
    REP(i, 2) {
        REP(j, n) scanf("%d", need[i] + j);
    }
    MST(dp, 1);
    dp[0][0][0][0][0] = 0;
    int cur = 0;
    REP(turn, n) {
        REP(a, A + 1) {
            REP(b, B + 1) {
                REP(c, A + 1) {
                    REP(d, B + 1) {
                        if (dp[cur][a][b][c][d] != inf) {
                            int x = dp[cur][a][b][c][d];
                            //no need for two boys
                            if (!need[0][turn] && !need[1][turn]) {
                                //unused
                                if (a == A && b == B) {
                                    //both no use
                                    if (c == A && d == B) {
                                        update(dp[cur ^ 1][a][b][c][d], x);
                                    }
                                    //second one used
                                    else {
                                        if (d) update(dp[cur ^ 1][a][b][c][d - 1], x);
                                        else update(dp[cur ^ 1][a][b][A][B], x + 1);
                                    }
                                }
                                else {
                                    //first one used
                                    if (c == A && d == B) {
                                        if (b) update(dp[cur ^ 1][a][b - 1][c][d], x);
                                        else update(dp[cur ^ 1][A][B][c][d], x + 1);
                                    }
                                    //both used
                                    else {
                                        int add = 0;
                                        int na, nb, nc, nd;
                                        if (b) {
                                            na = a, nb = b - 1;
                                        }
                                        else {
                                            add++;
                                            na = A, nb = B;
                                        }
                                        if (d) {
                                            nc = c, nd = d - 1;
                                        }
                                        else {
                                            add++;
                                            nc = A, nd = B;
                                        }
                                        update(dp[cur ^ 1][na][nb][nc][nd], x + add);
                                    }
                                }
                            }
                            //both two boys need tickets
                            else if (need[0][turn] && need[1][turn]) {
                                int add = 0;
                                int na, nb, nc, nd;
                                if (!a || !b) {
                                    add++;
                                    na = A - 1, nb = B - 1;
                                }
                                else {
                                    na = a - 1, nb = b - 1;
                                }
                                if (!c || !d) {
                                    add++;
                                    nc = A - 1, nd = B - 1;
                                }
                                else {
                                    nc = c - 1, nd = d - 1;
                                }
                                update(dp[cur ^ 1][na][nb][nc][nd], x + add);
                            }
                            //only one of them need a ticket
                            else {
                                cout << "hehe" << endl;
                                //has a ticket
                                if ((a && b) || (c && d)) {
                                    if (a && b) {
                                        if (c == A && d == B) {
                                            update(dp[cur ^ 1][a - 1][b - 1][c][d], x);
                                        }
                                        else {
                                            if (d) {
                                                update(dp[cur ^ 1][a - 1][b - 1][c][d - 1], x);
                                                cout << a - 1 << ' ' << b - 1 << ' ' << c << ' ' << d - 1 << ' ' << x << endl;
                                            }
                                            else {
                                                update(dp[cur ^ 1][a - 1][b - 1][A][B], x + 1);
                                                cout << a - 1 << ' ' << b - 1 << ' ' << A << ' ' << B << ' ' << x + 1 << endl;
                                            }
                                        }
                                    }
                                    if (c && d) {
                                        if (a == A && b == B) {
                                            update(dp[cur ^ 1][a][b][c - 1][d - 1], x);
                                        }
                                        else {
                                            if (b) {
                                                update(dp[cur ^ 1][a][b - 1][c - 1][d - 1], x);
                                            }
                                            else {
                                                update(dp[cur ^ 1][A][B][c - 1][d - 1], x + 1);
                                            }
                                        }
                                    }
                                }
                                //not have one
                                else {
                                    cout << "xixi" << endl;
                                    if (d) {
                                        update(dp[cur ^ 1][A - 1][B - 1][c][d - 1], x + 1);
                                    }
                                    else {
                                        update(dp[cur ^ 1][A - 1][B - 1][A][B], x + 2);
                                        cout << x + 2 << ' ' << A - 1 << ' ' << B - 1 << ' ' << A << ' ' << B << endl;
                                        cout << "lala" << endl;
                                    }
                                    if (b) {
                                        update(dp[cur ^ 1][a][b - 1][A - 1][B - 1], x + 1);
                                    }
                                    else {
                                        update(dp[cur ^ 1][A][B][A - 1][B - 1], x + 2);
                                        cout << x + 2 << ' ' << A << ' ' << B << ' ' << A - 1 << ' ' << B - 1 << endl;
                                        cout << "lala" << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        MST(dp[cur], 1);
        cur ^= 1;
    }
    int ans = inf;
    REP(a, A + 1) REP(b, B + 1) REP(c, A + 1) REP(d, B + 1) if (dp[cur][a][b][c][d] < inf) {
        int add = 0;
        if (a == A && b == B) add++;
        if (c == A && d == B) add++;
        if (dp[cur][a][b][c][d] - add < ans) {
            cout << a << ' ' << b << ' '  << c << ' ' << d << ' ' << dp[cur][a][b][c][d] << ' ' << add << ' ' << ans << endl;
        }
        ans = min(ans, dp[cur][a][b][c][d] - add);
    }
    printf("%d\n", ans);
    return 0;
}
