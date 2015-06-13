#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;

struct Edge{
	int st, ed, next;
}e[N];

int head[N], edge;
int vis[N];

void add(int x, int y) {
	e[++edge].next = head[x], e[edge].st = x, e[edge].ed = y;
	head[x] = edge;
}

pair<int, int> dp[N][2]; //node color add
int diff[N];
bool use[100];

void dfs(int x) {
	dp[x][0] = dp[x][1] = {INF, INF};
	int son = 0, sum = 0;
	for (int go = head[x]; go; go = e[go].next) {
		son++;
		int y = e[go].ed;
		dfs(y);
		sum += dp[y][0].first;
	}
	if (!son) dp[x][0] = {1, 1}, dp[x][1] = {2, 2};
	else {
		int now = 1, id = 0;
		for (int go = head[x]; go; go = e[go].next) {
			int y = e[go].ed;
			diff[dp[y][0].second] = 0;
			use[dp[y][0].second] = 0;
			vis[dp[y][0].second] = x;
		}
		while (now <= son + 2) {
			if (vis[now] != x) {
				dp[x][id] = {sum + now, now};
				id++;
			}
			now++;
			if (id == 2) break;
		}
		for (int go = head[x]; go; go = e[go].next) {
			int y = e[go].ed;
			diff[dp[y][0].second] += dp[y][1].first - dp[y][0].first;
		}
		for (int go = head[x]; go; go = e[go].next) {
			int y = e[go].ed, z = dp[y][0].second;
			if (use[z]) continue;
			if (sum + z + diff[z] <= dp[x][0].first) {
				dp[x][1] = dp[x][0];
				dp[x][0] = {sum + z + diff[z], z};
			}
			else if (sum + z + diff[z] <= dp[x][1].first) {
				dp[x][1] = {sum + z + diff[z], z};
			}
			use[z] = 1;
		}
	}
}

int main() {
    ios :: sync_with_stdio(0);
	//freopen("in", "r", stdin);
	int t, ca = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		REP(i, n + 1) vis[i] = 0, head[i] = 0;
		edge = 0;
		REP(i, n) {
			int x;
			cin >> x;
			if (x) add(x, i + 1);
		}
		dfs(1);
		cout << "Case #" << ca++ << ": " << dp[1][0].first << endl;
	}
    return 0;
}

