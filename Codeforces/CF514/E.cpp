#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 101;
const int MO = 1e9 + 7;

struct Matrix {
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
	if (x >= MO) x -= MO;
}

Matrix operator * (const Matrix &a, const Matrix &b) {
	Matrix c;
	REP(i, N) REP(j, N) REP(k, N) {
		add(c[i][j], 1LL * a[i][k] * b[k][j] % MO);
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

int cnt[N];
int dp[N][N];

int main() {
	ios :: sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	REPP(i, 1, n) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	dp[0][0] = 1;
	REPP(i, 1, 100) {
		REPP(j, 1, 100) {
			REPP(k, 1, 100) {
				if (j >= k && cnt[k]) {
					add(dp[i][j], 1LL * dp[i - 1][j - k] * cnt[k] % MO);
				}
			}
		}
	}
	Matrix ans(0), fun;
	REPP(j, 1, 100) {
		REPP(k, 1, 100) {
			add(ans[0][k - 1], dp[j][k]);
		}
	}
	ans[0][100] = 1;
	REP(i, 100) add(ans[0][100], ans[0][i]);
	REP(i, 99) {
		fun[i + 1][i] = 1;
	}
	REP(i, 100) {
		fun[i][99] = fun[i][100] = cnt[100 - i];
	}
	fun[100][100] = 1;
	//REP(i, 101) {
	//	REP(j, 101) {
	//		cout << fun[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	if (m == 0) {
		cout << 1 << endl;
	}
	else if (m < 100) {
		int res = 1;
		REP(i, m) add(res, ans[0][i]);
		cout << res << endl;
	}
	else {
		int res = (ans * pow_mod(fun, m - 100))[0][100];
		cout << res << endl;
	}

	return 0;
}

