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

const int N = 1005;
const int MO = 100007;
int dp[N][N];
char s[N];

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}

int main() {
	//freopen("B.in", "r", stdin);
	int t, ca = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		int n = strlen(s);
		REPP(i, 1, n) dp[i][i] = 1;
		REPP(i, 1, n - 1) dp[i][i + 1] = 2 + (s[i - 1] == s[i]);
		REPP(k, 2, n) {
			REPP(i, 1, n) if (i + k <= n) {
				int j = i + k;
				dp[i][j] = dp[i][j - 1];
				add(dp[i][j], dp[i + 1][j]);
				if (s[i - 1] != s[j - 1]) {
					add(dp[i][j], MO - dp[i + 1][j - 1]);
				}
				else {
					add(dp[i][j], 1);
				}
			}
		}
		printf("Case #%d: %d\n", ca++, dp[1][n]);
	}

	return 0;
}

