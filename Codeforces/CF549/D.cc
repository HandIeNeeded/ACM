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

const int N = 105;

char mp[N][N];
int v[N][N], a[N][N];

int main() {
    ios :: sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	REPP(i, 1, n) {
		cin >> mp[i] + 1;
	}
	REPP(i, 1, n) {
		REPP(j, 1, m) {
			if (mp[i][j] == 'W') {
				a[i][j] = 1;
			}
			else a[i][j] = -1;
		}
	}
	//REPP(i, 1, n) {
	//	REPP(j, 1, m) {
	//		cout << a[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	//REPP(i, 1, n) {
	//	REPP(j, 1, m) {
	//		cout << v[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	int ans = 0;
	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {
			if (v[i][j] != a[i][j]) {
				int d = a[i][j] - v[i][j];
				if (d) {
					ans++;
					for (int tt = i; tt >= 1; tt--) {
						for (int rr = j; rr >= 1; rr--) {
							v[tt][rr] += d;
						}
					}
				}
			}
		}
	}
	cout << ans << endl;

    return 0;
}

