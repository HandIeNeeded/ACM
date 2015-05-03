#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;

int a[N], pos[N];

int main() {
	ios :: sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	REPP(i, 1, n) cin >> a[i], pos[a[i]] = i;
	for (int i = 1, j = n; i <= n && k; i++, j--) {
		if (pos[j] == i) {
			continue;
		}
		else {
			k--;
			int x = a[i], y = j;
			swap(a[i], a[pos[j]]);
			swap(pos[x], pos[y]);
		}
	}
	REPP(i, 1, n) {
		cout << a[i] << " \n"[i == n];
	}

	return 0;
}

