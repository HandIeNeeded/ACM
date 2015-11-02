#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 400005;
typedef long long ll;
#define lson(x) ((x)<<1)
#define rson(x) (((x)<<1)|1)

struct SegTree {
    int lc[maxn<<2], rc[maxn<<2];
    ll S[maxn<<2], L[maxn<<2], R[maxn<<2], T[maxn<<2];

    int length(int u) {
        return rc[u] - lc[u] + 1;
    }

    void maintain(int u, ll a) {
        T[u] += a;
        S[u] += a * length(u);
        ll add = a * (length(u) + 1) * length(u) / 2;
        L[u] += add;
        R[u] += add;
    }

    void pushup(int u) {
        S[u] = S[lson(u)] + S[rson(u)];
        L[u] = L[lson(u)] + L[rson(u)] + S[rson(u)] * length(lson(u));
        R[u] = R[rson(u)] + R[lson(u)] + S[lson(u)] * length(rson(u));
    }

    void pushdown(int u) {
        if (T[u]) {
            maintain(lson(u), T[u]);
            maintain(rson(u), T[u]);
            T[u] = 0;
        }
    }

    void build (int u, int l, int r) {
        lc[u] = l, rc[u] = r;
        S[u] = L[u] = R[u] = T[u] = 0;

        if (l == r) return;

        int mid = (l+r)>>1;
        build (lson(u), l, mid);
        build (rson(u), mid+1, r);
        pushup(u);
    }

    void modify(int u, int l, int r, int v) {
        if (l <= lc[u] && rc[u] <= r) {
            maintain(u, v);
            return;
        }

        pushdown(u);
        int mid = (lc[u] + rc[u]) >> 1;
        if (l <= mid) modify(lson(u), l, r, v);
        if (r > mid) modify(rson(u), l, r, v);
        pushup(u);
    }

    ll query(int u, int l, int r) {
        if (l <= lc[u] && rc[u] <= r)
            return S[u];

        pushdown(u);
        int mid = (lc[u] + rc[u]) >> 1;
        ll ret = 0;
        if (l <= mid) ret += query(lson(u), l, r);
        if (r > mid) ret += query(rson(u), l, r);
        pushup(u);
        return ret;
    }

    ll queryLeft(int u, int l, int r) {
        if (l <= lc[u] && rc[u] <= r)
            return L[u] + S[u] * (lc[u] - l);

        pushdown(u);
        int mid = (lc[u] + rc[u]) >> 1;
        ll ret = 0;
        if (l <= mid) ret += queryLeft(lson(u), l, r);
        if (r > mid) ret += queryLeft(rson(u), l, r);
        pushup(u);
        return ret;
    }

    ll queryRight(int u, int l, int r) {
        if (l <= lc[u] && rc[u] <= r)
            return R[u] + S[u] * (r - rc[u]);

        pushdown(u);
        int mid = (lc[u] + rc[u]) >> 1;
        ll ret = 0;
        if (l <= mid) ret += queryRight(lson(u), l, r);
        if (r > mid) ret += queryRight(rson(u), l, r);
        pushup(u);
        return ret;
    }
}A, D;

int N, M;

int main () {
    int cas;
    scanf("%d", &cas);
    for (int kcas = 1; kcas <= cas; kcas++) {
        scanf("%d%d", &N, &M);
        A.build(1, 2, 2 * N);
        D.build(1, 1, 2 * N - 1);
//      A.build(1, 1, 2 * N);
//      D.build(1, 1, 2 * N);

        printf("Case #%d:\n", kcas);

        int t, l, r, x1, y1, x2, y2;
        while (M--) {
            scanf("%d", &t);
            if (t == 1) {
                scanf("%d%d", &l, &r);
                A.modify(1, l, r, 1);
            } else if (t == 2) {
                scanf("%d%d", &l, &r);
                D.modify(1, l + N, r + N, 1);
            } else {
                scanf("%d%d%d%d", &x1, &x2, &y1, &y2);
                ll ans = 0, t = min(x2-x1, y2-y1) + 1;;

                l = x2 + y1, r = x1 + y2;
                if (l > r) swap(l, r);
                ans += A.query(1, l, r) * t;
                ans += A.queryLeft(1, x1+y1, l-1);
                ans += A.queryRight(1, r+1, x2+y2);

                l = x1-y1+N, r = x2-y2+N;
                if (l > r) swap(l, r);
                ans += D.query(1, l, r) * t;
                ans += D.queryLeft(1, x1-y2+N, l-1);
                ans += D.queryRight(1, r+1, x2-y1+N);
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
