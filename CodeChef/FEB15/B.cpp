#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
int cnt[N];

int main() {
	ios :: sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int x, n;
		cin >> n;
		REPP(i, 1, n) {
			cin >> x;
			cnt[x]++;
		}
		int mx = 0;
		REPP(i, 1, N - 1) mx = max(mx, cnt[i]);
		cout << n - mx << endl;
		MST(cnt, 0);
	}

	return 0;
}
