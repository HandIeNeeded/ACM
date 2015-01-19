#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e6 + 5;
const int C = 26;

int tr[N][C], dp[N], node;

int New_Node() {
	MST(tr[node], 0);
	dp[node] = 0;
	return node++;
}

void insert(char *s) {
	int pos = 0, now = 0;
	while (s[pos]) {
		int x = s[pos++] - 'a';
		if (!tr[now][x]) {
			tr[now][x] = New_Node();
		}
		dp[now]++;
		now = tr[now][x];
	}
	dp[now]++;
}

int find(char *s) {
	int pos = 0, now = 0;
	int ans = 0;
	while (s[pos]) {
		int x = s[pos++] - 'a';
		now = tr[now][x];
		ans++;
		if (dp[now] == 1) return ans;
	}
	return ans;
}

char s[N];

int main() {
	ios :: sync_with_stdio(0);
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int t, ca = 1, n;
	cin >> t;
	while (t--) {
		node = 0;
		New_Node();
		cin >> n;
		long long ans = 0;
		REPP(i, 1, n) {
			cin >> s;
			insert(s);
			ans += find(s);
		}
		cout << "Case #" << ca++ << ": " << ans << endl;
	}

	return 0;
}

