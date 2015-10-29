#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LB(x) ((x) & (-(x)))

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N], n, ans[N], s[N], tmp[N];

bool cmp(int i, int j) {
    return a[i] < a[j];
}

void update(int x, int d) {
    while (x <= n) {
        s[x] += d;
        x += LB(x);
    }
}

int find(int K) {
    int p = 0;
    for (int i = 18; i >= 0; -- i) {
        p += 1 << i;
        if (p > n || K <= s[p]) p -= 1 << i;
        else K -= s[p];
    }
    return p + 1;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        REPP(i, 1, n) tmp[i] = i;
        REPP(i, 1, n) {
            scanf("%d%d", a + i, b + i);
        }
        sort(tmp + 1, tmp + n + 1, cmp);
        int bad = 0;
        REPP(i, 1, n) s[i] = 0;
        REPP(i, 1, n) update(i, 1);
        REPP(i, 1, n) {
            int id = tmp[i];
            int k = min(b[id], n - i - b[id]) + 1;
            if (k <= 0) {
                bad = 1;
                break;
            }
            int x = find(k);
            update(x, -1), ans[x] = a[id];
        }
        printf("Case #%d:", ca++);
        if (bad) {
            puts(" impossible");
        }
        else {
            REPP(i, 1, n) printf(" %d", ans[i]);
            puts("");
        }
    }
    return 0;
}

