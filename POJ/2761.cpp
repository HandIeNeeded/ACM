#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <climits>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 100005;

int node[N], val[N], weight[N], child[N][2], cnt[N], tot;

void update(int x) {
	node[x] = node[child[x][0]] + cnt[x] + node[child[x][1]];
}

void rotate(int &x, int t) {
	int y = child[x][t];
	child[x][t] = child[y][1 ^ t];
	child[y][1 ^ t] = x;
	update(x);
	update(y);
	x = y;
}

void insert(int &x, int number) {
	if (x) {
		if (val[x] == number) {
			cnt[x] ++;
		}
		else {
			int t = val[x] < number;
			insert(child[x][t], number);
			if (weight[child[x][t]] < weight[x]) {
				rotate(x, t);
			}
		}
	}
	else {
		x = tot++;
		val[x] = number;
		cnt[x] = 1;
		weight[x] = rand();
		MST(child[x], 0);
	}
	update(x);
}

void erase(int &x, int s) {
	if (val[x] == s) {
		if (cnt[x] > 1) {
			cnt[x] --;
		}
		else {
			if (!child[x][0] && !child[x][1]) {
				x = 0;
				return ;
			}
			else {
				rotate(x, weight[child[x][0]] > weight[child[x][1]]);
				erase(x, s);
			}
		}
	}
	else {
		erase(child[x][val[x] < s], s);
	}
	update(x);
}

int select(int &x, int s) {
	if (node[child[x][0]] >= s) {
		return select(child[x][0], s);
	}
	else if (node[child[x][0]] + cnt[x] >= s) {
		return val[x];
	}
	else {
		return select(child[x][1], s - node[child[x][0]] - cnt[x]);
	}
}

int ans[N], a[N];
pair<pair<pair<int, int>, int>, int> q[N];

int main() {
	ios :: sync_with_stdio(0);

	int n, m;	
	tot = 1, node[0] = 0, weight[0] = INT_MAX;
	cin >> n >> m;
	REPP(i, 1, n) {
		cin >> a[i];
	}
	REPP(i, 1, m) {
		int x, y, z;
		cin >> x >> y >> z;
		q[i] = {{{x, y}, z}, i};
	}
	sort(q + 1, q + m + 1);
	int l = 1, r = 0, rt = 0;
	REPP(i, 1, m) {
		while (r < q[i].first.first.second) {
			insert(rt, a[++r]);
		}
		while (l < q[i].first.first.first) {
			erase(rt, a[l++]);
		}
		ans[q[i].second] = select(rt, q[i].first.second);
	}
	REPP(i, 1, m) {
		cout << ans[i] << endl;
	}
	
	return 0;
}
