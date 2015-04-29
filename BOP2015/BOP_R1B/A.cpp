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
#define LL unsigned long long

using namespace std;

const int N = 14;
LL dp[N][N][N][N][5];
bool vis[N][N][N][N][5];
int cnt[N];

LL dfs(int a, int b, int c, int d, int e) {
	if (!(a | b | c | d)) return 1;

}

int main() {
	ios :: sync_with_stdio(0);
	int t, ca = 1;
	dfs(13, 13, 13, 13, 0);
	cin >> t;
	while (t--) {
		cin >> n;
		REP(i, 13) cnt[i] = 0;
		REP(i, n) {
			cin >> str;
			cnt[mp[str[0]]]++;
		}
		int tmp[4] = {0};
		REP(i, 13) tmp[cnt[i]]++;
		cout << dp[tmp[0]][tmp[1]][tmp[2]][tmp[3]][0] << endl;
	}

	return 0;
}

