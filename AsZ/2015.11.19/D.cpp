#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define LB(x) ((x) & (-(x)))
#define ALL(a) (a).begin(), (a).end()

#define MAXN 212345

using namespace std;
typedef int arrayN[MAXN];

arrayN last, a, nxt, pre;

int check(int l1, int r1, int l2, int r2) {
    if (l1 > r1 || l2 > r2) return 1;
    int tl1 = l1, tr2 = r2;
    for (; tl1 <= r1 || l2 <= tr2; ) {
        if (tl1 <= r1) {
            if (pre[tl1] < l1 && nxt[tl1] > r2)
                return check(tl1 + 1, r1, l2, r2);
            ++tl1;
        }
        if (l2 <= tr2) {
            if (pre[tr2] < l1 && nxt[tr2] > r2)
                return check(l1, r1, l2, tr2 - 1);
            --tr2;
        }
    }
    return 0;
}

int solve(int l, int r) {
    if (l >= r) return 1;
    int mid = (l + r) >> 1;
    if (!solve(l, mid)) return 0;
    if (!solve(mid + 1, r)) return 0;
    return check(l, mid, mid + 1, r);
}

int main() {
#ifdef HOME
    freopen("D.in", "r", stdin);
#endif
    int T, n;
    for (scanf("%d", &T); T; --T) {
        scanf("%d", &n);
        vector<int> num;
        REPP(i, 1, n) last[i] = 0;
        REPP(i, 1, n) {
            scanf("%d", a + i);
            num.push_back(a[i]);
        }
        sort(ALL(num));
        num.resize(unique(ALL(num)) - num.begin());
        REPP(i, 1, n) a[i] = lower_bound(ALL(num), a[i]) - num.begin() + 1;
        REPP(i, 1, n) {
            pre[i] = last[a[i]];
            last[a[i]] = i;
        }
        for (int i = 1; i <= n; ++i)
            last[i] = n + 1;
        for (int i = n; i >= 1; --i) {
            nxt[i] = last[a[i]];
            last[a[i]] = i;
        }
        //if (T == 4)
    //   for (int i = 1; i<= n; ++i)
      //      printf("%d: \n val: %d, pre: %d, nxt %d\n", i, a[i], pre[i], nxt[i]);
       // printf("%d\n", solve(1, n));
        solve(1, n) ? puts("non-boring") : puts("boring");
    }
    return 0;
}
