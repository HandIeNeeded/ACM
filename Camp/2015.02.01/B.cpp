#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i++)
#define MST(a, b) node(a, b, sizeof(a))

using namespace std;

const int N = 45;
const int MO = 1e9 + 7;
vector<pair<int, int> > edge[N];
int mp[105][2][2], col[N];
pair<int, int> p[105];
vector<int> node[2];
bool vis[N];

void dfs(int x, int now) {
	node[now].push_back(x);
	vis[x] = 1;
	for (auto y: edge[x]) {
		if (!vis[y.first]) dfs(y.first, now ^ 1);
	}
}

int ans = 0;

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
	if (x < 0) x += MO;
}

int calc() {
	int ans = 1;
	vector<int> &s = node[1];
	for (auto x: s) {
		int res = 0;
		REP(k, 2) {
			int tmp = 1;
			for (auto y: edge[x]) {
				int id = y.second;
				int cost = p[id].first == x ? mp[id][k][col[y.first]] : mp[id][col[y.first]][k];
				tmp = 1LL * tmp * cost % MO;
			}
			add(res, tmp);
		}
		ans = 1LL * ans * res % MO;
	}
	return ans;
}

void go(int now) {
	if (now == (int) node[0].size()) {
		add(ans, calc());
	}
	else {
		REP(i, 2) {
			col[node[0][now]] = i;
			go(now + 1);
		}
	}
}

int main() {
	ios :: sync_with_stdio(0);
	//freopen("B.in", "r", stdin);

	int n, m;
	cin >> n >> m;
	REPP(i, 1, m) {
		int x, y;
		cin >> x >> y;
		p[i] = make_pair(x, y);
		edge[x].push_back({y, i});
		edge[y].push_back({x, i});
		REP(j, 2) {
			REP(k, 2) {
				cin >> mp[i][j][k];
			}
		}
	}
	REPP(i, 1, n) if (!vis[i]) dfs(i, 0);
	if (node[0].size() > node[1].size()) {
		swap(node[0], node[1]);
	}
	go(0);
	cout << ans << endl;

	return 0;
}
