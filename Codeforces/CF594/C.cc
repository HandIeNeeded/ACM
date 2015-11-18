#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
pair<int, int> p[N];
int id[2][N];

bool cmpx(int i, int j) {
    return p[i].first < p[j].first;
}

bool cmpy(int i, int j) {
    return p[i].second < p[j].second;
}

bool in(int x, int l, int r, int u, int d) {
    return p[x].first >= l && p[x].first <= r && p[x].second >= u && p[x].second <= d;
}

int main() {
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    REP(i, n) {
        int x, y, z, w;
        scanf("%u%u%u%u", &x, &y, &z, &w);
        REP(j, 2) p[i] = {x + z, y + w};
        //cout << p[i].first << ' ' << p[i].second << endl;
    }
    REP(j, 2) REP(i, n) id[j][i] = i;
    sort(id[0], id[0] + n, cmpx);
    sort(id[1], id[1] + n, cmpy);
    int L, R, U, D;
    LL ans = LLONG_MAX;

    //srand(time(0) % clock());
    //random_shuffle(id[0], id[0] + k + 1);
    //random_shuffle(id[1], id[1] + k + 1);
    clock_t st = clock();
    REP(a, k + 1) {
        set<int> bad;
        L = p[id[0][a]].first;
        REP(t, a) {
            bad.insert(id[0][t]);
        }
        REP(b, k + 1) {
            R = p[id[0][n - 1 - b]].first;
            REP(t, b) {
                bad.insert(id[0][n -  1 - t]);
            }
            REP(c, k + 1) {
                U = p[id[1][c]].second;
                REP(t, c) {
                    bad.insert(id[1][t]);
                }
                REP(d, k + 1) {
                    D = p[id[1][n - 1 - d]].second;
                    REP(t, d) {
                        bad.insert(id[1][n - 1 - t]);
                    }
                    int cnt = 0;
                    for (auto &x: bad) {
                        if (!in(x, L, R, U, D)) {
                            cnt++;
                        }
                    }
                    if (cnt <= k) {
                        int W = R - L, H = D - U;
                        W = max(W, 2), H = max(H, 2);
                        if (W & 1) W++;
                        if (H & 1) H++;
                        //if (1LL * W * H < ans) {
                        //    cout << W << ' ' << H << endl;
                        //    cout << L << ' ' << R << ' ' << U << ' ' << D << endl;
                        //}
                        ans = min(ans, 1LL * W * H);
                    }
                    //if (1.0 * (clock() - st) / CLOCKS_PER_SEC > 0.9) {
                    //    printf("%lld\n", ans / 4);
                    //    return 0;
                    //}
                }
            }
        }
    }
    printf("%lld\n", ans / 4);
    return 0;
}

