#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

int main() {
	ios :: sync_with_stdio(0);
	int t;
	cin >> t;
	REPP(i, 1, t) {
		int a, b;
		cin >> a >> b;
		if (a % 3 == 0 || b % 3 == 0) {
			cout << "YES" << endl;
		}
		else if (a == 2) {
			cout << "NO" << ' ' << 2 * (b % 3) << endl;
		}
		else if (b == 2) {
			cout << "NO" << ' ' << 2 * (a % 3) << endl;
		}
		else {
			a %= 3, b %= 3;
			cout << "NO" << ' ' << a * b % 3 << endl;
		}
	}

	return 0;
}

