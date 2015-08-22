#include <bits/stdc++.h>

#define LL unsigned long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int M = 18;
vector<int> fac[70];
vector<LL> pw[70];
int p[M] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
vector<int> good[70];

LL poww(LL a, int b) {
    LL ans = 1;
    while (b) {
        if (b & 1) ans = ans * a;
        b >>= 1;
        a *= a;
    }
    return ans;
}

LL getRoot(LL n, int r) {
    if (r == 1) return n;
    if (r == 2) {
        LL rt = (LL) sqrt(n + 0.5);
        if (poww(rt, 2) <= n) rt++;
        if (poww(rt, 2) > n) rt--;
        return rt;
    }
    if (r == 3) {
        LL rt = (LL) pow(n + 0.5, 1.0 / r);
        if (poww(rt, 3) <= n) rt++;
        if (poww(rt, 3) > n) rt--;
        return rt;
    }
    int rt = upper_bound(pw[r].begin(), pw[r].end(), n) - pw[r].begin();
    return rt;
}

bool check(int x, int r) {
    vector<int> tmp;
    REP(i, M) {
        if (p[i] <= r) tmp.push_back(p[i]);
    }
    REP(i, fac[x].size()) {
        if (fac[x][i] > r) {
            return 0;
        }
    }
    REP(i, fac[x].size()) {
        if (x % (fac[x][i] * fac[x][i]) == 0) {
            return 0;
        }
    }
    return 1;
}

void init() {
    REPP(i, 4, 62) {
        int now = 1;
        double ans = 1;
        while (ans < 2e18) {
            pw[i].push_back(poww(now, i));
            now++;
            ans = pow(now, i);
        }
    }
    REPP(i, 2, 62) {
        REP(j, M) {
            if (i % p[j] == 0) {
                fac[i].push_back(p[j]);
            }
        }
    }
    REPP(i, 1, 62) {
        REPP(j, 2, 62) {
            if (check(i, j)) {
                good[j].push_back(i);
            }
        }
    }
}

LL calc(LL n, int r) {
    LL ans = 0;
    int odd = 0, even = 0;
    REP(j, good[r].size()) {
        int i = good[r][j];
        //cout << i << ' ';
        if (fac[i].size() & 1) {
            ans -= getRoot(n, i);
            odd++;
        }
        else {
            ans += getRoot(n, i);
            even++;
        }
    }
    //cout << endl;
    ans += odd - even;
    return ans;
}

int main() {
#ifdef HOME
    freopen("J.in", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
#define lld I64d
#endif

    init();

    int t;
    scanf("%d", &t);
    while (t--) {
        LL n;
        int r;
        scanf("%lld%d", &n, &r);
        LL lo = 0, hi = 2 * n + 5;
        while (lo + 1 < hi) {
            LL mid = (lo + hi) >> 1;
            if (calc(mid, r) < n) lo = mid;
            else hi = mid;
        }
        printf("%lld\n", hi);
    }

    return 0;
}
