#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
const int MO = 1e9 + 9;

int vis[N], pw[N] = {1}, out[N], in[N];
pair<int, int> p[N];
map<pair<int, int>, int> mp;
vector<int> edge[2][N];

bool good(int x) {
	if (out[x] == 0) return 1;
	for (auto y: edge[1][x]) {
		if (!vis[y] && in[y] == 1) return 0;
	}
	return 1;
}

int main() {
	ios :: sync_with_stdio(0);
	int n;
	cin >> n;
	REPP(i, 1, n) {
		pw[i] = 1LL * n * pw[i - 1] % MO;
	}
	REP(i, n) {
		int x, y;
		cin >> x >> y;
		p[i] = {x, y};
		mp[p[i]] = i;
	}
	queue<int> q;
	REP(i, n) {
		if (p[i].second == 0) {
			q.push(i);
			vis[i] = 1;
		}
	}
	//0 in 1 out
	while (q.size()) {
		int id = q.front(); q.pop();
		int x = p[id].first, y = p[id].second;
		REPP(dx, -1, 1) {
			REPP(dy, 1, 1) if (dx || dy) {
				int tx = x + dx, ty = y + dy;
				if (!mp.count({tx, ty})) continue;
				int tmp = mp[{tx, ty}];
				edge[0][tmp].push_back(id);
				edge[1][id].push_back(tmp);
				in[tmp]++;
				out[id]++;
				if (vis[tmp]) continue;
				q.push(tmp);
				vis[tmp] = 1;
			}
		}
	}
	MST(vis, 0);
	set<int> s;
	REP(i, n) {
		if (good(i)) {
			s.insert(i);
		}
	}
	int turn = 0, now = n - 1;
	int ans = 0;
	//REP(i, n) {
	//	cout << in[i] << ' ' << out[i] << endl;
	//}
	while (s.size()) {
		int id;
		if (turn) {
			auto it = s.begin();
			id = *it;
			s.erase(*it);
		}
		else {
			auto it = s.rbegin();
			id = *it;
			s.erase(*it);
		}
		if (vis[id] || !good(id)) {
			continue;
		}
		vis[id] = 1;
		in[id] = out[id] = 0;
		//cout << id << endl;
		ans += 1LL * id * pw[now--] % MO;
		if (ans >= MO) ans -= MO;
		for (auto y: edge[0][id]) {
			if (!vis[y]) {
				out[y]--;
			}
		}
		for (auto y: edge[1][id]) {
			if (!vis[y]) {
				in[y]--;
			}
		}
		for (auto y: edge[0][id]) {
			if (!vis[y]) {
				if (good(y) && !s.count(y)) s.insert(y);
			}
		}
		for (auto y: edge[1][id]) {
			if (!vis[y]) {
				if (good(y) && !s.count(y)) s.insert(y);
			}
		}
		turn ^= 1;
		//REP(i, n) {
		//	cout << in[i] << ' ' << out[i] << endl;
		//}
	}
	cout << ans << endl;

	return 0;
}

