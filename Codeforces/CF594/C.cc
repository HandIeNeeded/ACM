#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
pair<int, int> p[2][N];
int id[2][N];

bool cmpx(int i, int j) {
    return p[0][i].first < p[0][j].first;
}

bool cmpy(int i, int j) {
    return p[1][i].second < p[1][j].second;
}

bool in(int x, int l, int r, int u, int d) {
    return p[0][x].first >= l && p[0][x].first <= r && p[0][x].second >= u && p[0][x].second <= d;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    REP(i, n) {
        int x, y, z, w;
        scanf("%u%u%u%u", &x, &y, &z, &w);
        REP(j, 2) p[j][i] = {x + z, y + w};
    }
    REP(j, 2) REP(i, n) id[j][i] = i;
    sort(id[0], id[0] + n, cmpx);
    sort(id[1], id[1] + n, cmpy);
    int L, R, U, D;
    LL ans = LLONG_MAX;

    //REP(i, n) {
    //    cout << p[0][i].first << ' ' << p[0][i].second << endl;
    //}
    srand(time(0) % clock());
    random_shuffle(id[0], id[0] + k + 1);
    random_shuffle(id[1], id[1] + k + 1);
    clock_t st = clock();
    REP(a, k + 1) {
        L = p[0][id[0][a]].first;
        REP(b, k + 1) {
            R = p[0][id[0][n - 1 - b]].first;
            REP(c, k + 1) {
                U = p[1][id[1][c]].second;
                REP(d, k + 1) {
                    D = p[1][id[1][n - 1 - d]].second;
                    int cnt = 0;
                    REP(i, n) {
                        if (in(i, L, R, U, D)) {
                            cnt++;
                        }
                    }
                    if (cnt >= n - k) {
                        int W = R - L, H = D - U;
                        W = max(W, 2), H = max(H, 2);
                        //if (1LL * W * H < ans) {
                        //    cout << W << ' ' << H << endl;
                        //    cout << L << ' ' << R << ' ' << U << ' ' << D << endl;
                        //}
                        ans = min(ans, 1LL * W * H);
                    }
                    if (1.0 * (clock() - st) / CLOCKS_PER_SEC > 0.9) {
                        printf("%lld\n", ans / 4);
                        return 0;
                    }
                }
            }
        }
    }
    printf("%lld\n", ans / 4);
    return 0;
}

