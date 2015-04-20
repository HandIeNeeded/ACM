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

const int N = 1e6 + 5;
const int MO = 1e9 + 7;

char t[N];
int f[N], vis[N], lt, a[N];
int pw[N] = {1};

void getfail(){
	int i, j;
	f[0] = f[1] = 0;
	for (i = 1; i < lt; ++i){
		j = f[i];
		while (j && t[j] != t[i]) j = f[j];
		f[i + 1] = t[j] == t[i] ? j + 1 : 0; 
	}
}

int main() {
	ios :: sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	cin >> t;
	REPP(i, 1, n) pw[i] = 1LL * 26 * pw[i - 1] % MO;
	REPP(i, 1, m) cin >> a[i];
	lt = strlen(t);
	getfail();
	int tmp = lt;
	vis[tmp] = 1;
	while (tmp) tmp = f[tmp], vis[tmp] = 1;
	a[m + 1] = n + 1;
	int ans = pw[a[1] - 1];
	REPP(i, 1, m) {
		int dis = a[i + 1] - (a[i] + lt);
		if (dis >= 0) ans = 1LL * ans * pw[dis] % MO;
		else {
			dis = -dis;
			if (!vis[dis]) ans = 0;
		}
	}
	cout << ans << endl; 
	return 0;
}

