#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 3e5 + 5;

int in() {
	char c;
	while ((c = getchar()), (c < '0' || c > '9'));
	int ans = 0;
	while (c >= '0' && c <= '9') {
		ans = 10 * ans + c - 48;
		c = getchar();
	}
	return ans;
}

void out(int x) {
	int bit[8], len = 0;
	while (x) {
		bit[len++] = x % 10;
		x /= 10;
	}
	while (len--) {
		putchar('0' + bit[len]);
	}
	putchar('\n');
}

struct Edge{
	int from, to, id;
};

vector<pair<int, int> > a[2][N];
Edge p[N];
int f[N], degree[N], sum[N], cost[N], cnt[2];
bool use[N];

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

bool cmp(const Edge &a, const Edge &b) {
	return cost[a.id] < cost[b.id];
}

clock_t st, ed;
int n, m;

long long calc(int x, int y, int z) {
	long long ans = 0;
	ans += 1LL * degree[x] * sum[x] + 1LL * degree[y] * sum[y] + 1LL * degree[z] * sum[z];
	return ans;
}

void modify() {
	if (cnt[0] == 0) return ;
	while (1.0 * (clock() - st) / CLOCKS_PER_SEC < 0.90) {
		int y = rand() % n + 1;
		while (!a[0][y].size() || !a[1][y].size()) {
			y = rand() % n + 1;
		}
		int sz0 = a[0][y].size(), sz1 = a[1][y].size();
		int pos0 = rand() % sz0, pos1 = rand() % sz1;
		int x = a[0][y][pos0].first, id0 = a[0][y][pos0].second;
		int z = a[1][y][pos1].first, id1 = a[1][y][pos1].second;
		long long ans1 = calc(x, y, z);
		int cost0 = cost[id0];
		int cost1 = cost[id1];
		degree[x]++, sum[x] += cost0;
		sum[y] += cost0 - cost1;
		degree[z]--, sum[z] -= cost1;
		long long ans2 = calc(x, y, z);
		if (ans2 >= ans1) {
			degree[x]--, sum[x] -= cost0;
			sum[y] -= cost0 - cost1;
			degree[z]++, sum[z] += cost1;
		}
		else {
			use[id1] = 0;
			use[id0] = 1;
			auto it = a[1][z].begin();
			while (it->first != y) it++;
			a[1][z].erase(it);
			it = a[0][x].begin();
			while (it->first != y) it++;
			a[0][x].erase(it);
			a[0][z].push_back({y, id1});
			a[1][x].push_back({y, id0});
			swap(a[0][y][pos0], a[1][y][pos1]);
		}
	}
}

int mark[N];

int main() {
	freopen("E.in", "r", stdin);
	st = clock();
	n = in(), m = in();
	//REPP(i, 1, n) mark[i] = i;
	//random_shuffle(mark + 1, mark + n + 1);
	REPP(i, 1, m) {
		int x, y;
		x = in(), y = in(), cost[i] = in();
		p[i] = {x, y, i};
	}
	sort(p + 1, p + m + 1, cmp);
	REPP(i, 1, n) f[i] = i;
	REPP(i, 1, m) {
		int x = p[i].from, y = p[i].to, z = cost[p[i].id], id = p[i].id;
		int tx = find(x), ty = find(y);
		if (tx != ty) {
			use[id] = 1;
			f[tx] = ty;
			degree[x]++, degree[y]++;
			sum[x] += z, sum[y] += z;
			a[1][x].push_back({y, id});
			a[1][y].push_back({x, id});
			cnt[1]++;
		}
		else {
			a[0][x].push_back({y, id});
			a[0][y].push_back({x, id});
			cnt[0]++;
		}
	}
	REPP(i, 1, m) {
		if (use[i]) {
			out(i);
		}
	}
	modify();
	REPP(i, 1, m) {
		if (use[i]) {
			out(i);
		}
	}

	return 0;
}
