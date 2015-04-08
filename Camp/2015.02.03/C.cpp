#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

struct Node{
	int dis, id, parent;
};

const int N = 2e5 + 5;
const int INF = 0x7f3f3f3f;
int key[N], dp[N][2], parent[N][2];
vector<int> edge[N], val[N];
int n, m, k;

struct cmp{
	bool operator () (const Node &a, const Node &b) const {
		return a.dis > b.dis || (a.dis == b.dis && a.parent > b.parent);
	}
};

void dijkstra() {
	priority_queue<Node, vector<Node>, cmp> q;
	REPP(i, 1, n) {
		REP(j, 2) {
			dp[i][j] = INF;
		}
	}
	REPP(i, 1, n) if (key[i]) {
		dp[i][0] = 0;
		parent[i][0] = i;
		q.push({0, i, i});
	}
	while (q.size()) {
		Node tmp = q.top(); q.pop();
		int x = tmp.id;
		REP(i, edge[x].size()) {
			int cost = val[x][i] + tmp.dis;
			int y = edge[x][i];
			if (cost < dp[y][0] || (cost == dp[y][0] && tmp.parent < parent[y][0])) {
				if (tmp.parent != parent[y][0]) {
					dp[y][1] = dp[y][0];
					parent[y][1] = parent[y][0];
				}
				dp[y][0] = cost;
				parent[y][0] = tmp.parent;
				q.push({cost, y, tmp.parent});
			}
			if (cost < dp[y][1] || (cost == dp[y][1] && tmp.parent < parent[y][1])) {
				if (tmp.parent != y && tmp.parent != parent[y][0]) {
					dp[y][1] = cost;
					parent[y][1] = tmp.parent;
					q.push({cost, y, tmp.parent});
				}
			}
		}
	}
}

int a[N];

int main() {
	//freopen("C.in", "r", stdin);
	ios :: sync_with_stdio(0);
	cin >> n >> m >> k;
	REPP(i, 1, m) {
		int x, y, z;
		cin >> x >> y >> z;
		edge[x].push_back(y), edge[y].push_back(x);
		val[x].push_back(z), val[y].push_back(z);
	}
	REP(i, k) {
		cin >> a[i];
		key[a[i]] = 1;
	}
	dijkstra();
	REP(i, k) {
		cout << parent[a[i]][1] << endl;
	}

	return 0;
}


