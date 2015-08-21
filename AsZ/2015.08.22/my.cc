#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 1e5 + 5;
int qx, qd, ql, qr;
int num[N];

struct Unit{
    int l, r, la, ra; //range length
    LL lsum, lmax; //prefix max
    LL rsum, rmax; //suffix max
    LL ans;

    void print() {
        cout << la << ' ' << lsum << ' ' << lmax << endl;
        cout << ra << ' ' << rsum << ' ' << rmax << endl;
        cout << ans << endl;
    }
}p[N << 2];

Unit operator + (const Unit &a, const Unit &b) {
    Unit ans;
    ans.l = a.l, ans.r = b.r;
    if (a.la == b.l - a.l && ((num[a.r] - num[b.l]) & 1)) {
        ans.la = a.la + b.la;
        ans.lsum = a.lsum + b.lsum;
        ans.lmax = max(a.lmax, a.lsum + b.lmax);
    }
    else {
        ans.la = a.la;
        ans.lsum = a.lsum;
        ans.lmax = a.lmax;
    }

    if (b.ra == b.r - a.r && ((num[a.r] - num[b.l]) & 1)) {
        ans.ra = a.ra + b.ra;
        ans.rsum = a.rsum + b.rsum;
        ans.rmax = max(b.rmax, b.rsum + a.rmax);
    }
    else {
        ans.ra = b.ra;
        ans.rsum = b.rsum;
        ans.rmax = b.rmax;
    }
    return ans;
}

void build(int x, int l, int r) {
    if (l == r) {
        p[x] = (Unit) {l, r, 1, 1, num[l], num[l], num[r], num[r], num[l]};
    }
    else {
        build(LC), build(RC);
        p[x] = p[L] + p[R];
    }
}

Unit query(int x, int l, int r) {
    if (ql <= l && qr >= r) {
        return p[x];
    }
    else {
        if (ql > MID) return query(RC);
        if (qr <= MID) return query(LC);
        return query(LC) + query(RC);
    }
}

void update(int x, int l, int r) {
    if (l == r) {
        p[x] = (Unit) {l, r, 1, 1, qd, qd, qd, qd, qd};
    }
    else {
        if (qx <= MID) update(LC);
        if (qx > MID) update(RC);
        p[x] = p[L] + p[R];
    }
}

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
#define lld I64d
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        REPP(i, 1, n) scanf("%d", num + i);
        build(1, 1, n);
        while (m--) {
            int type;
            scanf("%d%d%d", &type, &ql, &qr);
            if (type) {
                qx = ql, qd = qr;
                update(1, 1, n);
                num[qx] = qd;
            }
            else {
                printf("%lld\n", query(1, 1, n).ans);
            }
        }
    }

    return 0;
}
