#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2;
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

Matrix pow_mod(Matrix a, int n) {
	Matrix ans(1);
	while (n) {
		if (n & 1) ans = ans * a;
		n >>= 1;
		a = a * a;
	}
	return ans;
}

int main() {
	int a, b, n, t;
	cin >> t;
	while (t--) {
		cin >> a >> b >> n;
		if (n == 0) {
			cout << a << endl;
			continue;
		}
		else if (n == 1) {
			cout << b << endl;
			continue;
		}
		Matrix fun, start;
		start[0][0] = a, start[0][1] = b;
		fun[0][1] = fun[1][1] = fun[1][0] = 1;
		start = start * pow_mod(fun, n - 1);
		cout << start[0][1] << endl;
	}
	return 0;
}

