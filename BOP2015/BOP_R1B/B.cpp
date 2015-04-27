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
#define LL long long

using namespace std;

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;

int f[N];
int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}

int fi[N], ne[N << 1], en[N << 1], edge;

void add(int x, int y) {
	ne[++edge] = fi[x], fi[x] = edge, en[edge] = y;
}

int tmp[N], tot;
int pre[N], vis[N], val[N];
int mi, id;

void bfs(int x) {
	queue<int> q;
	q.push(x), vis[x] = 1;
	tot = 0, tmp[tot++] = x;
	mi = val[x], id = x;
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int go = fi[x]; go; go = ne[go]) {
			int y = en[go];
			if (!vis[y]) {
				pre[y] = x;
				vis[y] = 1, q.push(y);
				tmp[tot++] = y;
				if (val[y] < mi) mi = val[y], id = y;
			}
		}
	}
}

bool use[N];

int main() {
	int t, ca = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		REPP(i, 1, n) scanf("%d", val + i);
		REPP(i, 1, n) use[i] = 0, fi[i] = 0, vis[i] = 0;
		edge = 0;
		REPP(i, 1, m) {
			int x, y;
			scanf("%d%d", &x, &y);
			add(x, y), add(y, x);
		}
		LL ans = 0, cnt = 0;
		REPP(i, 1, n) if (!vis[i]) {
			bfs(i);
			REP(i, tot) vis[tmp[i]] = 0;
			bfs(id);
			ans += val[id], use[id] = 1;
			cnt += tot - 1;
		}
		if (m - cnt < k) {
			vector<int> tmp;
			int kk = k - (m - cnt);
			REPP(i, 1, n) if (!use[i]) {
				tmp.push_back(val[i]);
			}
			sort(tmp.begin(), tmp.end());
			REP(i, kk) {
				ans += tmp[i];
			}
		}
		printf("Case #%d: %lld\n", ca++, ans);
	}

	return 0;
}

