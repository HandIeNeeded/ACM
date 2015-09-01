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

const LL INF = 1LL << 60;
const int N = 2e5 + 5;
LL mi[N << 2], id[N << 2], dp[N], flag[N << 2];
int a[N], b[N], cost[N];
int n;

void maintain(int x, int l, int r) {
    if (mi[L] < 0) mi[x] = mi[R], id[x] = id[R];
    else if (mi[R] < 0) mi[x] = mi[L], id[x] = id[L];
    else {
        if (mi[L] < mi[R]) mi[x] = mi[L], id[x] = id[L];
        else mi[x] = mi[R], id[x] = id[R];
    }
    flag[x] = flag[L] == flag[R] ? flag[L] : 0;
}

void build(int x, int l, int r) {
    if (l == r) {
        mi[x] = dp[l] = INF;
        flag[x] = 0;
        id[x] = l;
    }
    else {
        build(LC), build(RC);
        maintain(x, l, r);
    }
}

int ql, qr, qx;
LL qd;

void push(int x, int l, int r) {
    if (flag[L] > 0) flag[L] = min(flag[L], flag[x]);
    else if (flag[L] == 0) {
        flag[L] = flag[x];
    }
    if (flag[R] > 0) flag[R] = min(flag[R], flag[x]);
    else if (flag[R] == 0) {
        flag[R] = flag[x];
    }
    mi[L] = min(mi[L], flag[x]);
    mi[R] = min(mi[R], flag[x]);
    id[L] = l, id[R] = r;
    flag[x] = 0;
}

void modify(int x, int l, int r) {
    if (l == r) {
        flag[x] = mi[x] = qd;
        id[x] = l;
        cout << x << ' ' << l << ' ' << r << ' ' << mi[x] << endl;
    }
    else {
        if (flag[x]) push(x, l, r);
        if (qx <= MID) modify(LC);
        else modify(RC);
        maintain(x, l, r);
    }
}

void update(int x, int l, int r) {
    if (l == r) {
        if (flag[x] >= 0) {
            flag[x] = mi[x] = min(mi[x], 1LL * qd);
            id[x] = l;
        }
        return ;
    }
    if (ql <= l && qr >= r) {
        cout << "update: " << l << ' ' << r << ' ' << qd << endl;
        cout << mi[x] << ' ' << flag[x] << endl;
        if (mi[x] > qd) {
            flag[x] = mi[x] = qd;
            if (flag[L] < 0) id[x] = id[R];
            else id[x] = id[L];
        }
        else if (flag[x]) {
            flag[x] = mi[x] = min(flag[x], qd);
            id[x] = l;
        }
        else {
            update(LC), update(RC);
            maintain(x, l, r);
        }
    }
    else {
        if (flag[x]) push(x, l, r);
        if (ql <= MID) update(LC);
        if (qr > MID) update(RC);
        maintain(x, l, r);
    }
}

pair<LL, LL> query(int x, int l, int r) {
    if (ql <= l && qr >= r) {
        return {mi[x], id[x]};
    }
    else {
        if (flag[x]) push(x, l, r);
        if (qr <= MID) return query(LC);
        if (ql > MID) return query(RC);
        pair<LL, LL> a = query(LC), b = query(RC);
        if (a.first < 0) return b;
        if (b.first < 0) return a;
        if (a.first > b.first) return b;
        else return a;
    }
}

void dijkstra() {
    build(1, 1, n);
    ql = 1, qr = n;
    dp[1] = 0;
    qx = 1, qd = 0;
    modify(1, 1, n);
    int cnt = n;
    while (cnt) {
        int x;
        ql = 1, qr = n;
        pair<LL, LL> tmp = query(1, 1, n);
        x = tmp.second;
        dp[x] = tmp.first;
        cout << "x dp: " << x << ' ' << dp[x] << endl;
        ql = max(1, x - b[x]), qr = max(0, x - a[x]);
        cout << "ql qr: " << ql << ' ' << qr << endl;
        if (ql <= qr) {
            qd = dp[x] + cost[x];
            update(1, 1, n);
        }
        ql = min(x + a[x], n + 1), qr = min(n, x + b[x]);
        cout << "ql qr: " << ql << ' ' << qr << endl;
        if (ql <= qr) {
            qd = dp[x] + cost[x];
            update(1, 1, n);
        }
        qx = x, qd = -1;
        modify(1, 1, n);
        cnt--;
    }
}

int main() {
#ifdef HOME
    freopen("I.in", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
#define lld I64d
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        REPP(i, 1, n) scanf("%d", a + i);
        REPP(i, 1, n) scanf("%d", b + i);
        REPP(i, 1, n) scanf("%d", cost + i);
        dijkstra();
        REPP(i, 1, n) {
            if (dp[i] == INF) dp[i] = -1;
            printf("%lld%c", dp[i], " \n"[i == n]);
        }
    }
    return 0;
}
