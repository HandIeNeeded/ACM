#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 100005;
const int K = 30;

int tr[N * K][2], node, ans;
int fi[N], ne[N << 1], en[N << 1], val[N << 1], edge;

void add(int x, int y, int z) {
	ne[++edge] = fi[x], fi[x] = edge, en[edge] = y, val[edge] = z;
}

int New_Node() {
	MST(tr[node], 0);
	return node++;
}

void insert(int x) {
	int now = 0;
	for (int i = K - 1; i >= 0; --i) {
		int d = (x >> i) & 1;
		if (!tr[now][d]) {
			tr[now][d] = New_Node();
		}
		now = tr[now][d];
	}
}

int find(int x) {
	int now = 0, ans = 0;
	for (int i = K - 1; i >= 0; --i) {
		int d = (x >> i) & 1;
		if (tr[now][!d]) {
			now = tr[now][!d];
			ans |= (1 << i);
		}
		else {
			now = tr[now][d];
		}
	}
	return ans;
}

void dfs(int x, int p, int now) {
	ans = max(ans, find(now));
	insert(now);
	for (int go = fi[x]; go; go = ne[go]) {
		int y = en[go];
		if (y != p) {
			dfs(y, x, now ^ val[go]);
		}
	}
}

int main() {
	ios :: sync_with_stdio(0);
	//freopen("cf.in", "r", stdin);

	int t;
	int n, x, y, z;

	cin >> t;
	while (t--) {
		cin >> n;
		edge = node = 0;
		MST(fi, 0), MST(tr[0], 0);
		New_Node();
		REPP(i, 1, n - 1) {
			cin >> x >> y >> z;
			add(x, y, z);
			add(y, x, z);
		}
		ans = 0;
		insert(0);
		dfs(1, 0, 0);
		cout << ans << endl;
	}


	return 0;
}
