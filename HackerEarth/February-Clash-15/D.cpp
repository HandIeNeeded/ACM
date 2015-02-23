#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 16;
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
};

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

Matrix operator * (const Matrix &a, const Matrix &b) {
	Matrix c;
	REP(i, N) REP(j, N) REP(k, N) {
		add(c[i][j], 1ll * a[i][k] * b[k][j] % MOD);
	}
	return c;
}

Matrix pow_mod(Matrix a, long long n) {
	Matrix ans(1);
	while (n) {
		if (n & 1) ans = ans * a;
		n >>= 1;
		a = a * a;
	}
	return ans;
}

int digit[4] = {2, 3, 5, 7};

Matrix init() {
	Matrix fun;
	REP(i, 16) {
		REP(j, 10) {
			int st = i;
			REP(k, 4) {
				if (j == digit[k]) {
					st ^= (1 << k);
				}
			}
			fun[i][st]++;
		}
	}
	return fun;
}

int main() {
	ios :: sync_with_stdio(0);
	int t;
	cin >> t;
	Matrix fun = init();
	while (t--) {
		long long n;
		int a, b, c, d;
		cin >> n >> a >> b >> c >> d;
		int st = 0;
		st |= (a * 1);
		st |= (b * 2);
		st |= (c * 4);
		st |= (d * 8);
		Matrix tmp = fun;
		Matrix ans;
		ans[0][0] = 6, ans[0][1] = 1, ans[0][2] = 1, ans[0][4] = 1, ans[0][8] = 1;
		ans = ans * pow_mod(tmp, n - 1);
		cout << ans[0][st] << endl;
	}

	return 0;
}
