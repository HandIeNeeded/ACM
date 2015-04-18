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

const int N = 1005;
int a[N];

int main() {
	ios :: sync_with_stdio(0);
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int t, ca = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		REPP(i, 1, n) cin >> a[i];
		int ansa = 0, ansb = 0;
		REPP(i, 1, n - 1) {
			if (a[i] > a[i + 1]) {
				ansa += a[i] - a[i + 1];
			}
		}
		int eat = 0;
		REPP(i, 1, n - 1) {
			eat = max(eat, a[i] - a[i + 1]);
		}
		REPP(i, 1, n - 1) {
			ansb += min(a[i], eat);
		}
		cout << "Case #" << ca++ << ": " <<  ansa << ' ' << ansb << endl;
	}

	return 0;
}

