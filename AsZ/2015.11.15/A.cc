#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e4 + 5;
struct Unit{
    int L, R, W, H;
}p[N];
int n, r;

bool cmp(const Unit &a, const Unit &b) {
    return a.R < b.R || (a.R == b.R && a.L < b.L);
}

LL calc(int x) {
    LL ans = 0;
    REP(i, n) {
        if (p[i].L < x) {
            if (p[i].R <= x) {
                ans += 1LL * p[i].W * p[i].H;
            }
            else {
                ans += 1LL * (x - p[i].L) * p[i].H;
            }
        }
    }
    return ans;
}

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &r);
        scanf("%d", &n);
        LL tot = 0;
        REP(i, n) {
            int a, b, c, d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            p[i] = (Unit) {a, a + c, c, d};
            tot += 1LL * c * d;
        }
        p[n + 1] = (Unit) {r, r, 0, 0};
        sort(p, p + n, cmp);
        //REP(i, n) {
        //    cout << p[i].L << ' ' << p[i].R << ' ' << p[i].W << ' ' << p[i].H << endl;
        //}
        int lo = 0, hi = r;
        while (lo + 1 < hi) {
            int mid = (lo + hi) >> 1;
            LL sum = calc(mid);
            if (sum >= tot - sum) {
                hi = mid;
            }
            else lo = mid;
        }
        LL res = calc(hi);
        //cout << "res: " << res << endl;
        lo = hi, hi = r + 1;
        while (lo + 1 < hi) {
            int mid = (lo + hi) >> 1;
            LL sum = calc(mid);
            if (sum == res) {
                lo = mid;
            }
            else {
                hi = mid;
            }
        }
        printf("%d\n", lo);
    }

    return 0;
}


