#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memSet(a, b, sizeof(a))

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
    LL res[2][2];
    LL ans;

    void print() {
        REP(i, 2) {
            REP(j, 2) {
                cout << res[i][j] << ' ';
            }
            cout << endl;
        }
        cout << "ans: " << ans << endl;
    }
}p[N << 2];

void update(Unit &a, Unit b) {
    REP(i, 2) {
        REP(j, 2) {
            a.res[i][j] = max(a.res[i][j], b.res[i][j]);
        }
    }
    a.ans = max(a.ans, b.ans);
}

Unit operator + (const Unit &a, const Unit &b) {
    Unit ans;
    REP(i, 2) REP(j, 2) ans.res[i][j] = -(1LL << 60);
    REP(i, 2) {
        REP(j, 2) {
            REP(k, 2) {
                ans.res[i][k] = max(ans.res[i][k], a.res[i][j] + b.res[j ^ 1][k]);
            }
        }
    }
    update(ans, a);
    update(ans, b);
    ans.ans = -(1LL << 60);
    REP(i, 2) {
        REP(j, 2) {
            ans.ans = max(ans.ans, ans.res[i][j]);
        }
    }
    return ans;
}

void Set(Unit &ans, int pos, int qx) {
    REP(i, 2) {
        REP(j, 2) {
            ans.res[i][j] = -(1LL << 60);
        }
    }
    if (pos & 1) {
        ans.res[1][1] = qx;
    }
    else {
        ans.res[0][0] = qx;
    }
    ans.ans = qx;
}

void build(int x, int l, int r) {
    if (l == r) {
        Set(p[x], l, num[l]);
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
        Set(p[x], l, qd);
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
        //p[1].print();
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
