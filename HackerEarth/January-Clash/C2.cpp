#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 17;
const int MOD = 1e9 + 7;

struct Matrix{
	int a[N][N];

	Matrix (bool ident = 0) {
		MST(a, 0);
		if (ident) {
			REP(i, N) a[i][i] = 1;
		}
	}

	int* operator [] (int i){
		return a[i];
	}

	const int* operator [] (int i) const {
		return a[i];
	}
}fun;

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

Matrix operator * (const Matrix &a, const Matrix &b) {
	Matrix c;
	REP(i, N) REP(j, N) REP(k, N) {
		add(c[i][j], 1LL * a[i][k] * b[k][j] % MOD);
	}
	return c;
}

Matrix quick_pow(Matrix a, long long n) {
	Matrix ans(1);
	while (n) {
		if (n & 1) ans = ans * a;
		n >>= 1;
		a = a * a;
	}
	return ans;
}

const int num[4] = {2, 3, 5, 7};
int start[N];

void init() {
	REP(i, 1 << 4) {
		REPP(j, 1, 9) {
			int now = i;
			REP(k, 4) {
				int cnt = 0;
				int jj = j;
				while (jj % num[k] == 0) {
					jj /= num[k];
					cnt ^= 1;
				}
				now ^= (cnt << k);
			}
			fun[i][now]++;
		}
	}
	fun[0][16] = fun[16][16] = 1;
	REPP(j, 1, 9) {
		int now = 0;
		REP(k, 4) {
			int cnt = 0;
			int jj = j;
			while (jj % num[k] == 0) {
				jj /= num[k];
				cnt ^= 1;
			}
			now ^= (cnt << k);
		}
		start[now]++;
	}
}

long long n;

int pow_mod(int x, long long y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1LL * ans * x % MOD;
		y >>= 1;
		x = 1LL * x * x % MOD;
	}
	return ans;
}

int solve(long long n) {
	Matrix func = fun, ans;
	memcpy(ans[0], start, sizeof(start));
	ans = ans * quick_pow(func, n);
	//REP(i, N) {
	//	REP(j, N) {
	//		cout << ans[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	int res = ans[0][16];
	add(res, pow_mod(10, n));
	int tmp = 9LL * (pow_mod(9, n) - 1) % MOD;
	tmp = 1LL * tmp * pow_mod(8, MOD - 2) % MOD;
	add(res, MOD - tmp);
	return res;
}

int main() {
	ios :: sync_with_stdio(0);
	int t;
	cin >> t;
	init();
	while (t--) {
		cin >> n;
		cout << solve(n) << endl;
	}

	return 0;
}

