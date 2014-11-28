#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <bitset>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#define dou double
#define mem(a) memset(a, 0, sizeof(a))
#define memm(a) memset(a, -1, sizeof(a))
#define LL long long
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
#define FI first
#define SE second
#define SZ(a) ((int) a.size())
#define ALL(a) a.begin(), a.end()
#define RI(a) scanf("%d", &(a))
#define RII(a, b) scanf("%d%d", &(a), &(b))
#define RIII(a, b, c) scanf("%d%d%d", &(a), &(b), &(c))
#define RL(a) scanf("%lld", &(a))
#define RLL(a, b) scanf("%lld%lld", &(a), &(b))
#define RLLL(a, b, c) scanf("%lld%lld%lld", &(a), &(b), &(c)) 
#define PI(r) printf("%d\n", (r))
#define PL(r) printf("%lld\n", (r))
#define RS(s) scanf("%s", (s))
#define SL(a) strlen(a)
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define FOR(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define MID ((l + r) >> 1)
#define L (x << 1)
#define R ((x << 1) | 1)
#define LC L, l, MID
#define RC R, MID + 1, r
#define LB(x) ((x) & (-(x)))
#pragma warning (disable : 4996)
//#pragma comment(linker, "/STACK:102400000,102400000")
#define EPS 1e-8
#define INF 2000000000
#define LIM (1ll << 60)
#define MOD 1000000007
#define N 111111

using namespace std;

int n, m;

int source, sink;
int lvl[55], vis[55], cur[55], fi[55], en[4444], ne[4444], tot;

struct edge{
	int cap, flow;
}e[4444];

void _add(int x, int y, int cap, int flow) {
	ne[++tot] = fi[x], fi[x] = tot, en[tot] = y;
	e[tot] = (edge) {cap, flow};
}

void add(int x, int y, int z) {
	_add(x, y, z, 0);
	_add(y, x, 0, 0);
}

int bfs() {
	mem(lvl), mem(vis);
	queue<int> q;
	q.push(source), vis[source] = 1;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int go = fi[x]; go; go = ne[go]) {
			int y = en[go];
			if (!vis[y] && e[go].cap > e[go].flow) {
				lvl[y] = lvl[x] + 1;
				vis[y] = 1;
				q.push(y);
			}
		}
	}
	//cout << "ss" << lvl[sink] << endl;
	return lvl[sink];
}

#define inv(x) ((x) + ((x) & 1 ? 1 : -1))

LL dfs(int x, LL flow) {
	LL ans = 0, tmpflow = 0;
	if (x == sink || flow == 0) return flow;
	for (int& go = cur[x]; go; go = ne[go]) {
		int y = en[go];
		if (lvl[y] == lvl[x] + 1 && (tmpflow = dfs(y, min(flow, 1ll * (e[go].cap - e[go].flow)))) > 0) {
			e[go].flow += tmpflow;
			e[inv(go)].flow -= tmpflow;
			flow -= tmpflow;
			ans += tmpflow;
			if (flow == 0) break;
		}
	}
	return ans;
}

LL Dinic() {
	LL maxflow = 0;
	while (bfs()) {
		//cout << "hehe" << endl;
		REPP(i, 1, n) cur[i] = fi[i];
		maxflow += dfs(source, LIM);
		//cout << maxflow << endl;
		//REPP(i, 1, tot) cout << i << ' ' << e[i].flow << endl;
		//system("PAUSE");
	}
	return maxflow;
}

int main(){
	int t, x, y, z, ca = 1;
	// freopen("D:/Contest/1.in", "r", stdin);
	//freopen("1.ans", "w", stdout);
	//ios :: sync_with_stdio(false);
	RI(t);
	while (t--) {
		RII(n, m);
		RII(source, sink);
		//cout << source << ' ' << sink << endl;
		int sum = 0;
		REPP(i, 1, m) {
			RIII(x, y, z);
			sum += z;
			z = z * 1000 + 1;
			add(x, y, z);
			add(y, x, z);
		}
		LL ans = Dinic();
		if (ans == 0) puts("Inf");
		else {
			printf("%.2f\n", 1.0 * (sum - ans / 1000) / (ans % 1000));
		}
		tot = 0, mem(fi);
	}

	return 0;
}