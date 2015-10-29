#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

int main() {
    ios :: sync_with_stdio(0);
	int n, k1, k2, p1, p2, p3;
	cin >> n >> k1 >> k2 >> p1 >> p2 >> p3;
	if (n < p1) {
		cout << 0 << endl;
	}
	else {
		int ans = k1;
		n -= p1;
		int tot = 0;
		while (n > 0 && tot < k2) {
			ans++, tot++;
			n -= p2;
		}
		if (n > 0) ans += (n + p3 - 1) / p3;
		cout << ans << endl;
	}

    return 0;
}

