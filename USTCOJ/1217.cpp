#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 105;
const LL INF = 0x3f3f3f3f3f3f3f3f;

struct Matrix{
	LL a[N][N];

	Matrix (bool ident = 0) {
		MST(a, 0x3f);
	}

	LL * operator [] (int i){
		return a[i];
	}

	const LL * operator [] (int i) const {
		return a[i];
	}
};

LL mul(const LL &a, const LL &b) {
	if (a == INF || b == INF) return INF;
	return a + b;
}

LL add(const LL &a, const LL &b) {
	return min(a, b);
}

Matrix mul(const Matrix &a, const Matrix &b, int N) {
	Matrix c;
	REPP(i, 1, N) REPP(j, 1, N) REPP(k, 1, N) {
		c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
	}
	return c;
}

Matrix pow_mod(Matrix a, int n, int N) {
	Matrix ans;
	int flag = 0;
	while (n) {
		if (n & 1){
			if (!flag) flag = 1, ans = a;
			else ans = mul(ans, a, N);
		}
		n >>= 1;
		a = mul(a, a, N);
	}
	return ans;
}

int main() {
	ios :: sync_with_stdio(0);
	
	int n, m, k;
	int start, end;
	while (cin >> n >> m >> k, n | m | k) {
		cin >> start >> end;
		Matrix fun;
		int a, b, c;
		REP(i, m) {
			cin >> a >> b >> c;
			fun[a][b] = c;
		}
		Matrix ans = pow_mod(fun, k, n);
		
		if (ans[start][end] == INF) {
			cout << "None" << endl;
		}
		else {
			cout << ans[start][end] << endl;
		}
	}
	return 0;
}


