#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define ALL(a) (a).begin(), (a).end()
#define PII pair<int, int>

using namespace std;

const int N = 22;
const int MO = 1e9 + 7;

struct Unit{
    int cnt, mx;
}mp[N][N];

struct rect{
    int a, b, c, d, v;

    void print() {
        cout << a << ' ' << b << ' '  << c << ' '  << d << ' ' << v << endl;
    }
}p[N];

vector<int> row, col;
vector<PII> use[N];
int r, c, n, m, h, w, tot;
bool vis[N][N];

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

void toMin(int &x, int y) {
    if (y < x) x = y;
}

void update(int id, int x, int y, int a, int b, int v) {
    int r = a - x, c = b - y;
    REP(i, r) {
        REP(j, c) {
            toMin(mp[x + i][y + j].mx, v);
            use[id].push_back({x + i, y + j});
            if (!vis[x + i][y + j]) tot += mp[x + i][y + j].cnt;
            vis[x + i][y + j] = 1;
        }
    }
}

int pow_mod(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = 1LL * ans * a % MO;
		b >>= 1;
		a = 1LL * a * a % MO;
	}
	return ans;
}

void modifyr(int &x) {
    x = lower_bound(ALL(row), x) - row.begin() + 1;
}

void modifyc(int &x) {
    x = lower_bound(ALL(col), x) - col.begin() + 1;
}

void modify(rect &x) {
    modifyr(x.a), modifyr(x.c);
    modifyc(x.b), modifyc(x.d);
}

int get() {
    int ans = 1;
    REPP(i, 1, r) {
        REPP(j, 1, c) if (vis[i][j]) {
            ans = 1LL * ans * pow_mod(mp[i][j].mx, mp[i][j].cnt);
        }
    }
    return ans;
}

int ans;

void dfs(int dep, int odd, int now) {
    if (dep == n) {
        if (odd) add(ans, MO - now);
        else add(ans, now);
        return ;
    }
    dfs(dep + 1, odd, now);
    vector<int> tmp;
    int flag = 0;
    for(auto &q: use[dep]) {
        int x, y;
        tie(x, y) = q;
        tmp.push_back(mp[x][y].mx);
        int cc = pow_mod(mp[x][y].mx, mp[x][y].cnt);
        now = 1LL * now * pow_mod(cc, MO - 2) % MO;
        toMin(mp[x][y].mx, p[dep].v - 1);
        if (mp[x][y].mx == 0) {
            flag = 1;
            continue;
        }
        now = 1LL * now * pow_mod(mp[x][y].mx, mp[x][y].cnt) % MO;
    }
    if (!flag) {
        dfs(dep + 1, odd ^ 1, now);
    }
    int id = 0;
    for (auto &q: use[dep]) {
        int x, y;
        tie(x, y) = q;
        mp[x][y].mx = tmp[id++];
    }
}

int main() {
#ifdef AsZ
    freopen("4.in", "r", stdin);
#endif

    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d", &h, &w, &m, &n);
        row.clear(), col.clear();
        row.push_back(1), row.push_back(h + 1);
        col.push_back(1), col.push_back(w + 1);
        REP(i, n) {
            int a, b, c, d, v;
            scanf("%d%d%d%d%d", &a, &b, &c, &d, &v);
            row.push_back(a), row.push_back(c + 1);
            col.push_back(b), col.push_back(d + 1);
            p[i] = (rect) {a, b, c + 1, d + 1, v};
        }
        sort(ALL(row)), sort(ALL(col));
        row.resize(unique(ALL(row)) - row.begin());
        col.resize(unique(ALL(col)) - col.begin());
        REP(i, n) {
            use[i].clear();
            modify(p[i]);
        }
        r = row.size() - 1, c = col.size() - 1;
        REPP(i, 1, r) {
            REPP(j, 1, c) {
                mp[i][j] = (Unit) {(row[i] - row[i - 1]) * (col[j] - col[j - 1]), m};
            }
        }
        tot = 0;
        REPP(i, 1, r) {
            REPP(j, 1, c) vis[i][j] = 0;
        }
        REP(i, n) {
            update(i, p[i].a, p[i].b, p[i].c, p[i].d, p[i].v);
        }
        ans = 0;
        int mul = pow_mod(m, h * w - tot);
        dfs(0, 0, get());
        ans = 1LL * ans * mul % MO;
        printf("Case #%d: %d\n", ca++, ans);
    }
    return 0;
}

