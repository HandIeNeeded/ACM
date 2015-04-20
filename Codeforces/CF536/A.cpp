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

int A, B, q;

long long sum(int l, int r) {
	long long a = A + 1LL * (l - 1) * B, b = A + 1LL * (r - 1) * B;
	return 1LL * (a + b) * (r - l + 1) >> 1;
}

int main() {
	ios :: sync_with_stdio(0);
	cin >> A >> B >> q;
	while (q--) {
		int l, t, m;
		cin >> l >> t >> m;
		if (A + 1LL * (l - 1) * B > t) {
			cout << -1 << endl;
			continue;
		}
		int lo = -1, hi = int(1e6 + 5);
		while (lo + 1 < hi) {
			int mid = (lo + hi) >> 1;
			if (sum(l, l + mid - 1) <= 1LL * t * m && A + 1LL * (l + mid - 2) * B <= t) lo = mid;
			else hi = mid;
		}
		cout << l + lo - 1 << endl;
	}


	return 0;
}

