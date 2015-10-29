#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

int a[7];
string s;

int main() {
    ios :: sync_with_stdio(0);
	REP(i, 7) cin >> a[i];
	cin >> s;
	int ans = 0;
	if (a[0] > 0) {
		while (a[0]) {
			ans += 8;
			a[0]--;
		}
		ans += 27;
		if (s == "RED") {
			ans += 7;
		}
	}
	else {
		if (s == "RED") {
			ans = 34;
		}
		else {
			REP(i, 7) {
				ans += (i + 1) * a[i];
			}
		}
	}
	cout << ans << endl;

    return 0;
}

