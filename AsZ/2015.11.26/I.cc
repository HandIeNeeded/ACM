#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;
typedef tuple<int, int, int> unit;

const int N = 205;
const int K = 151;
const int MO = 1e9 + 7;
LL state[N];
int dp[N][N][K], now;
map<LL, int> mp;

unit decode(int x) {
    int c = x & 1;
    x >>= 1;
    int b = x % 5, a = x / 5;
    return make_tuple(a, b, c);
}

int zip(unit x) {
    int a, b, c;
    tie(a, b, c) = x;
    return (5 * a + b) * 2 + c;
}

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

void bfs() {
    queue<LL> q;
    LL st = 1;
    mp[0] = 0, now = 1;//0 for invalid
    mp[st] = now;
    state[now++] = st;
    q.push(st);
    while (q.size()) {
        st = q.front(); q.pop();
        //pair 2 + triple
        {
            int limit = 2;
            REP(p, limit + 1) {
                LL ns = 0;//new state
                REP(i, 50) {
                    if (st & (1 << i)) {
                        int a, b, c;
                        tie(a, b, c) = decode(i);
                        if (c || a < p || b < p) {
                            continue;
                        }
                        ns |= 1LL << (zip(make_tuple(b - p, 2 - p, 1)));
                    }
                }
                if (!mp.count(ns)) {
                    mp[ns] = now;
                    state[now++] = ns;
                    q.push(ns);
                }
            }
        }

        //pair 3 + triple
        {
            int limit = 1;
            REP(p, limit + 1) {
                LL ns = 0;
                REP(i, 50) {
                    if (st & (1 << i)) {
                        int a, b, c;
                        tie(a, b, c) = decode(i);
                        if (a < p || b < p) {
                            continue;
                        }
                        ns |= 1LL << (zip(make_tuple(b - p, 1 - p, c)));
                    }
                }
                if (!mp.count(ns)) {
                    mp[ns] = now;
                    state[now++] = ns;
                    q.push(ns);
                }
            }
        }

        //no pair + triple
        {
            int limit = 4;
            REP(p, limit + 1) {
                LL ns = 0;
                REP(i, 50) {
                    if (st & (1 << i)) {
                        int a, b, c;
                        tie(a, b, c) = decode(i);
                        if (a < p || b < p) {
                            continue;
                        }
                        ns |= 1LL << (zip(make_tuple(b - p, 4 - p, c)));
                    }
                }
                if (!mp.count(ns)) {
                    mp[ns] = now;
                    state[now++] = ns;
                    q.push(ns);
                }
            }
        }
    }
    cerr << now << endl;
}

void go(int n, int m) {
    dp[0][0][1] = 1;
    REP(i, n) {
        REP(j, m + 1) {
            REP(k, K) if (dp[i][j][k]) {
                //cerr << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << endl;
                //pair 2
                {
                    int limit = 2;
                    LL st = state[k];
                    REP(p, limit + 1) {
                        LL ns = 0;
                        REP(i, 50) {
                            if (st & (1 << i)) {
                                int a, b, c;
                                tie(a, b, c) = decode(i);
                                if (c || a < p || b < p) {
                                    continue;
                                }
                                ns |= 1LL << (zip(make_tuple(b - p, 2 - p, 1)));
                            }
                        }
                        assert(mp.count(ns));
                        int nk = mp[ns];
                        if (j + p * 3 + 2 <= m) {
                            add(dp[i + 1][j + p * 3 + 2][nk], dp[i][j][k]);
                        }
                    }
                }

                //pair 3
                {
                    int limit = 1;
                    LL st = state[k];
                    REP(p, limit + 1) {
                        LL ns = 0;
                        REP(i, 50) {
                            if (st & (1 << i)) {
                                int a, b, c;
                                tie(a, b, c) = decode(i);
                                if (a < p || b < p) {
                                    continue;
                                }
                                ns |= 1LL << (zip(make_tuple(b - p, 1 - p, c)));
                            }
                        }
                        assert(mp.count(ns));
                        int nk = mp[ns];
                        if (j + p * 3 + 3 <= m) {
                            add(dp[i + 1][j + p * 3 + 3][nk], dp[i][j][k]);
                        }
                    }
                }

                //no pair
                {
                    int limit = 4;
                    LL st = state[k];
                    REP(p, limit + 1) {
                        LL ns = 0;
                        REP(i, 50) {
                            if (st & (1 << i)) {
                                int a, b, c;
                                tie(a, b, c) = decode(i);
                                if (a < p || b < p) {
                                    continue;
                                }
                                ns |= 1LL << (zip(make_tuple(b - p, 4 - p, c)));
                            }
                        }
                        assert(mp.count(ns));
                        int nk = mp[ns];
                        if (j + p * 3 <= m) {
                            add(dp[i + 1][j + p * 3][nk], dp[i][j][k]);
                        }
                    }
                }
            }
        }
    }
}

int main() {
#ifdef HOME
    freopen("I.in", "r", stdin);
#endif
    int t, ca = 1;
    bfs();
    REP(i, 10) {
        cout << state[i] << ' ';
    }
    cout << endl;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        REP(i, n + 1) REP(j, m + 1) REP(k, K) dp[i][j][k] = 0;
        go(n, m);
        int ans = 0;
        REP(i, K) if (i) {
            int good = 0;
            REP(j, 50) if (i & (1LL << j)) {
                int a, b, c;
                tie(a, b, c) = decode(j);
                if (c) {
                    good = 1;
                    break;
                }
            }
            if (good) {
                cout << "hehe" << i << endl;
                add(ans, dp[n][m][i]);
            }
        }
        cerr << dp[n][m][0] << endl;
        printf("Case #%d: %d\n", ca++, ans);
    }
    return 0;
}
