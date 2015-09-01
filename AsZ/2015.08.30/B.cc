#include <bits/stdc++.h>

#define Long long long
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
int ql, qr, qd;
int a[N];
Long sum[N << 2], flag[N << 2];

void build(int x, int l, int r) {
    if (l == r) {
        sum[x] = flag[x] = 0;
    }
    else {
        build(LC), build(RC);
        sum[x] = flag[x] = 0;
    }
}

void push(int x, int l, int r) {
    sum[L] += 1LL * flag[x] * (MID - l + 1);
    sum[R] += 1LL * flag[x] * (r - MID);
    flag[L] += flag[x], flag[R] += flag[x];
    flag[x] = 0;
}

void update(int x, int l, int r) {
    if (ql <= l && qr >= r) {
        sum[x] += 1LL * (r - l + 1) * qd;
        flag[x] += qd;
    }
    else {
        if (flag[x]) push(x, l, r);
        if (ql <= MID) update(LC);
        if (qr > MID) update(RC);
        sum[x] = sum[L] + sum[R];
    }
}

Long query(int x, int l, int r) {
    if (ql <= l && qr >= r) {
        return sum[x];
    }
    else {
        if (flag[x]) push(x, l, r);
        Long ans = 0;
        if (ql <= MID) ans += query(LC);
        if (qr > MID) ans += query(RC);
        return ans;
    }
}

void unique(deque<pair<int, int> > &a) {
    deque<pair<int, int> > tmp;
    REP(i, a.size()) {
        if (i == 0) tmp.push_back(a[i]);
        else if (a[i].first == a[i - 1].first) {
            tmp.back().second = a[i].second;
        }
        else {
            tmp.push_back(a[i]);
        }
    }
    a = tmp;
}

int LL[N], RR[N]; 
int tmp[N];
Long ans[N];

bool cmp(int i, int j) {
    return RR[i] < RR[j];
}

int main() {
#ifdef HOME
    freopen("B.in", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
#define lld I64d
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        REPP(i, 1, n) scanf("%d", a + i);
        deque<pair<int, int> > g;
        int m;
        scanf("%d", &m);
        REPP(i, 1, m) tmp[i] = i;
        REPP(i, 1, m) {
            scanf("%d%d", LL + i, RR + i);
        }
        sort(tmp + 1, tmp + m + 1, cmp);
        int now = 1;
        build(1, 1, n);
        REPP(i, 1, n) {
            g.push_front({a[i], i});
            for (auto &p: g) {
                p = {__gcd(p.first, a[i]), p.second};
            }
            unique(g);
            //for (auto &p: g) {
            //    cout << p.first << ' ' << p.second << endl;
            //}
            //cout << "**********" << endl;
            int pre = i;
            REP(i, g.size()) {
                ql = g[i].second, qr = pre, qd = g[i].first;
                update(1, 1, n);
                pre = g[i].second - 1;
            }
            while (now <= m && RR[tmp[now]] == i) {
                ql = LL[tmp[now]], qr = RR[tmp[now]];
                ans[tmp[now]] = query(1, 1, n);
                now++;
            }
        }
        REPP(i, 1, m) {
            printf("%lld\n", ans[i]);
        }
    }

    return 0;
}

