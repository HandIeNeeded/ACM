#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define ALL(a) (a).begin(), (a).end()
#define LB(x) ((x) & (-(x)))

using namespace std;

const int N = 1e5 + 5;
const int inf = 1 << 30;
int a[N], cnt[N], tot, n, K, M;
int Left[N], Right[N];
vector<int> num;

struct Query {
    int l, r, id;
}p[N];

int get(int x) {
    return x / M;
}

bool cmp(const Query &a, const Query &b) {
    return get(a.l) < get(b.l) || (get(a.l) == get(b.l) && a.r < b.r);
}

void update(int x, int d) {
    while (x <= tot) {
        cnt[x] += d;
        x += LB(x);
    }
}

int query(int x) {
    int ans = 0;
    while (x) {
        ans += cnt[x];
        x -= LB(x);
    }
    return ans;
}

int L, R;
LL ans;

LL query(int l, int r) {
    if (get(l) != get(L)) {
        REPP(i, 1, tot) cnt[i] = 0;
        L = inf, R = -inf, ans = 0;
    }
    int bound = (get(l) + 1) * M, A, B;
    for (int i = max(bound, R + 1); i <= r; i++) {
        A = Left[a[i] - 1], B = Right[a[i] - 1];
        ans += query(A - 1) - query(B - 1);
        update(a[i], 1);
    }
    LL res = ans;
    for (int i = l; i < min(bound, r + 1); i++) {
        A = Left[a[i] - 1], B = Right[a[i] - 1];
        ans += query(A - 1) - query(B - 1);
        update(a[i], 1);
    }
    for (int i = l; i < min(bound, r + 1); i++) {
        update(a[i], -1);
    }
    L = l, R = r;
    swap(ans, res);
    return res;
}

LL res[N];

int in() {
    char c;
    while (c = getchar(), (c < '0' || c > '9') && (c != '-'));
    bool flag = (c == '-');
    if (flag) c = getchar();
    int x = 0;
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - 48;
        c = getchar();
    }
    return flag ? -x : x;
}

void out(LL x) { //int
    if (x < 0) putchar('-'), x = -x;
    int len = 0, bit[12]; // LL  -> bit[20]
    while (x) {
        bit[len++] = x % 10;
        x /= 10;
    }
    if (!len) bit[len++] = 0;
    while (len--) putchar(bit[len] + 48);
    putchar('\n');
}
int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    scanf("%d%d", &n, &K);
    //REP(i, n) scanf("%d", a + i), num.push_back(a[i]);
    M = int(sqrt(n)) + 5;
    REP(i, n) {
        a[i] = in();
        num.push_back(a[i]);
    }
    sort(ALL(num)), num.resize(unique(ALL(num)) - num.begin());
    tot = num.size();
    REP(i, n) a[i] = lower_bound(ALL(num), a[i]) - num.begin() + 1;
    REP(i, tot) {
        int &A = Left[i], &B = Right[i];
        A = num[i] + K, B = num[i] - K;
        A = upper_bound(ALL(num), A) - num.begin() + 1;
        B = lower_bound(ALL(num), B) - num.begin() + 1;
    }
    int Q;
    Q = in();
    //scanf("%d", &Q);
    L = inf, R = -inf;
    REP(i, Q) {
        int x, y;
        x = in(), y = in();
        //scanf("%d%d", &x, &y);
        p[i] = (Query) {x, y, i};
    }
    sort(p, p + Q, cmp);
    REP(i, Q) {
        res[p[i].id] = query(p[i].l, p[i].r);
    }
    REP(i, Q) {
        //printf("%lld\n", res[i]);
        out(res[i]);
    }
    return 0;
}

