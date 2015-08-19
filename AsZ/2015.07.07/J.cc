#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
vector<int> edge[N], e[N];
vector<int> candidate;
int degree[N], vis[N], deg[N];
int n, m, now;

void goup(int x) {
	if(e[x].size() == 0) {
		candidate.push_back(x);
		return ;
	}
	for (auto &y: e[x]) {
		if (vis[y] == now) continue;
		goup(y);
	}
}

void go(int x) {
	vis[x] = now;
	for (auto &y: edge[x]) {
		if (vis[y] == now) continue;
		go(y);
	}
}

pair<int, int> rnd() {
	sort(candidate.begin(), candidate.end());
	candidate.resize(unique(candidate.begin(), candidate.end()) - candidate.begin());
	int n = candidate.size();
	int node = 0, ans = 0, fail = 0;
	REPP(i, 1, 300) {
		int x = candidate[rand() % n];
		//cout << "random now: " << x << endl;
		now++;
		go(x);
		int tmp = 0;
		REPP(i, 1, ::n) if (vis[i] == now) tmp++;
		//cout << "node cnt " << x << ' ' << tmp << endl;
		if (tmp > ans) {
			node = x, ans = tmp;
		}
		else {
			fail++;
			if (fail > 100) break;
		}
	}
	return {node, ans};
}

int main() {
	freopen("journey.in", "r", stdin);
	freopen("journey.out", "w", stdout);
	srand(time(0) % clock());
	while (scanf("%d", &n), n) {
		scanf("%d", &m);
		REPP(i, 1, n) edge[i].clear(), e[i].clear(), degree[i] = 0;
		candidate.clear();
		REPP(i, 1, m) {
			int x, y;
			scanf("%d%d", &x, &y);
			edge[x].push_back(y);
			e[y].push_back(x);
			degree[x]++;
		}
		int mx = -1;
		REPP(i, 1, n) mx = max(mx, degree[i]);
		REPP(i, 1, n) if (e[i].size() && edge[i].size() == 0) {
			now++;
			goup(i);
		}
		REPP(i, 1, n) if (degree[i] == mx) {
			now++;
			goup(i);
		}
		int k = int(sqrt(n + 0.5));
		REP(i, k) {
			now++;
			goup(rand() % n + 1);
			candidate.push_back(rand() % n + 1);
		}
		int node = 0, ans = 0;
		tie(node, ans) = rnd();
		printf("%d %d\n", node, ans);
	}

	return 0;
}
