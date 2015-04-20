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

const int N = 105;
const int M = 2e5 + 5;
const double eps = 1e-10;

int cmp(double x) {
	if (fabs(x) < eps) return 0;
	else if (x > 0) return 1;
	else return -1;
}

struct MaxFlow{
	int fi[N], en[M], ne[M], edge;
	double cap[M];
	int lvl[N], cur[N], source, sink, tot;

	void init(int n) {
		edge = 1, tot = n + 2;
		source = n + 1, sink = n + 2;
		REPP(i, 1, tot) fi[i] = 0;
	}

	void _add(int x, int y, double z) {
		ne[++edge] = fi[x], fi[x] = edge, en[edge] = y, cap[edge] = z;
	}

	void add(int x, int y, double z) {
		_add(x, y, z);
		_add(y, x, 0);
	}

	bool bfs() {
		queue<int> q;
		REPP(i, 1, tot) lvl[i] = 0;
		q.push(source), lvl[source] = 1;
		while (q.size()) {
			int x = q.front(); q.pop();
			for (int go = fi[x]; go; go = ne[go]) if (cmp(cap[go]) > 0) {
				int y = en[go];
				if (!lvl[y]) {
					lvl[y] = lvl[x] + 1;
					q.push(y);
				}
			}
		}
		return lvl[sink];
	}

	double dfs(int x, double flow) {
		if (x == sink || cmp(flow) == 0) {
			return flow;
		}
		double ans = 0, tmp = 0;
		for (int &go = cur[x]; go; go = ne[go]) if (cmp(cap[go]) > 0) {
			int y = en[go];
			if (lvl[y] == lvl[x] + 1 && cmp(tmp = dfs(y, min(flow, cap[go]))) > 0) {
				cap[go] -= tmp, cap[go ^ 1] += tmp;
				ans += tmp, flow -= tmp;
				if (cmp(flow) <= 0) return ans;
			}
		}
		return ans;
	}

	double dinic() {
		double ans = 0;
		while (bfs()) {
			REPP(i, 1, tot) cur[i] = fi[i];
			ans += dfs(source, 1e10);
		}
		return ans;
	}
}D;

int n, cnt, a[N];
int qa[M], qb[M], degree[N];

void prepare(double g) {
	D.init(n);
	REP(i, cnt) {
		D.add(qa[i], qb[i], 1);
		D.add(qb[i], qa[i], 1);
	}
	REPP(i, 1, n) {
		D.add(D.source, i, 1.0 * cnt);
		D.add(i, D.sink, cnt + 2 * g - degree[i]);
	}
}

double work() {
	double hi = 1.0 * cnt, lo = 0;
	while (cmp(hi - lo) > 0) {
		double mid = (hi + lo) / 2.0;
		prepare(mid);
		double ans = (1.0 * n * cnt - D.dinic());
		if (cmp(ans) <= 0) hi = mid;
		else lo = mid;
	}
	return lo;
}

int main() {
	ios :: sync_with_stdio(0);
	//freopen("C.in", "r", stdin);
	int t, ca = 1;
	cin >> t;
	while (t--) {
		cin >> n;
		REPP(i, 1, n) cin >> a[i];
		REPP(i, 1, n) degree[i] = 0;
		cnt = 0;
		REPP(i, 1, n) {
			REPP(j, i + 1, n) {
				if (a[i] > a[j]) {
					qa[cnt] = a[i];
					qb[cnt++] = a[j];
					degree[a[i]]++, degree[a[j]]++;
				}
			}
		}
		cout << "Case #" << ca++ << ": " << fixed << setprecision(10) << work() << endl;
	}

	return 0;
}

