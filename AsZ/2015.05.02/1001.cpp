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
#define uint unsigned int

using namespace std;

const int N = 1e7 + 5;
uint L[N], R[N];
string str[2] = {"NO", "YES"};

bool good(int x, int y) {
	if (L[x] > L[y]) {
		swap(x, y);
	}
	return R[x] < L[y];
}

bool use[N];

int main() {
	ios :: sync_with_stdio(0);
	int t;
	cin >> t;
	REPP(ca, 1, t) {
		int n;
		uint a, b, c, d;
		cin >> n >> L[1] >> R[1] >> a >> b >> c >> d;
		int bad = 0;
		REPP(i, 1, n) use[i] = 0;
		REPP(i, 2, n) {
			L[i] = L[i - 1] * a + b;
			R[i] = R[i - 1] * c + d;
		}
		REPP(i, 1, n) {
			if (L[i] > R[i]) {
				swap(L[i], R[i]);
			}
		}
		uint mir = -1, id = -1;
		REPP(i, 1, n) {
			if (!use[i] && R[i] < mir) {
				mir = R[i];
				id = i;
			}
		}
		use[id] = 1;
		uint mirr = -1;
		id = -1;
		REPP(i, 1, n) {
			if (!use[i] && R[i] < mirr && L[i] > mir) {
				mirr = R[i];
				id = i;
			}
		}
		if (id == -1) {
			bad = 1;
		}
		uint mirrr = -1;
		id = -1;
		REPP(i, 1, n) {
			if (!use[i] && R[i] < mirrr && L[i] > mirr) {
				mirrr = R[i];
				id = i;
			}
		}
		if (id == -1) bad = 1;
		cout << (bad ? "NO" : "YES") << endl;
	}

	return 0;
}

