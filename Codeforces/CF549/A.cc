#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 55;
char mp[N][N];
bool vis[26];
string str = "face";

int main() {
    ios :: sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	REPP(i, 1, n) {
		cin >> mp[i] + 1;
	}
	int ans = 0;
	REPP(i, 1, n) {
		REPP(j, 1, m) {
			MST(vis, 0);
			if (i + 1 <= n && j + 1 <= m) {
				vis[mp[i][j] - 'a'] = 1;
				vis[mp[i][j + 1] - 'a'] = 1;
				vis[mp[i + 1][j + 1] - 'a'] = 1;
				vis[mp[i + 1][j] - 'a'] = 1;
			}
			int bad = 0;
			REP(k, 4) if (!vis[str[k] - 'a']) bad = 1;
			if (!bad) ans++;
		}
	}
	cout << ans << endl;


    return 0;
}

