#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r
#define ALL(a) (a).begin(), (a).end()

using namespace std;

const int N = 2e5 + 5;

int val[N], cnt[N], prefix[N];
int W, H, n;
vector<int> num;
pair<int, int> p[N];

bool cmpy(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int flag[N << 2], mx[N << 2];

void merge(int x, int l, int r) {
    if (flag[x]) mx[x] = 0;
    else {
        if (l == r) mx[x] = val[l];
        else mx[x] = max(mx[L], mx[R]);
    }
}

int ql, qr, qd, tot;

void build(int x, int l, int r) {
    if (l == r) {
        mx[x] = val[l], flag[x] = 0;
    }
    else {
        build(LC), build(RC);
        flag[x] = 0;
        merge(x, l, r);
    }
}

void update(int x, int l, int r) {
    if (ql <= l && qr >= r) {
        flag[x] += qd;
        if (flag[x] == 0) {
            merge(x, l, r);
        }
        else {
            mx[x] = 0;
        }
    }
    else {
        if (ql <= MID) update(LC);
        if (qr > MID) update(RC);
        if (flag[x] == 0) {
            merge(x, l, r);
        }
        else {
            mx[x] = 0;
        }
    }
}

void add(int x) {
    ql = num[p[x].first - 1];
    ql = lower_bound(ALL(num), ql - W + 1) - num.begin() + 1;
    qr = p[x].first;
    qd = 1;
    update(1, 1, tot);
}

void erase(int x) {
    ql = num[p[x].first - 1];
    ql = lower_bound(ALL(num), ql - W + 1) - num.begin() + 1;
    qr = p[x].first;
    qd = -1;
    update(1, 1, tot);
}

int main() {
#ifdef HOME
    freopen("tmp.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int x, y;
        num.clear();
        scanf("%d%d%d", &n, &W, &H);
        REPP(i, 1, n) {
            scanf("%d%d", &x, &y);
            p[i] = {x, y};
            num.push_back(x);
            num.push_back(x - W);
        }
        sort(ALL(num));
        num.resize(unique(ALL(num)) - num.begin());
        tot = num.size();
        REPP(i, 1, tot) cnt[i] = 0;
        REPP(i, 1, n) {
            int x, y;
            tie(x, y) = p[i];
            x = lower_bound(ALL(num), x) - num.begin() + 1;
            p[i] = {x, y};
            cnt[x]++;
        }
        REPP(i, 1, tot) prefix[i] = prefix[i - 1] + cnt[i];
        REPP(i, 1, tot) {
            int nextpos = num[i - 1] + W;
            int y = lower_bound(ALL(num), nextpos) - num.begin() + 1;
            val[i] = prefix[y - 1] - prefix[i - 1];
        }
        build(1, 1, tot);
        sort(p + 1, p + n + 1, cmpy);
        int ans = 0;
        vector<int> h;
        REPP(i, 1, n) {
            h.push_back(p[i].second);
            h.push_back(p[i].second + H);
        }
        sort(ALL(h));
        h.resize(unique(ALL(h)) - h.begin());
        int cnt = h.size();
        int now = 1, pos = 1;
        REP(i, cnt) {
            while (now <= n) {
                int y0 = h[i], y1 = p[now].second;
                if (y0 - y1 >= H) {
                    erase(now);
                    now++;
                }
                else {
                    break;
                }
            }
            int height = h[i];
            while (pos <= n && p[pos].second == height) {
                add(pos);
                pos++;
            }
            ans = max(ans, mx[1] + pos - now);
        }
        printf("Case #%d: %d\n", ca++, ans);
    }
    return 0;
}
