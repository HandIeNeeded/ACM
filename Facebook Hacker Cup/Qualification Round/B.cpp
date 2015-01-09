#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 25;
int a[3][N];

int main() {
	ios :: sync_with_stdio(0);
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int t, ca = 1;
	cin >> t;
	while (t--) {
		int n, x, y, z;
		cin >> x >> y >> z;
		cin >> n;
		REP(i, n) {
			REP(j, 3) {
				cin >> a[j][i];
			}
		}
		bool good = 0;
		REP(i, 1 << n) {
			int tx = 0, ty = 0, tz = 0;
			REP(j, n) {
				if (i & (1 << j)) {
					tx += a[0][j];
					ty += a[1][j];
					tz += a[2][j];
				}
			}
			if (tx == x && ty == y && tz == z) {
				good = 1;
				break;
			}
		}
		cout << "Case #" << ca++ << ": " << (good ? "yes" : "no") << endl;
	}
	return 0;
}

