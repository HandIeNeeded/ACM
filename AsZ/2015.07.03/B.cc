#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 105;
const int MO = 175781251;
const int inv2 = (MO + 1) / 2;
int f[N][N], c[N][N], pw[N], g[N];

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}

int pow_mod(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = 1LL * ans * a % MO;
		b >>= 1;
		a = 1LL * a * a % MO;
	}
	return ans;
}

void init() {
	REPP(i, 0, N - 1) c[i][0] = c[i][i] = 1;
	REPP(i, 1, N - 1) {
		REPP(j, 1, i - 1) {
			c[i][j] = c[i - 1][j - 1];
			add(c[i][j], c[i - 1][j]);
		}
	}
	pw[0] = g[0] = 1;
	REPP(i, 1, N - 1) pw[i] = (pw[i - 1] << 1) % MO, g[i] = g[i - 1] * 3 % MO;
	//REPP(tot, 3, 100) {
	//	f[1][tot - 1] = pw[tot - 1];
	//	REPP(left, 2, tot / 2) {
	//		int right = tot - left;
	//		f[left][right] = 1LL * (g[right] - 1) * f[left - 1][right] % MO;
	//		REPP(have, 1, right - 1) {
	//			int tmp = 1LL * pw[have] * g[right - have] % MO * f[left - 1][right] % MO;
	//			add(f[left][right], tmp);
	//		}
	//	}
	//}
	REPP(left, 1, 100) {
		f[left][1] = pw[left];
		REPP(right, 2, 100) {
			int &ans = f[left][right];
			ans = pow_mod(g[right] - 1, left);
			for (int i = right - 1, j = 1; i >= 1; i--, j++) {
				if (j & 1) {
					add(ans, MO - 1LL * c[right][i] * pow_mod(g[i] - 1, left) % MO);
				}
				else {
					add(ans, 1LL * c[right][i] * pow_mod(g[i] - 1, left) % MO);
				}
			}
		}
	}
}

int solve(int n) {
	if (n == 1) return 1;
	else if (n == 2) return 3;
	else {
		int ans = 0;
		REPP(i, 0, n - 2) {//alone
			int tot = n - i;//tot node had edge
			REPP(left, 1, tot / 2) {
				int right = tot - left;//left right
				int tmp = 1LL * c[n][tot] * c[tot][left] % MO;
				if (left == right) {
					tmp = 1LL * tmp * pow_mod(2, MO - 2) % MO;
				}
				tmp = 1LL * tmp * f[left][right] % MO;
				add(ans, tmp);
			}
		}
		add(ans, 1);//no edge
		return ans;
	}
}

int main() {
    ios :: sync_with_stdio(0);
	freopen("bipartite.in", "r", stdin);
	freopen("bipartite.out", "w", stdout);
	init();
	int n;
	while (cin >> n, n) {
		cout << solve(n) << endl;
	}
    return 0;
}

