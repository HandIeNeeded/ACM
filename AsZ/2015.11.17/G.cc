#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 3e5 + 5;
char s[N];

int flag[N << 2], mx[N << 2], cnt[N << 2], a[N];

void maintain(int x, int l, int r) {
    mx[x] = min(mx[L], mx[R]);
}

void build(int x, int l, int r) {
    if (l == r) {
        mx[x] = a[l];
        cnt[x] = s[l] == ')' ? 1 : 0;
        flag[x] = 0;
    }
    else {
        build(LC), build(RC);
        maintain(x, l, r);
        cnt[x] = cnt[L] + cnt[R];
        flag[x] = 0;
    }
}

int qx, qd, ql, qr;

void push(int x, int l, int r) {
    mx[L] += flag[x], mx[R] += flag[x];
    flag[L] += flag[x], flag[R] += flag[x];
    flag[x] = 0;
}

void modify(int x, int l, int r) {
    if (l == r) {
        cnt[x] += qd;
    }
    else {
        if (qx <= MID) modify(LC);
        else modify(RC);
        cnt[x] = cnt[L] + cnt[R];
    }
}

void update(int x, int l, int r) {
    if (ql <= l && qr >= r) {
        mx[x] += qd;
        flag[x] += qd;
    }
    else {
        if (flag[x]) push(x, l, r);
        if (ql <= MID) update(LC);
        if (qr > MID) update(RC);
        maintain(x, l, r);
    }
}

int Query(int x, int l, int r) {
    if (l == r) return l;
    else {
        if (cnt[L]) {
            return Query(LC);
        }
        else return Query(RC);
    }
}

int query(int x, int l, int r) {
    if (l == r) {
        return l;
    }
    else {
        if (flag[x]) push(x, l, r);
        if (mx[R] >= 2) {
            return query(LC);
        }
        else return query(RC);
    }
}

int main() {
#ifdef HOME
    freopen("G.in", "r", stdin);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);

    REPP(i, 1, n) a[i] = a[i - 1] + (s[i] == '(' ? 1 : -1);
    build(1, 1, n);
    while (m--) {
        int x;
        scanf("%d", &x);
        qx = x, qd = s[x] == '(' ? 1 : -1;
        modify(1, 1, n);
        if (s[x] == '(') {
            s[x] = ')';
            qd = -2;
            ql = qx, qr = n;
            update(1, 1, n);
            qx = Query(1, 1, n);
            qd = -1;
            modify(1, 1, n);
            s[qx] = '(';
            ql = qx, qr = n;
            qd = 2;
            update(1, 1, n);
        }
        else {
            s[x] = '(';
            qd = 2;
            ql = qx, qr = n;
            update(1, 1, n);
            qx = query(1, 1, n) + 1;
            qd = 1;
            modify(1, 1, n);
            s[qx] = ')';
            ql = qx, qr = n;
            qd = -2;
            update(1, 1, n);
        }
        printf("%d\n", qx);
        //cout << s + 1 << endl;
    }
    return 0;
}
