#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define id(x) ((x) / BLK)
#define next hehehe

using namespace std;

const int N = 1e4 + 5;
const int INF = 0x3f3f3f3f;

int BLK, L, R;
int a[N], n;
LL ans[N], sum;

struct Query{
    int l, r, id;
}q[N];

bool cmp(Query a, Query b) {
    return id(a.l) < id(b.l) || (id(a.l) == id(b.l) && a.r < b.r);
}

map<int, int> d, invd;
int A;

LL query(int l, int r) {
    int bound = (id(l) + 1) * BLK;
    if (id(l) != id(L)) {
        d.clear(), invd.clear();
        L = INF, R = -INF;
        A = 0, sum = 0;
    }
    for (int i = max(bound, R + 1); i <= r; i++) {
        vector<pair<int, int> > update;
        for (auto &p: d) {
            int tmp = __gcd(p.first, a[i]);
            update.push_back({tmp, p.second});
        }
        d.clear();
        REP(i, update.size()) {
            int x = update[i].first;
            if (!d.count(x)) d[x] = update[i].second;
            else d[x] = min(d[x], update[i].second);
        }
        if (!d.count(a[i])) d[a[i]] = i - 1;
        else d[a[i]] = min(d[a[i]], i - 1);
        //for (auto &p: d) {
        //    cout << p.first << ' ' << p.second << endl;
        //}
        //cout << "hehehehe" << endl;
        int pre = 0;
        for (auto it = d.rbegin(); it != d.rend(); it++) {
            auto p = *it;
            sum += 1LL * (i - p.second - pre) * p.first;
            pre = i - p.second;
        }
        A = __gcd(A, a[i]);
        invd[A] = max(invd[A], i + 1);
    }
    LL ans = sum;
    map<int, int> use = invd;
    for (int i = min(bound - 1, r); i >= l; i--) {
        vector<pair<int, int> > update;
        for (auto &p: use) {
            int tmp = __gcd(p.first, a[i]);
            update.push_back({tmp, p.second});
        }
        use.clear();
        REP(i, update.size()) {
            int x = update[i].first;
            use[x] = max(use[x], update[i].second);
        }
        use[a[i]] = max(use[a[i]], i + 1);
        int pre = 0;
        for (auto it = use.rbegin(); it != use.rend(); it++) {
            auto p = *it;
            sum += 1LL * (p.second - i - pre) * p.first;
            pre = p.second - i;
        }
    }
    swap(ans, sum);
    L = l, R = r;
    return ans;
}

int main() {
#ifdef HOME
    freopen("tmp.in", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
#define lld I64d
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        REP(i, n) scanf("%d", a + i);
        BLK = int(sqrt(n + 0.5)) + 1;
        int m;
        scanf("%d", &m);
        REPP(i, 1, m) {
            int x, y;
            scanf("%d%d", &x, &y);
            x--, y--;
            q[i] = {x, y, i};
        }
        sort(q + 1, q + m + 1, cmp);
        L = INF, R = -INF, sum = 0;
        REPP(i, 1, m) {
            ans[q[i].id] = query(q[i].l, q[i].r);
        }
        REPP(i, 1, m) {
            printf("%lld\n", ans[i]);
        }
    }

    return 0;
}
