#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 4005;
short dp[N][N];
string s, ans;

int main() {
    ios :: sync_with_stdio(0);
	int n, k;
	cin >> k >> s;
	s = s + s;
	n = s.size();
	queue<int> pos;
	REPP(dif, 1, n - 1) {
		while (pos.size()) pos.pop();
		int end = n, b = n - 1, a = b - dif;
		while (a >= 0) {
			if (s[a] != s[b]) {
				pos.push(b);
			}
			while (int(pos.size()) > k) {
				end = pos.front();
				pos.pop();
			}
			dp[a][b] = end - b;
			a--, b--;
		}
	}
	int mx = -1;
	REP(i, n) {
		REPP(j, i + 1, n - 1) {
			//wrong j - i not j - i + 1
			if (dp[i][j] >= j - i && (j - i) * 2 <= n / 2) {
				//cout << i << ' ' << j << ' ' << mx << endl;
				if (j - i > mx) {
					mx = j - i;
					ans = s.substr(i, 2 * (j - i));
				}
				else if (j - i == mx) {
					ans = min(ans, s.substr(i, 2 * (j - i)));
				}
			}
		}
	}
	cout << ans << endl;
    return 0;
}

