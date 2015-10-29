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
bool vis[N];

int main() {
	ios :: sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	bool bad = 0;
	REPP(i, 1, m) {
		int x, y;
		cin >> x >> y;
		if (x > y) bad = 1;
		if (x == y - 1) vis[x] = 1;
	}
	REPP(i, 1, n - 1) {
		if (!vis[i]) bad = 1;
	}
	if (bad) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}

	return 0;
}

