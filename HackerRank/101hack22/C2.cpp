#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <deque>
#include <bitset>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cassert>
#include <cmath>

#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;
int a[2][N], b[N], pos[N];
deque<int> q;

int main() {
	ios :: sync_with_stdio(0);
	int n;
	cin >> n;
	REP(j, 2) {
		REPP(i, 1, n) cin >> a[j][i];
	}
	REPP(i, 1, n) {
		pos[a[0][i]] = i;
	}
	REPP(i, 1, n) {
		b[i] = pos[a[1][i]];
	}
	REPP(i, 1, n) {
		int pos = upper_bound(q.begin(), q.end(), b[i]) - q.begin();
		if (pos == 0) {
			q.push_front(b[i]);
		}
		else {
			q[pos - 1] = b[i];
		}
	}
	cout << q.size() << endl;

	return 0;
}
