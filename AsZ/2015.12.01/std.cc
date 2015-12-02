#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <tuple>
#include <cassert>
using namespace std;
typedef long long LL;

const int MAXN = 100010;
const int MAXL = 200010;
const int MAXT = 400010;

struct Node {
    int x, y;
    void read() {
        scanf("%d%d", &x, &y);
    }
} p[MAXN];

int val[MAXL];

vector<int> ytmp;

int T, n, w, h;

void inithash() {
    ytmp.clear();
    for(int i = 0; i < n; ++i) {
        ytmp.push_back(p[i].y - h + 1);
        ytmp.push_back(p[i].y + 1);
    }
    sort(ytmp.begin(), ytmp.end());
    ytmp.erase(unique(ytmp.begin(), ytmp.end()), ytmp.end());
}

int yhash(int y) {
    return lower_bound(ytmp.begin(), ytmp.end(), y) - ytmp.begin();
}

void initval() {
    memset(val, 0, ytmp.size() * sizeof(int));
    for(int i = 0; i < n; ++i) {
        val[yhash(p[i].y - h + 1)]++;
        val[yhash(p[i].y + 1)]--;
    }
    partial_sum(val, val + ytmp.size(), val);
}

int root(int l, int r) {
    return (l + r) | (l != r);
}
#define mid ((l + r) >> 1)
#define rt root(l, r)
#define ll root(l, mid)
#define rr root(mid + 1, r)
int ban[MAXT], maxt[MAXT];

void update(int l, int r) {
    if(!ban[rt]) maxt[rt] = (l == r ? val[l] : max(maxt[ll], maxt[rr]));
    else maxt[rt] = 0;
}

void build(int l, int r) {
    if(l == r) {
        maxt[rt] = val[l];
    } else {
        build(l, mid);
        build(mid + 1, r);
        update(l, r);
    }
}

void modify_ban(int l, int r, int a, int b, int val) {
    if(a <= l && r <= b) {
        ban[rt] += val;
    } else {
        if(a <= mid) modify_ban(l, mid, a, b, val);
        if(mid < b) modify_ban(mid + 1, r, a, b, val);
    }
    update(l, r);
}

int query() {
    return maxt[root(0, ytmp.size() - 1)];
}

vector<int> allx;
vector<tuple<int, int, int> > xtmp;
#define gpos(t) get<0>(t)
#define gval(t) get<1>(t)
#define gy(t) get<2>(t)

int solve() {
    xtmp.clear();
    for(int i = 0; i < n; ++i) {
        xtmp.push_back(make_tuple(p[i].x - w + 1, 1, p[i].y));
        xtmp.push_back(make_tuple(p[i].x + 1, -1, p[i].y));
    }
    sort(xtmp.begin(), xtmp.end());

    allx.clear();
    for(int i = 0; i < n; ++i) {
        allx.push_back(p[i].x - w + 1);
        allx.push_back(p[i].x + 1);
    }
    sort(allx.begin(), allx.end());
    allx.erase(unique(allx.begin(), allx.end()), allx.end());

    int res = query(), cnt = 0;
    size_t i = 0;
    for(int x : allx) {
        while(i < xtmp.size() && gpos(xtmp[i]) <= x) {
            auto t = xtmp[i++];
            modify_ban(0, ytmp.size() - 1, yhash(gy(t) - h + 1), yhash(gy(t) + 1) - 1, gval(t));
            cnt += gval(t);
        }
        res = max(res, query() + cnt);
    }
    return res;
}

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d%d%d", &n, &w, &h);
        assert(w > 0 && h > 0);
        for(int i = 0; i < n; ++i)
            p[i].read();
        inithash();
        initval();
        build(0, ytmp.size() - 1);
        printf("Case #%d: %d\n", t, solve());
    }
}
