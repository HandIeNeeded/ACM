#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r
#define next hehe

using namespace std;

const int N = 1e5 + 5;
int pre[N], next[N];
int a[N], n;
int mx[N << 2], flag[N << 2];
LL m;

int top;
LL prefix[N];

void build(int x, int l, int r) {
    if (l == r) mx[x] = a[l] - top;
    else {
        build(LC), build(RC);
        mx[x] = max(mx[L], mx[R]);
    }
}

int ql, qr, qd;

void push(int x, int l, int r) {
    flag[L] += flag[x], flag[R] += flag[x];
    mx[L] += flag[x], mx[R] += flag[x];
    flag[x] = 0;
}

void update(int x, int l, int r) {
    if (ql <= l && qr >= r) {
        flag[x] += qd;
        mx[x] += qd;
    }
    else {
        if (flag[x]) push(x, l, r);
        if (ql <= MID) update(LC);
        if (qr > MID) update(RC);
        mx[x] = max(mx[L], mx[R]);
    }
}

LL querySum(int l, int r) {
    return prefix[r] - prefix[l - 1];
}

int queryL(int x, int l, int r) {
    if (l == r) {
        if (mx[x] >= 0) return l;
        else return 0;
    }
    else {
        if (flag[x]) push(x, l, r);
        int a = 0, b = 0;
        if (qr > MID) b = queryL(RC);
        if (ql <= MID) a = queryL(LC);
        if (b) return b;
        else return a;
    }
}

int queryR(int x, int l, int r) {
    if (l == r) {
        if (mx[x] >= 0) return l;
        else return n + 1;
    }
    else {
        if (flag[x]) push(x, l, r);
        int a = n + 1, b = n + 1;
        if (ql <= MID) a = queryR(LC);
        if (qr > MID) b = queryR(RC);
        if (a != n + 1) return a;
        return b;
    }
}

LL calc(int a, int b, int x) {
    return 1LL * (a + b) * x / 2;
}

LL get(int x, int l, int r) {
    //l -> x
    LL ans = 0;
    int cnt = x - l + 1;
    ans += calc(top, top - cnt + 1, cnt);
    cnt = r - x + 1;
    ans += calc(top, top - cnt + 1, cnt);
    ans -= top;
    return ans;
}

bool check(int x) {
    top = x;
    build(1, 1, n);
    REPP(i, 1, n) {
        ql = 1, qr = i - 1;
        if (ql <= qr) {
            qd = 1;
            update(1, 1, n);
        }
        ql = 1, qr = i;
        pre[i] = queryL(1, 1, n);
    }
    build(1, 1, n);
    for (int i = n; i >= 1; i--) {
        ql = i + 1, qr = n;
        if (ql <= qr) {
            qd = 1;
            update(1, 1, n);
        }
        ql = i, qr = n;
        next[i] = queryR(1, 1, n);
    }
    REPP(i, 1, n) {
        LL tmp = 0;
        if (pre[i] == 0) continue;
        if (next[i] == n + 1) continue;
        ql = pre[i] + 1, qr = next[i] - 1;
        if (ql <= qr) {
            tmp = get(i, ql, qr) - querySum(ql, qr);
        }
        if (tmp <= m) return 1;
    }
    return 0;
}

int main() {
    freopen("landscape.in", "r", stdin);
#ifndef HOME
    freopen("landscape.out", "w", stdout);
#endif

    scanf("%d%lld", &n, &m);
    int h = INT_MAX;
    REPP(i, 1, n) {
        scanf("%d", a + i);
        prefix[i] = prefix[i - 1] + a[i];
        h = min(h, a[i]);
    }
    int lo = h, hi = 3e5;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid)) lo = mid;
        else hi = mid;
    }
    printf("%d\n", lo);

    return 0;
}


