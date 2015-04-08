#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e6 + 5;
bool vis[N];
int mp[1005][1005];

int main() {
	ios :: sync_with_stdio(0);
	int n;
	cin >> n;
	REPP(i, 1, n) {
		int x;
		cin >> x;
		vis[x] = 1;
	}
	REPP(i, 1, 1000) {
		REPP(j, 1, 1000) {
			mp[i][j] = __gcd(i, j);
		}
	}
	int ans = 0;
	REPP(i, 1, 1000000) {
		int lim = 1000000 / i;
		for (int j = 1; j * j <= lim; j++) {
			for (int k = j + 1; k * k <= lim; k++) {
				if (mp[j][k] == 1) {
					if (vis[j * j * i] && vis[k * k * i] && vis[i * j * k]) {
						ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}
