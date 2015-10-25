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

const int N = 2e5 + 5;

pair<int, int> p[N];
int ans[N], t[N], tmp[N];
LL sum[N << 2], flag[N << 2];

bool cmp(int i, int j) {
    return p[i].first < p[j].first;
}

int ql, qr, qd;

void build(int x, int l, int r) {
    if (l == r) sum[x] = t[l], flag[x] = 0;
    else {
        build(LC), build(RC);
        sum[x] = sum[L] + sum[R];
        flag[x] = 0;
    }
}

void push(int x, int l, int r) {
    flag[L] += flag[x], flag[R] += flag[x];
    sum[L] -= 1LL * (MID - l + 1) * flag[x], sum[R] -= 1LL * (r - MID) * flag[x];
    flag[x] = 0;
}

void update(int x, int l, int r) {
    if (ql <= l && qr >= r) {
        flag[x] += qd;
        sum[x] -= 1LL * (r - l + 1) * qd;
    }
    else {
        if (flag[x]) push(x, l, r);
        if (ql <= MID) update(LC);
        if (qr > MID) update(RC);
        sum[x] = sum[L] + sum[R];
    }
}

int query(int x, int l, int r, int num) {
    if (l == r) return l;
    else {
        if (flag[x]) push(x, l, r);
        if (sum[L] >= num) return query(LC, num);
        else {
            num -= sum[L];
            return query(RC, num);
        }
    }
}

int main() {
#ifdef HOME
    freopen("G.in", "r", stdin);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    REPP(i, 1, m) {
        scanf("%d", t + i);
    }
    build(1, 1, m);
    REPP(i, 1, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        p[i] = {x, y};
    }
    REPP(i, 1, n) tmp[i] = i;
    sort(tmp + 1, tmp + n + 1, cmp);
    int pre = 0;
    REPP(ii, 1, n) {
        int i = tmp[ii];
        if (ii == 1) {
            qd = p[i].first;
        }
        else {
            qd = p[i].first - p[pre].first;
        }
        pre = i, ql = 1, qr = m;
        update(1, 1, m);
        //cout << sum[1] << ' ' << p[i].second << endl;
        if (sum[1] < p[i].second) ans[i] = 0;
        else ans[i] = query(1, 1, m, p[i].second);
    }
    REPP(i, 1, n) {
        printf("%d%c", ans[i], " \n"[i == n]);
    }

    return 0;
}


