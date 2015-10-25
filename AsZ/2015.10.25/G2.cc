#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define ALL(a) (a).begin(), (a).end()

using namespace std;

const int N = 2e5 + 5;

struct Node{
    int l, r, cnt;
    LL sum;
}t[N * 20];

vector<int> num;
int node, head[N];

int NewNode() {
    t[node].l = t[node].r = t[node].cnt = t[node].sum = 0;
    return node++;
}

void update(int &now, int pre, int l, int r, int x) {
    now = NewNode();
    if (l == r) {
        t[now].cnt = t[pre].cnt + 1;
        t[now].sum = t[pre].sum + num[x];
        //cout << l << ' ' << r << ' ' << num[x] << endl;
        return ;
    }
    else {
        int mid = (l + r) >> 1;
        if (x <= mid) {
            update(t[now].l, t[pre].l, l, mid, x);
            t[now].r = t[pre].r;
        }
        else {
            update(t[now].r, t[pre].r, mid + 1, r, x);
            t[now].l = t[pre].l;
        }
        t[now].cnt = t[t[now].l].cnt + t[t[now].r].cnt;
        t[now].sum = t[t[now].l].sum + t[t[now].r].sum;
    }
}

pair<int, LL> operator + (const pair<int, LL> &a, const pair<int, LL> &b) {
    return {a.first + b.first, a.second + b.second};
}

pair<int, LL> query(int now, int l, int r, int x, int y) {
    if (x <= l && y >= r) {
        return {t[now].cnt, t[now].sum};
    }
    else {
        int mid = (l + r) >> 1;
        pair<int, LL> a = {0, 0}, b = {0, 0};
        if (x <= mid) a = query(t[now].l, l, mid, x, y);
        if (y > mid) b = query(t[now].r, mid + 1, r, x, y);
        return a + b;
    }
}

int a[N], d[N], r[N];

int main() {
#ifdef HOME
    freopen("G.in", "r", stdin);
#endif
    head[0] = NewNode();
    num.push_back(-1);

    int n, m;
    scanf("%d%d", &n, &m);
    REPP(i, 1, m) {
        scanf("%d", a + i);
        num.push_back(a[i]);
    }
    sort(ALL(num));
    num.resize(unique(ALL(num)) - num.begin());
    int tot = num.size() - 1;
    //cout << tot << endl;
    //for (auto &x: num) {
    //    cout << x << ' ';
    //}
    //cout << endl;
    REPP(i, 1, m) {
        int pos = lower_bound(ALL(num), a[i]) - num.begin();
        update(head[i], head[i - 1], 1, tot, pos);
    }
    //REPP(i, 1, 10) {
    //    cout << i << ' ' << t[i].l << ' ' << t[i].r << ' ' << t[i].cnt << ' ' << t[i].sum << endl;
    //}
    //REPP(j, 1, m) {
    //    cout << t[head[j]].cnt << ' ' << t[head[j]].sum << endl;
    //}
    REPP(i, 1, n) {
        scanf("%d%d", d + i, r + i);
    }
    REPP(i, 1, n) {
        int lo = 0, hi = m + 1;
        int pos = lower_bound(ALL(num), d[i]) - num.begin();
        //cout << pos << "hehe" << ' ' << i << endl;
        while (lo + 1 < hi) {
            int mid = (lo + hi) >> 1;
            int cnt = 0;
            LL sum = 0;
            tie(cnt, sum) = query(head[mid], 1, tot, pos, tot);
            //cout << "cnt, sum: " << cnt << ' ' << sum << endl;
            if (sum - 1LL * cnt * d[i] >= r[i]) hi = mid;
            else lo = mid;
        }
        if (hi == m + 1) hi = 0;
        printf("%d%c", hi, " \n"[i == n]);
        //REPP(j, 1, m) {
        //    cout << t[head[j]].cnt << ' ' << t[head[j]].sum << endl;
        //}
    }

    return 0;
}

