#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;

int fi[N], en[N], ne[N], edge; 
int dp[N][20], in[N];

void add(int x, int y) {
	ne[++edge] = fi[x], fi[x] = edge, en[edge] = y;
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);

	int n, t, ca = 1, x;
	cin >> t;
	while (t--) {
		cin >> n;
		REPP(i, 1, n) {
			cin >> x;
			if (x) in[x]++, add(i, x);
		}
		int res = INF;
		queue<int> q;
		REPP(i, 1, n) {
			if (in[i] == 0) {
				q.push(i);
			}
		}
		while (q.size()) {
			int x = q.front(); q.pop();
			REP(j, 20) dp[x][j] += j;
			for (int go = fi[x]; go; go = ne[go]) {
				int y = en[go];
				REP(i, 20) {
					int tmp = INF;
					REP(j, 20) if (j != i) {
						tmp = min(tmp, dp[x][j]);
					}
					dp[y][i] += tmp;
				}
				in[y]--;
				if (in[y] == 0) q.push(y);
			}
		}
		REP(i, 20) res = min(res, dp[1][i]);
		res += n;
		cout << "Case #" << ca++ << ": " << res << endl;
		MST(dp, 0), MST(fi, 0), edge = 0;
	}

	return 0;
}


