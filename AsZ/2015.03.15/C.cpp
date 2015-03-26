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

pair<int, int> ans;

bool work(int n, int len) {
	n *= 2;
	if (n % len) return 0;
	else {
		int s = n / len;
		int b = (s + len - 1) / 2;
		int a = s - b;
		if (a > b) swap(a, b);
		if (1LL * (a + b) * (b - a + 1) == n) {
			ans = {a, b};
			return 1;
		}
		else return 0;
	}
}

int main() {
	ios :: sync_with_stdio(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 1) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		int len = int(sqrt(2.0 * n + 0.5)) + 1;
		bool find = 0;
		int tt = 2;
		while (tt <= len) {
			if (work(n, tt)) {
				find = 1;
				break;
			}
			tt++;
		}
		if (!find) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			cout << n << " = ";
			int now = ans.first;
			assert(now > 0);
			cout << now++;
			REPP(i, 2, tt) {
				cout << " + " << now++;
			}
			cout << endl;
		}
	}

	return 0;
}
