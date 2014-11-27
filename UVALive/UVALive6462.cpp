#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define MP make_pair 

using namespace std;

const int B = 21;
const int G = 8;

int can[1 << B][B], sum[1 << B][G], all[1 << B];
int dp[1 << B], cnt[B][G];

int g, b, s;

void Init() {
	REP(i, (1 << b)) {
		REP(j, b) if (i & (1 << j)){
			int st = i ^ (1 << j);
			can[i][j] = 0;
			REP(k, g) {
				can[i][j] += (sum[st][k] + cnt[j][k]) / s;
				sum[i][k] = (sum[st][k] + cnt[j][k]) % s;
			}
			all[i] = all[st] + can[i][j];
		}
	}
}

int main() {
	ios :: sync_with_stdio(0);
	// freopen("cf.in", "r", stdin);

	int n, x;

	while (cin >> g >> b >> s) {
		if (g | b | s) {
			REP(i, b) {
				cin >> n;
				REP(j, g) cnt[i][j] = 0;
				REP(j, n) {
					cin >> x;
					x--;
					cnt[i][x]++;
				}
			}
			Init();

			dp[0] = 0;
			int mask = (1 << b) - 1;
			REP(i, (1 << b)) {
				int tmp = 0;
				REP(j, b) if (i & (1 << j)){
					int st = (~i) & mask;
					if (can[st | (1 << j)][j]) {
						tmp = max(tmp, can[st | (1 << j)][j] + dp[i ^ (1 << j)]);
					}
					else {
						tmp = max(tmp, all[mask] - all[st] - dp[i ^ (1 << j)]);
					}
				}
				dp[i] = tmp;
			}
			// REP(i, (1 << b)) {
			// 	cout << i << ' ' << dp[i] << ' ' << all[i] << endl;
			// } 
			cout << 2 * dp[mask] - all[mask] << endl;
		}
		else break;
	}

	return 0;
}