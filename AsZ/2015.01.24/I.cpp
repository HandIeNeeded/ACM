#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 105;
const int M = 1505;

int bitcount(int x) {
	int ans = 0;
	while (x) {
		ans++;
		x &= x - 1;
	}
	return ans;
}

int fi[N], ne[M], en[M], edge;
int bit[1 << 16], mex[1 << 16], val[N], out[N], sg[N], son[N], limit[N], clk;
vector<int> invedge[N];

void add(int x, int y) {
	ne[++edge] = fi[x], fi[x] = edge, en[edge] = y;
}

void init() {
	REP(i, 1 << 16) {
		bit[i] = bitcount(i);
	}
}

void getsg(int n) {
	queue<int> q;
	REP(i, n) {
		if (out[i] == 0) {
			q.push(i);
			sg[i] = 0;
		}
	}
	while (q.size()) {
		int x = q.front(); q.pop();
		REP(i, invedge[x].size()) {
			int y = invedge[x][i];
			out[y]--;
			if (out[y] == 0) {
				clk++;
				int cnt = 0;
				for (int go = fi[y]; go; go = ne[go]) {
					son[cnt++] = en[go];
				}
				REP(i, 1 << cnt) if (bit[i] <= limit[y] && (bit[i] & 1) == (limit[y] & 1)) {
					int tmp = 0;
					REP(j, cnt) {
						if (i & (1 << j)) {
							tmp ^= sg[son[j]];
						}
					}
					mex[tmp] = clk;
				}
				int now = 0;
				while (mex[now] == clk) now++;
				assert(now < (1 << 16));
				sg[y] = now;
				q.push(y);
			}
		}
	}
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("I.in", "r", stdin);
	int t, ca = 1;

	init();
	cin >> t;
	while (t--) {
		int n, m, q;
		cin >> n >> m;
		assert(n <= 100 && n >= 2);
		assert(m <= 1500);
		REP(i, m) {
			int x, y;
			cin >> x >> y;
			assert(x >= 0 && x < n && y >= 0 && y < n && x != y);
			add(x, y);
			invedge[y].push_back(x);
			out[x]++;
			assert(out[x] <= 15);
		}
		REP(i, n) {
			cin >> limit[i];
		}
		getsg(n);
		cin >> q;
		int now = 1;
		cout << "Game#" << ca++ << ":" << endl;
		while (q--) {
			cout << "Round#" << now++ << ": ";
			int ans = 0;
			REP(i, n) {
				int x;
				cin >> x;
				if (x & 1) ans ^= sg[i];
			}
			if (ans) {
				cout << "WINNING" << endl;
			}
			else {
				cout << "LOSING" << endl;
			}
		}
		cout << endl;
		MST(fi, 0), edge = 0;
		REP(i, n) invedge[i].clear();
	}

	return 0;
}
