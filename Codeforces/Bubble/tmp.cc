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

const int N = 1e5 + 5;
const int M = 1e6 + 5;
const int MO = 1e9 + 7;

vector<int> edge[N], type[N];
int top[N], pos[N], pre[N], son[N], size[N], inv[N], dep[N], now;
int parent[N][18], pw[M];
int ql, qr, qx, n;

void dfs(int x, int p) {
	pre[x] = p, size[x] = 1, son[x] = 0;
	dep[x] = dep[p] + 1;
    parent[x][0] = p;
    REPP(i, 1, 17) parent[x][i] = parent[parent[x][i - 1]][i - 1];
    for (auto &y: edge[x]) {
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
	top[x] = tp, pos[x] = now, inv[now++] = x;
	if (son[x]) divide(son[x], tp);
    for (auto &y: edge[x]) {
		if (y != pre[x] && y != son[x]) {
			divide(y, y);
		}
	}
}

int goStep(int x, int step) {
    REP(i, 18) if (step & (1 << i)) {
        x = parent[x][i];
    }
    return x;
}

int getLca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    if (dep[x] > dep[y]) {
        x = goStep(x, dep[x] - dep[y]);
    }
    if (x == y) return x;
    for (int i = 17; i >= 0; i--) {
        if (parent[x][i] != parent[y][i]) {
            x = parent[x][i];
            y = parent[y][i];
        }
    }
    return parent[x][0];
}

struct Tree{
    int cnt[N << 2];

    void push(int x, int l, int r) {
        cnt[L] += cnt[x], cnt[R] += cnt[x];
        cnt[x] = 0;
    }

    void update(int x, int l, int r) {
        if (ql <= l && qr >= r) {
            cnt[x]++;
        }
        else {
            if (cnt[x]) push(x, l, r);
            if (ql <= MID) update(LC);
            if (qr > MID) update(RC);
        }
    }

    void update(int a, int b) {
        while (top[a] - top[b]) {
            if (dep[top[a]] > dep[top[b]]) {
                swap(a, b);
            }
            ql = pos[top[b]], qr = pos[b];
            update(1, 1, n);
            b = pre[top[b]];
        }
        if (dep[a] > dep[b]) {
            swap(a, b);
        }
        ql = pos[a], qr = pos[b];
        update(1, 1, n);
    }

    int query(int x, int l, int r) {
        if (l == r) {
            return cnt[x];
        }
        else {
            if (cnt[x]) push(x, l, r);
            if (qx <= MID) return query(LC);
            else return query(RC);
        }
    }
}A, B; //A go down, B go up

void query(int x, int y) {
    if (x == y) return ;
    int z = getLca(x, y);
    //cout << x << ' ' << y << ' ' << z << endl;
    if (x != z) {
        int tmp = goStep(x, dep[x] - dep[z] - 1);
        //cout << "update B: " << x << ' ' << tmp << endl;
        B.update(x, tmp);
    }
    if (y != z) {
        int tmp = goStep(y, dep[y] - dep[z] - 1);
        //cout << "update A: " << y << ' ' << tmp << endl;
        A.update(y, tmp);
    }
}

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

int ans = 0;

void getAns(int x, int p) {
    REP(i, edge[x].size()) {
        int y = edge[x][i];
        if (y != p) {
            if (type[x][i]) {
                qx = pos[y];
                int a = 0, b = 0;
                if (type[x][i] == 1) {
                    b = B.query(1, 1, n);
                }
                else {
                    a = A.query(1, 1, n);
                }
                //cout << "getAns: " << x << ' ' << y << ' ' << a << ' ' << b << endl;
                add(ans, pw[a] - 1);
                add(ans, pw[b] - 1);
            }
            getAns(y, x);
        }
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    pw[0] = 1;
    REPP(i, 1, M - 1) pw[i] = pw[i - 1], add(pw[i], pw[i]);
    scanf("%d", &n);
    REPP(i, 1, n - 1) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        edge[x].push_back(y), type[x].push_back(z);
        edge[y].push_back(x), type[y].push_back(z);
        if (z) type[y].back() = 2;
    }
    dfs(1, 0), divide(1, 1);
    int k;
    scanf("%d", &k);
    int pre = 1;
    REP(i, k) {
        int x;
        scanf("%d", &x);
        query(pre, x);
        pre = x;
    }
    getAns(1, 0);
    printf("%d\n", ans);

    return 0;
}
