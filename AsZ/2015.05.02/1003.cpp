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

const int N = 1e5 + 5;
int A[N], B[N];

int main() {
	ios :: sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		REP(i, m) cin >> A[i];
		REP(i, m) cin >> B[i];
		sort(A, A + m), sort(B, B + m);
		int bad = 0;
		REP(i, m) if (A[i] > B[i]) {
			bad = 1;
		}
		if (bad) {
			cout << "Stupid BrotherK!" << endl;
			continue;
		}
		else {
			int ans = max(n - B[m - 1], A[0] - 1);
			REPP(i, 1, m - 1) ans = max(ans, A[i] - B[i - 1] - 1);
			cout << fixed << setprecision(6) << 1.0 * ans << endl;
		}
	}

	return 0;
}

