#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
const int MO = 1e9 + 7;
string s;
int fac[N], inv[N];
int a[4], b[4];

int pow_mod(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1LL * ans * x % MO;
		y >>= 1;
		x = 1LL * x * x % MO;
	}
	return ans;
}

int main() {
	ios :: sync_with_stdio(0);
	fac[0] = inv[0] = 1;
	REPP(i, 1, N - 1) fac[i] = 1LL * i * fac[i - 1] % MO;
	int n;
	cin >> n >> s;
	REP(i, s.size()) {
		if (s[i] == 'A') a[0]++;
		else if (s[i] == 'G') a[1]++;
		else if (s[i] == 'T') a[2]++;
		else a[3]++;
	}
	sort(a, a + 4);
	int cnt = 0;
	REP(i, 4) if (a[i] == a[3]) cnt++;
	cout << pow_mod(cnt, n) << endl;

	return 0;
}

