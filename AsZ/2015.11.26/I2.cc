#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

typedef tuple<int, int, int> triple;

const int N = 205;
const int L = 44;
const int MO = 1e9 + 7;

int dp[N][N][L];
LL state[L];
map<LL, int> mp;

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

triple decode(int x) {
    int c = x & 1;
    x >>= 1;
    int b = x % 5, a = x / 5;
    return make_tuple(a, b, c);
}

int zip(int a, int b, int c) {
    return (5 * a + b) * 2 + c;
}

void bfs() {
    queue<LL> q;
    int now = 0;
    LL x = 1;
    state[now] = x;
    mp[x] = now++;
    q.push(x);
    while (q.size()) {
        x = q.front(), q.pop();
        //pair 2
        {
            int limit = 2;
            REP(p, limit + 1) {
                LL ns = 0;
                REP(i, 50) {
                    if (x & (1LL << i)) {
                        int a, b, c;
                        tie(a, b, c) = decode(i);
                        if (c || a < p || b < p) continue;
                        ns |= 1LL << zip(b - p, 2 - p, 1);
                    }
                }
                if (ns == 0) continue;
                if (!mp.count(ns)) {
                    state[now] = ns;
                    mp[ns] = now++;
                    q.push(ns);
                }
            }
        }
        //pair 3
        {
            int limit = 1;
            REP(p, limit + 1) {
                LL ns = 0;
                REP(i, 50) {
                    if (x & (1LL << i)) {
                        int a, b, c;
                        tie(a, b, c) = decode(i);
                        if (a < p || b < p) continue;
                        ns |= 1LL << zip(b - p, 1 - p, c);
                    }
                }
                if (ns == 0) continue;
                if (!mp.count(ns)) {
                    state[now] = ns;
                    mp[ns] = now++;
                    q.push(ns);
                }
            }
        }
        //no pair
        {
            int limit = 4;
            REP(p, limit + 1) {
                LL ns = 0;
                REP(i, 50) {
                    if (x & (1LL << i)) {
                        int a, b, c;
                        tie(a, b, c) = decode(i);
                        if (a < p || b < p) continue;
                        ns |= 1LL << zip(b - p, 4 - p, c);
                    }
                }
                if (ns == 0) continue;
                if (!mp.count(ns)) {
                    state[now] = ns;
                    mp[ns] = now++;
                    q.push(ns);
                }
            }
        }
    }
    REP(i, now) {
        assert(__builtin_popcountll(state[i]) == 1);
    }
    //cerr << now << endl;
}

void go(int n, int m) {
    dp[0][0][0] = 1;
    REP(i, n) {
        REP(j, m + 1) {
            REP(k, L) if (dp[i][j][k]) {
                LL x = state[k];
                //pair 2
                {
                    int limit = 2;
                    REP(p, limit + 1) {
                        LL ns = 0;
                        REP(i, 50) {
                            if (x & (1LL << i)) {
                                int a, b, c;
                                tie(a, b, c) = decode(i);
                                if (c || a < p || b < p) continue;
                                ns |= 1LL << zip(b - p, 2 - p, 1);
                            }
                        }
                        if (ns == 0) continue;
                        add(dp[i + 1][j + 2 + 3 * p][mp[ns]], dp[i][j][k]);
                    }
                }
                //pair 3
                {
                    int limit = 1;
                    REP(p, limit + 1) {
                        LL ns = 0;
                        REP(i, 50) {
                            if (x & (1LL << i)) {
                                int a, b, c;
                                tie(a, b, c) = decode(i);
                                if (a < p || b < p) continue;
                                ns |= 1LL << zip(b - p, 1 - p, c);
                            }
                        }
                        if (ns == 0) continue;
                        add(dp[i + 1][j + 3 + 3 * p][mp[ns]], dp[i][j][k]);
                    }
                }
                //no pair
                {
                    int limit = 4;
                    REP(p, limit + 1) {
                        LL ns = 0;
                        REP(i, 50) {
                            if (x & (1LL << i)) {
                                int a, b, c;
                                tie(a, b, c) = decode(i);
                                if (a < p || b < p) continue;
                                ns |= 1LL << zip(b - p, 4 - p, c);
                            }
                        }
                        if (ns == 0) continue;
                        add(dp[i + 1][j + 3 * p][mp[ns]], dp[i][j][k]);
                    }
                }
            }
        }
    }
}

int main() {
#ifdef HOME
    freopen("I2.in", "r", stdin);
#endif
    bfs();
    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        assert(m % 3 == 2);
        REP(i, n + 1) REP(j, m + 1) memset(dp[i][j], 0, sizeof(int) * L);
        go(n, m);
        int ans = 0;
        REP(i, L) {
            LL x = state[i];
            bool good = 0;
            REP(j, 50) if (x & (1LL << j)) {
                int a, b, c;
                tie(a, b, c) = decode(j);
                if (c) {
                    good = 1;
                    break;
                }
            }
            if (good) add(ans, dp[n][m][i]);
        }
        printf("Case #%d: %d\n", ca++, ans);
    }
    return 0;
}

