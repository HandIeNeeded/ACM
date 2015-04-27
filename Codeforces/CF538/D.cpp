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

const int N = 105;

char mp[N][N], op[N][N], g[N][N];
int sx, sy, n;

bool good(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
	ios :: sync_with_stdio(0);
	cin >> n;
	REP(i, n) cin >> mp[i];
	sx = sy = n - 1;
	REP(i, 2 * n - 1) {
		REP(j, 2 * n - 1) {
			op[i][j] = 'x';
		}
	}
	REP(i, n) {
		REP(j, n) g[i][j] = '.';
	}
	op[sx][sy] = 'o';
	REP(i, n) {
		REP(j, n) if (mp[i][j] == 'o') {
			REP(k, n) {
				REP(t, n) {
					if (mp[k][t] == '.') {
						op[sx + k - i][sy + t - j] = '.';
					}
				}
			}
		}
	}
		//REP(i, 2 * n - 1) {
		//	cout << op[i] << endl;
		//}
	REP(i, n) {
		REP(j, n) {
			if (mp[i][j] == 'o') {
				REP(k, 2 * n - 1) {
					REP(t, 2 * n - 1) if (op[k][t] == 'x') {
						if (good(i + k - sx, j + t - sy)) {
							g[i + k - sx][j + t - sy] = 'x';
						}
					}
				}
			}
		}
	}
	//REP(i, n) {
	//	cout << g[i] << endl;
	//}
	int bad = 0;
	REP(i, n) {
		REP(j, n) {
			if (mp[i][j] != 'o') {
				if (mp[i][j] != g[i][j]) {
					bad = 1;
				}
			}
		}
	}
	if (bad) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		REP(i, 2 * n - 1) {
			cout << op[i] << endl;
		}
	}

	return 0;
}

