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
int mp[N][N], col[N];
int a[N], b[N], c[N];
int n, m, q;

int query() {
	int ans = 0;
	REPP(i, 1, n) {
		REPP(j, i + 1, n) if (col[i] ^ col[j]) {
			ans += mp[i][j];
		}
	}
	return ans;
}

int main() {
	ios :: sync_with_stdio(0);
	int t, ca = 1, x, y, z;
	cin >> t;
	while (t--) {
		cin >> n >> m >> q;
		REPP(i, 1, n) cin >> col[i];
		REPP(i, 1, n) REPP(j, 1, n) mp[i][j] = 0;
		REPP(i, 1, m) {
			cin >> x >> y >> z;
			a[i] = x, b[i] = y;
			mp[x][y] = mp[y][x] = z;
		}
		cout << "Case #" << ca++ << ":" << endl;
		while (q--) {
			int ty;
			cin >> ty;
			if (ty == 1) {
				cin >> x;
				col[x] ^= 1;
			}
			else if (ty == 2) {
				cin >> x >> y >> z;
				mp[x][y] = mp[y][x] = z;
			}
			else {
				cout << query() << endl;
			}
		}
	}

	return 0;
}

