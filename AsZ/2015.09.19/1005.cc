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

const int N = 4e5 + 5;

struct Unit{
    int cnt, flag;
    LL sum, prefix, suffix;
}t[2][N << 2];

Unit operator + (const Unit &a, const Unit &b) {
    Unit res;
    res.cnt = a.cnt + b.cnt;
    res.flag = 0, res.sum = a.sum + b.sum;
    res.prefix = a.prefix + a.cnt * b.sum + b.prefix;
    res.suffix = a.suffix + b.cnt * a.sum + b.suffix;
    return res;
}

int ql, qr;

void build(int x, int l, int r) {
    if (l == r) {
        REP(i, 2) t[i][x] = (Unit) {1, 0, 0, 0, 0};
    }
    else {
        build(LC), build(RC);
        REP(i, 2) t[i][x] = (Unit) {r - l + 1, 0, 0, 0, 0};
    }
}

void push(int x, int l, int r, int id) {
    t[id][L].flag += t[id][x].flag, t[id][R].flag += t[id][x].flag;
    t[id][L].sum += 1LL * t[id][L].cnt * t[id][x].flag;
    t[id][R].sum += 1LL * t[id][R].cnt * t[id][x].flag;
    LL A = 1LL * t[id][L].cnt * (t[id][L].cnt + 1) / 2;
    LL B = 1LL * t[id][R].cnt * (t[id][R].cnt + 1) / 2;
    t[id][L].prefix += A * t[id][x].flag;
    t[id][R].prefix += B * t[id][x].flag;
    t[id][L].suffix += A * t[id][x].flag;
    t[id][R].suffix += B * t[id][x].flag;
    t[id][x].flag = 0;
}

void update(int x, int l, int r, int id) {
    if (ql <= l && qr >= r) {
        t[id][x].flag += 1;
        t[id][x].sum += t[id][x].cnt;
        t[id][x].prefix += 1LL * t[id][x].cnt * (t[id][x].cnt + 1) / 2;
        t[id][x].suffix += 1LL * t[id][x].cnt * (t[id][x].cnt + 1) / 2;
    }
    else {
        if (t[id][x].flag) push(x, l, r, id);
        if (ql <= MID) update(LC, id);
        if (qr > MID) update(RC, id);
        t[id][x] = t[id][L] + t[id][R];
    }
}

Unit query(int x, int l, int r, int id) {
    if (ql <= l && qr >= r) {
        return t[id][x];
    }
    else {
        if (t[id][x].flag) push(x, l, r, id);
        if (ql > MID) return query(RC, id);
        if (qr <= MID) return query(LC, id);
        return query(LC, id) + query(RC, id);
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        printf("Case #%d:\n", ca++);
        int tot = n << 1;
        build(1, 1, tot);
        while (m--) {
            int type, l, r;
            scanf("%d", &type);
            if (type <= 2) {
                scanf("%d%d", &l, &r);
                if (type == 1) {
                    ql = l, qr = r;
                    update(1, 1, tot, 0);
                }
                else {
                    ql = n + 1 + l, qr = n + 1 + r;
                    update(1, 1, tot, 1);
                }
            }
            else {
                int x1, x2, y1, y2;
                scanf("%d%d%d%d", &x1, &x2, &y1, &y2);
                int H = x2 - x1, W = y2 - y1;
                LL ans = 0;
                if (H >= W) {
                    //left
                    ql = x1 + y1, qr = x1 + y2 - 1;
                    if (ql <= qr) {
                        ans += query(1, 1, tot, 0).prefix;
                    }
                    ql = x2 + y1 + 1, qr = x2 + y2;
                    if (ql <= qr) {
                        ans += query(1, 1, tot, 0).suffix;
                    }
                    ql = x1 + y2, qr = x2 + y1;
                    if (ql <= qr) {
                        ans += query(1, 1, tot, 0).sum * (W + 1);
                    }

                    //right
                    y1 = n + 1 - y1, y2 = n + 1 - y2;
                    swap(y1, y2);
                    ql = x1 + y1, qr = x1 + y2 - 1;
                    if (ql <= qr) {
                        ans += query(1, 1, tot, 1).prefix;
                    }
                    ql = x2 + y1 + 1, qr = x2 + y2;
                    if (ql <= qr) {
                        ans += query(1, 1, tot, 1).suffix;
                    }
                    ql = x1 + y2, qr = x2 + y1;
                    if (ql <= qr) {
                        ans += query(1, 1, tot, 1).sum * (W + 1);
                    }
                }
                else {
                    //left
                    ql = x1 + y1, qr = x2 + y1 - 1;
                    if (ql <= qr) {
                        ans += query(1, 1, tot, 0).prefix;
                    }
                    ql = x1 + y2 + 1, qr = x2 + y2;
                    if (ql <= qr) {
                        ans += query(1, 1, tot, 0).suffix;
                    }
                    ql = x2 + y1, qr = x1 + y2;
                    if (ql <= qr) {
                        ans += query(1, 1, tot, 0).sum * (H + 1);
                    }

                    //right
                    y1 = n + 1 - y1, y2 = n + 1 - y2;
                    swap(y1, y2);
                    ql = x1 + y1, qr = x2 + y1 - 1;
                    if (ql <= qr) {
                        ans += query(1, 1, tot, 1).prefix;
                    }
                    ql = x1 + y2 + 1, qr = x2 + y2;
                    if (ql <= qr) {
                        ans += query(1, 1, tot, 1).suffix;
                    }
                    ql = x2 + y1, qr = x1 + y2;
                    if (ql <= qr) {
                        ans += query(1, 1, tot, 1).sum * (H + 1);
                    }
                }
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
