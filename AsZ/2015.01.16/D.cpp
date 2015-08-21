#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

int main() {
	ios :: sync_with_stdio(0);
	freopen("group.in", "r", stdin);

	int n, m;
	cin >> n >> m;
	int a = n - m;
	int b = 3 * (n - m - 1) + m / 2 * 3 + (m & 1);
	cout << a << ' ' << b << endl;

	return 0;
}

