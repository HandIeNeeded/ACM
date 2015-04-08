#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

string rr, cc;
const int N = 105;
int mp[N][N];
int row[N], col[N];

int cal(int x, int y) {
	return !x || y;
}

int go(int x, int y) {
	return !(x && y);
}

int main() {
	ios :: sync_with_stdio(0);

	int n, m, q;
	cin >> n >> m >> q;
	cin >> rr >> cc;
	REP(i, n) row[i + 1] = 1 - (rr[i] - '0');
	REP(i, m) col[i + 1] = 1 - (cc[i] - '0');

	mp[1][1] = row[1] || col[1];
	REPP(i, 2, n) mp[1][i] = cal(mp[1][i - 1], row[i]);
	REPP(i, 2, m) mp[i][1] = cal(mp[i - 1][1], col[i]);

	REPP(i, 2, m) {
		REPP(j, 2, n) {
			mp[i][j] = go(mp[i - 1][j], mp[i][j - 1]);
		}
	}
	//REPP(i, 1, m) {
	//	REPP(j, 1, n) {
	//		cout << mp[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (mp[y][x]) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}
