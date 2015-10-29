#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 55;
const int C = 55;

struct AC{
	int tr[N * N][C], fail[N * N], node;
	string dict;

	void init(string s) {
		node = 0;
		dict = s;
		MST(tr[node], 0);
	}

	int New_Node() {
		MST(tr[node], 0);
		return node++;
	}

	int index(char c) {
		return dict.find(c);
	}

	void insert(char *s) {
		int pos = 0, now = 0;
		while (s[pos]) {
			int x = index(s[pos++]);
			if (!tr[now][x]) {
				tr[now][x] = New_Node();
			}
			now =tr[now][x];
		}
	}

	void getfail() {
		queue<int> q;
		REP(i, C) {
			if (tr[0][i]) {
				q.push(tr[0][i]);
				fail[tr[0][i]] = 0;
			}
		}
		while (q.size()) {
			int x = q.front(); q.pop();
			REP(i, C) {
				int
			}
		}

	}
}ac;
int n, m, p;
int dp[N][N * N];

int main() {
	ios :: sync_with_stdio(0);
	cin >> n >> m >> p;
	string s;
	cin >> s;
	ac.init(s);
	REP(i, p) {
		cin >> s;
		ac.insert(s.c_str());
	}
	ac.getfail();
	dp[0][0] = 1;
	REPP(i, 1, m) {
		REPP(j, 0, ac.node) {
			REP(c, n) {
				int node = tr[j][c];

			}
		}
	}

	return 0;
}

