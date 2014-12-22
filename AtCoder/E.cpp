#include <bits/stdc++.h>
 
#define REP(i, a) for (int i = 0;i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long
 
using namespace std;
 
const int N = 105;
double dp[N][N][N][4];
bool vis[N][N][N][4];
int px, py, pz;
 
double solve(int x, int y, int z, int st) {
	if (x == y && z == y && z == 0) {
		return 0;
	}
	else if (x < 0 || y < 0 || z < 0) {
		return 1e100;
	}
	else if (vis[x][y][z][st]) return dp[x][y][z][st];
	else {
		vis[x][y][z][st] = 1;
		double &ans = dp[x][y][z][st];
		ans = 1e100;
		if (st == 0) {
			ans = min(ans, 100.0 / px + solve(x - 1, y, z, 1));
			ans = min(ans, 100.0 / py + solve(x, y - 1, z, 1));
			ans = min(ans, 100.0 / pz + solve(x, y, z - 1, 1));
			return ans;
		}
		else if (st == 2) {
			ans = min(ans, solve(x, y, z, 0) * (100 - px) / 100.0 + solve(x - 1, y, z, 0) * px / 100.0);
			ans = min(ans, solve(x, y, z, 0) * (100 - py) / 100.0 + solve(x, y - 1, z, (st + 1) % 4) * py / 100.0);
			ans = min(ans, solve(x, y, z, 0) * (100 - pz) / 100.0 + solve(x, y, z - 1, (st + 1) % 4) * pz / 100.0);
			return ans;
		}
		else {
			ans = min(ans, solve(x, y, z, 0) * (100 - px) / 100.0 + solve(x - 1, y, z, (st + 1) % 4) * px / 100.0);
			ans = min(ans, solve(x, y, z, 0) * (100 - py) / 100.0 + solve(x, y - 1, z, (st + 1) % 4) * py / 100.0);
			ans = min(ans, solve(x, y, z, 0) * (100 - pz) / 100.0 + solve(x, y, z - 1, (st + 1) % 4) * pz / 100.0);
			return ans;
		}
	}
}
 
int main() {
	ios :: sync_with_stdio(0);
	int a, b, c;
	cin >> a >> b >> c;
	cin >> px >> py >> pz;
	cout << fixed << setprecision(10) << solve(a, b, c, 0) << endl;
 
	return 0;
}
