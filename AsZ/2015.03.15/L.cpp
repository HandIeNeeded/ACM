#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 305;
const int INF = 0x3f3f3f3f;
int dp[N][N], Left[N], Right[N];

struct Enemy{
	int x, y, h;
}q[N];

bool cmp(Enemy a, Enemy b) {
	return a.x < b.x;
}

int main() {
	ios :: sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		REPP(i, 1, n) {
			int x, y, h;
			cin >> x >> y >> h;
			q[i] = {x, y, h};
		}
		sort(q + 1, q + n + 1, cmp);
		REPP(i, 1, n) {
			Left[i] = Right[i] = i;
			int &j = Left[i];
			while (j > 0 && q[j].y >= q[i].x && q[j].h <= q[i].h) j--;
			int &k = Right[i];
			while (j <= n && q[k].x == q[i].x && q[k].h <= q[i].h) k++;
		}
		REPP(i, 1, n) {
			cout << i << ' ' << Left[i] << ' ' << Right[i] << endl;
		}
		REPP(i, 1, n) dp[i][i] = q[i].h;
		REPP(i, 1, n - 1) {
			if (q[i].y >= q[i + 1].x) {
				dp[i][i + 1] = max(dp[i][i], dp[i + 1][i + 1]);
			}
			else {
				dp[i][i + 1] = dp[i][i] + dp[i + 1][i + 1];
			}
		}
		REPP(k, 2, n - 1) {
			REPP(i, 1, n) {
				if (i + k <= n) {
					int j = i + k;
					dp[i][j] = INF;
					REPP(mid, i, j) {
						dp[i][j] = min(dp[i][j], dp[i][Left[i]] + q[mid].h + dp[Right[i]][j]);
					}
				}
			}
		}
		cout << dp[1][n] << endl;
	}
	
	return 0;
}

