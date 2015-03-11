#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
const int MO = 998244353;

int dp[2][55][55];

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}

int main() {
	ios :: sync_with_stdio(0);
	
	int n, m, p;
	cin >> n >> p >> m;
	dp[0][0][0] = 1;
	int cur = 0;
	REPP(i, 1, n) {
		REP(mod, p) {
			REP(sum, m + 1) {
				REP(digit, 10) {
					if (sum + digit <= m) {
						add(dp[cur ^ 1][(10 * mod + digit) % p][sum + digit], dp[cur][mod][sum]);
					}
					else break;
				}
			}
		}
		MST(dp[cur], 0);
		cur ^= 1;
	}
	REPP(i, 1, m) add(dp[cur][0][i], dp[cur][0][i - 1]);
	REPP(i, 0, m) {
		cout << dp[cur][0][i] << " \n"[i == m];
	}

	return 0;
}
