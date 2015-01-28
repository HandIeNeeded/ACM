#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define MP make_pair

using namespace std;

const int N = 10005;
const int INF = 0x3f3f3f3f;

int fi[N], en[N << 1], ne[N << 1], val[N << 1], edge;
int son[N], ban[N];
int n, m;

void add(int x, int y, int z) {
	ne[++edge] = fi[x], fi[x] = edge, en[edge] = y, val[edge] = z;
}

long long ans;
pair<int, int> rt;

void get_root(int x, int pre, int tot) {
	son[x] = 1;
	pair<int, int> tmp = MP(-INF, INF);
	for (int go = fi[x]; go; go = ne[go]) {
		int y = en[go];
		if (y != pre && !ban[y]) {
			get_root(y, x, tot);
			tmp = max(tmp, MP(son[y], x));
			son[x] += son[y];
		}
	}
	tmp = max(tmp, MP(tot - son[x], x));
	rt = min(rt, tmp);
}

void dfs(int x, int pre, int dep, vector<int> &tmp) {
	tmp.push_back(dep);
	son[x] = 1;
	for (int go = fi[x]; go; go = ne[go]) {
		int y = en[go];
		if (y != pre && !ban[y]) {
			dfs(y, x, dep + val[go], tmp);
			son[x] += son[y];
		}
	}
}

long long calculate(vector<int> &tmp) {
	long long ans = 0;
	sort(tmp.begin(), tmp.end());
	REP(i, tmp.size()) {
		int pos = lower_bound(tmp.begin(), tmp.end(), m - tmp[i] + 1) - tmp.begin();
		if (pos <= i) break;
		ans += pos - i - 1;
	}
	return ans;
}

void solve(int x, int tot, vector<int> &tmp) {
	rt = MP(INF, INF);
	get_root(x, -1, tot);
	tmp.push_back(0);
	for (int go = fi[rt.second]; go; go = ne[go]) {
		int y = en[go];
		if (!ban[y]) {
			vector<int> now;
			dfs(y, rt.second, val[go], now);
			ans -= calculate(now);
			REP(i, now.size()) tmp.push_back(now[i]);
		}
	}

	ans += calculate(tmp);
	ban[rt.second] = 1;
	for (int go = fi[rt.second]; go; go = ne[go]) {
		int y = en[go];
		if (!ban[y]) {
			vector<int> tmp;
			solve(y, son[y], tmp);
		}
	}
}

int main() {
	ios :: sync_with_stdio(0); 
	//freopen("in", "r", stdin);

	while (cin >> n >> m, n | m) {
		REP(i, n - 1) {
			int x, y, z;
			cin >> x >> y >> z;
			add(x, y, z);
			add(y, x, z);
		}
		ans = 0;
		vector<int> tmp;
		solve(1, n, tmp);
		cout << ans << endl;
		MST(ban, 0), MST(fi, 0), edge = 0;
	}
	return 0;
}
