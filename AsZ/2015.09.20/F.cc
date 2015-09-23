#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;

struct Node{
    int l, r, cnt, mx;
}p[N * 20];

int now, node, head[N << 1], clk, version[N], n, m;
vector<int> edge[2][N];
int dep[2][N], pos[N], size[N], son[N], top[N], pre[N], inv[N];

int newNode() {
    p[node].l = p[node].r = p[node].cnt = p[node].mx = 0;
    return node++;
}

void update(int &x, int pre, int l, int r, int num, int d) {
    x = newNode();
    if (l == r) {
        p[x].cnt = p[pre].cnt + d;
        p[x].mx = p[x].cnt ? inv[l] : 0;
        return ;
    }
    int mid = (l + r) >> 1;
    if (num <= mid) {
        update(p[x].l, p[pre].l, l, mid, num, d);
        p[x].r = p[pre].r;
    }
    else {
        update(p[x].r, p[pre].r, mid + 1, r, num, d);
        p[x].l = p[pre].l;
    }
    p[x].cnt = p[p[x].l].cnt + p[p[x].r].cnt;
    p[x].mx = max(p[p[x].l].mx, p[p[x].r].mx);
}

int query(int x, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) {
        return p[x].mx;
    }
    else {
        int mid = (l + r) >> 1;
        int a = 0, b = 0;
        if (ql <= mid) a = query(p[x].l, l, mid, ql, qr);
        if (qr > mid) b = query(p[x].r, mid + 1, r, ql, qr);
        return max(a, b);
    }
}

void dfsA(int x, int p = 0) {
    dep[0][x] = dep[0][p] + 1;
    ++clk;
    update(head[clk], head[clk - 1], 1, n, pos[x], 1);
    version[x] = clk;
    for (auto &y: edge[0][x]) {
        if (y != p) {
            dfsA(y, x);
        }
    }
    ++clk;
    update(head[clk], head[clk - 1], 1, n, pos[x], -1);
}

void getNext(int &x, int y) {
    x += y;
    if (x >= n) x -= n;
    x++;
}

void dfs(int x, int p = 0) {
    dep[1][x] = dep[1][p] + 1;
    pre[x] = p;
    size[x] = 1, son[x] = 0;
    for (auto &y: edge[1][x]) {
        if (y != p) {
            dfs(y, x);
            size[x] += size[y];
            if (size[y] > size[son[x]]) {
                son[x] = y;
            }
        }
    }
}

void divide(int x, int tp) {
    pos[x] = ++now, top[x] = tp;
    inv[now] = x;
    if (son[x]) divide(son[x], tp);
    for (auto &y: edge[1][x]) {
        if (y != pre[x] && y != son[x]) {
            divide(y, y);
        }
    }
}

int query(int a, int b, int version) {
    int ans = 0;
    while (top[a] != top[b]) {
        if (dep[1][top[a]] < dep[1][top[b]]) {
            swap(a, b);
        }
        ans = max(ans, query(head[version], 1, n, pos[top[a]], pos[a]));
        a = pre[top[a]];
    }
    if (dep[1][a] < dep[1][b]) {
        swap(a, b);
    }
    ans = max(ans, query(head[version], 1, n, pos[b], pos[a]));
    return ans;
}

int getAns(int x, int y) {
    return query(1, y, version[x]);
}

int main() {
#ifdef HOME
    freopen("F.in", "r", stdin);
#endif
    while (scanf("%d%d", &n, &m) > 0) {
        REP(i, 2) REPP(j, 1, n) edge[i][j].clear();
        REP(j, 2) {
            REPP(i, 1, n - 1) {
                int x;
                scanf("%d", &x);
                edge[j][x].push_back(i + 1);
            }
        }
        now = 0, clk = 0, node = 0;
        newNode();
        dfs(1), divide(1, 1);
        dfsA(1);
        int pre = 0;
        while (m--) {
            int x, y;
            scanf("%d%d", &x, &y);
            getNext(x, pre), getNext(y, pre);
        //cout << "hehe" << ' ' << x << ' ' << y << endl;
            pre = getAns(x, y);
            printf("%d %d %d\n", pre, dep[0][x] - dep[0][pre] + 1, dep[1][y] - dep[1][pre] + 1);
        }
    }
    return 0;
}
