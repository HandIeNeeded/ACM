#include <bits/stdc++.h> 

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 55;
int fi[N], en[N], ne[N], edge;
int vis[N], dep[N], pre[N];
int n, m;

void add(int x, int y) {
	ne[++edge] = fi[x], fi[x] = edge, en[edge] = y;
}

void bfs(int start) {
	MST(vis, 0), MST(dep, 0);
	queue<int> q;
	q.push(start);
	vis[start] = 1;
	dep[start] = 0;

	while(q.size()) {
		int x = q.front(); q.pop();
		for(int go = fi[x]; go; go = ne[go]) {
			int y = en[go];
			if (!vis[y]) {
				vis[y] = 1;
				dep[y] = dep[x] + 1;
				q.push(y);
			}
		}
	}
}

void dfs(int x, int father,  int end) {
	for (int go = fi[x]; go; go = ne[go]) {
		int y = en[go];
		if (y != father) {
			dfs(y, x, end);
			pre[y] = x;
		}
	}
}

void getdiameter() {
	int mx = 0, start = 0, end = 0;
	bfs(1);
	REPP(i, 1, n) {
		if (dep[i] > mx) {
			start = i;
			mx = dep[i];
		}
	}
	
	bfs(start);
	mx = 0;
	REPP(i, 1, n) {
		if (dep[i] > mx) {
			end = i;
			mx = dep[i];
		}
	}
	
	MST(vis, 0);
	dfs(start, 0, end);
	int now = end;
	vis[start] = -1;
	while (now != start) {
		vis[now] = -1;
		now = pre[now];
	}
}

bool check() {
	REPP(i, 1, n) {
		if (vis[i] == -1) {
			queue<int> q;
			q.push(i);
			dep[i] = 0;
			
			while(q.size()) {
				int x = q.front(); q.pop();
				if (dep[x] == 2) break;
				for (int go = fi[x]; go; go = ne[go]) {
					int y = en[go];
					if (vis[y]) {
						continue;
					}
					dep[y] = dep[x] + 1;
					vis[y] = 1;
					q.push(y);
				}
			}
		}
	}

	REPP(i, 1, n) if (!vis[i]) return 0;
	return 1;
}

int main() {
	int t, x, y;
	ios :: sync_with_stdio(0);

	cin >> t;
	while(t--) {
		cin >> n >> m;
		MST(fi, 0), edge = 0;
		REPP(i, 1, m) {
			cin >> x >> y;
			x++, y++;
			add(x, y);
			add(y, x);
		}
		if (m > n - 1) {
			cout << "NO" << endl;
		}
		else {
			getdiameter();
			if (check()) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}

	return 0;
}
