#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define MP make_pair
#define EPS 1e-8

using namespace std;

const int N = 105;
const int M = 2005;
int f[N], edge[N];
pair<double, pair<int, int> > g[M];
double cost[M];
int id[M];
int n, m;

int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}
double sqr(double x) {return x * x;}

bool cmp(int i, int j) {
	return cost[i] + EPS < cost[j];
}

double kruscal(int num) {
	double ans = 0, avg = 0.5 * num + 0.1;

	REPP(i, 1, m) {
		cost[i] = sqr(g[i].first - avg);
	}
	REPP(i, 1, m) id[i] = i;
	sort(id + 1, id + m + 1, cmp);
	REPP(i, 1, n) f[i] = i;
	int now = 0, sum = 0, tot = n - 1;
	REPP(ca, 1, m) {
		int i = id[ca];
		int x = g[i].second.first, y = g[i].second.second;
		int tx = find(x), ty = find(y);
		if (tx != ty) {
			f[tx] = ty;
			edge[now++] = g[i].first;
			sum += g[i].first;
			tot--;
		}
		if (tot == 0) break;
	}
	avg = 1.0 * sum / (n - 1);
	REP(i, now) {
		ans += sqr(edge[i] - avg);
	}
	ans /= (n - 1);

	return ans;
}

int main() {
	// ios :: sync_with_stdio(0);
	// freopen("cf.in", "r", stdin);

	int x, y, z;
	int ca = 1;

	while (scanf("%d %d", &n, &m), n | m) {
		REPP(i, 1, m) {
			// cin >> x >> y >> z;
			scanf("%d %d %d", &x, &y, &z);
			g[i] = MP(1.0 * z, MP(x, y));
		}
		double ans = 1e100;
		REPP(i, 0, 105) {
			ans = min(ans, kruscal(i));
		}
		if (n == 1) ans = 0;
		printf("Case %d: %.2f\n", ca++, ans);
	}


	return 0;
}