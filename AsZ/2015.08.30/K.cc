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

const int N = 2e5 + 5;
const int LOG = 18;
const int L = 31;
const int C = 2;

int tr[N * L][C], node;
vector<int> edge[N];
int ql[N], qr[N], pos[N], inv[N], a[N], now;

struct Query{
    int type, x, y, id;
};

int Node() {
    MST(tr[node], 0), cnt[node] = 0;
    return node++;
}

void insert(int x, int rt) {
    int now = 1 << 30, u = rt;
    REP(i, 31) {
        int c = (now & x) > 0;
        if (!tr[u][c]) tr[u][c] = Node();
        u = tr[u][c];
        now >>= 1;
    }
}

void dfs(int x) {
    pos[x] = ++now, inv[now] = x;
    ql[x] = now;
    for (auto &y: edge[x]) {
        dfs(y);
    }
    qr[x] = now;
}

vector<pair<int, int> > segment[LOG];
vector<Query> query[LOG];

void getSegment(int now, int l, int r) {
    segment[now].push_back({l, r});
    if (l != r) {
        getSegment(now + 1, l, MID);
        getSegment(now + 1, MID + 1, r);
    }
}

int type, id;

void split(int now, int ql, int qr, int l, int r) {
    if (ql <= l && qr >= r) {
        query[now].push_back((Query) {type, l, r, id});
    }
    else {
        if (ql <= MID) split(now + 1, ql, qr, l, MID);
        if (qr > MID) split(now + 1, ql, qr, MID + 1, r);
    }
}

int mp[N], rt[N];

void solve() {
    REP(i, LOG) {
        node = 0;
        REP(j, segment[i].size()) mp[segment[i][j].first] = j, rt[j] = Node();

    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        now = 0; // dfs
        REPP(i, 1, n) edge[i].clear();
        REP(i, LOG) segment.clear();
        getSegment();
        REPP(i, 1, n - 1) {
            int x;
            scanf("%d", &x);
            edge[x].push_back(i + 1);
        }
        dfs(1);
        REPP(i, 1, n) scanf("%d", a + i);
        int type, x, y;
        REPP(i, 1, m) {
            scanf("%d%d", &type, &x);
            if (type == 0) {
                scanf("%d", &y);
                split(0, 
            }
            else {

            }
        }
        REPP(i, 1, m) {
            if (q[i].type) {
                printf("%d\n", q[i].y);
            }
        }
    }
    return 0;
}

