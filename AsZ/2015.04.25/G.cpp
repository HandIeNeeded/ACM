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

const int N = 1000;
char mp[N][N];
const int sx = 500, sy = 500;

void init() {
	REP(i, 201) {
		char c = i % 3 ? 'w' : 'b';
		int nx = sx - i, ny = sy;
		REP(j, i + 1) {
			mp[nx][ny] = c;
			nx++, ny++;
		}
		nx = sx - i, ny = sy;
		REP(j, i + 1) {
			mp[nx][ny] = c;
			nx++, ny--;
		}
		nx = sx + i, ny = sy;
		REP(j, i + 1) {
			mp[nx][ny] = c;
			nx--, ny++;
		}
		nx = sx + i, ny = sy;
		REP(j, i + 1) {
			mp[nx][ny] = c;
			nx--, ny--;
		}
	}
}

int main() {
	ios :: sync_with_stdio(0);
	int t;
	init();
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = sx - n; i <= sx + n; i++) {
			for (int j = sy - n; j <= sy + n; j++) {
				cout << mp[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}

