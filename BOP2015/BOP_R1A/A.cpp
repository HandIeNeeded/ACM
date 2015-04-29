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

const int N = 1e5 + 5;
map<int, int> mp[N];
vector<int> edge[N];
int ans, vis[N], pre[N], col[N];

int main() {
	int t, ca = 1;
	scanf("%d", &t);
	while(t--) {
		int n, qq;
		scanf("%d", &n);
		REPP(i, 0, n) col[i] = 0, edge[i].clear(), mp[i].clear();
		REPP(i, 1, n - 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		queue<int> q;
		REPP(i, 1, n) vis[i] = 0;
		q.push(1), vis[1] = 1;
		mp[0][0] = 1, col[0] = -1;
		while (q.size()) {
			int x = q.front(); q.pop();
			REP(i, edge[x].size()) {
				int y = edge[x][i];
				if (!vis[y]) {
					vis[y] = 1, pre[y] = x, mp[x][0]++;
					q.push(y);
				}
			}
		}
		scanf("%d", &qq);
		printf("Case #%d:\n", ca++);
		ans = 1;
		while (qq--) {
			int ty;
			scanf("%d", &ty);
			if (ty == 1) {
				printf("%d\n", ans);
			}
			else {
				int x, y;
				scanf("%d%d", &x, &y);
				int z = col[x];
				int common = (col[pre[x]] == col[x]) + mp[x][col[x]];
				col[x] = y;
				int diff = (col[pre[x]] == col[x]) + mp[x][col[x]];
				ans += common - diff;
				mp[pre[x]][z]--;
				mp[pre[x]][col[x]]++;
			}
		}
	}
	return 0;
}

