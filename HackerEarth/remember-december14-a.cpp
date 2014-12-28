#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0;i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 205;
char mp[N][N];

void print(int x) {
	MST(mp, 0);
	REPP(i, 1, 2 * x) {
		REPP(j, 1, 2 * x + 2) {
			mp[i][j] = ' ';
		}
	}
	REPP(i, 1, x) {
		int a = x, b = 2 * i - 1;
		while (b <= x) {
			mp[a][b] = '/';
			a--;
			b++;
		}
	}
	REPP(i, 1, x) {
		REPP(j, x + 1, 2 * x) {
			if (mp[i][2 * x + 1 - j] == '/') {
				mp[i][j] = '\\';
			}
		}
	}
	REPP(i, x + 1, 2 * x) {
		REPP(j, 1, 2 * x) {
			if (mp[2 * x + 1 - i][j] != ' ') {
				mp[i][j + 2] = '\\' + '/' - mp[2 * x + 1 - i][j];
			}
		}
	}
	REPP(i, 1, 2 * x) {
		int y = 2 * x + 2;
		while (mp[i][y] == ' ') mp[i][y] = 0, y--;
		cout << mp[i] + 1 << endl;
	}
}

int main() {
	ios :: sync_with_stdio(0);

	int n;
	cin >> n;
	print(n);
	print(n + 1);	

	return 0;
}


