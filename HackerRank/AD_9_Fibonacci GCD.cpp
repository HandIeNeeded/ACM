#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for(int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

LL gcd(LL a, LL b) {
	return b ? gcd(b, a % b) : a;
}

const int N = 200005;
const int SZ = 2;
const int MOD = 1e9 + 7;
LL a[N];

struct Matrix{
	int v[SZ][SZ];

	Matrix () {}
	Matrix (bool ident) {
		MST(v, 0);
		if (ident) {
			REP(i, SZ) v[i][i] = 1;
		}
	}
	
	int * operator [] (int i) {
		return v[i];
	}

	const int * operator [] (int i) const {
		return v[i];
	}
}func;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

Matrix operator * (const Matrix &a, const Matrix &b) {
	Matrix ans(0);
	REP(i, SZ) REP(j, SZ) REP(k, SZ) {
		add(ans[i][j], 1LL * a[i][k] * b[k][j] % MOD);
	}
	return ans;
}

Matrix quick_pow(Matrix a, LL b) {
	Matrix ans(1);
	while (b) {
		if (b & 1) {
			ans = ans * a;
		}
		b >>= 1;
		a = a * a;
	}
	return ans;
}

int fibnacci(LL x) {
	if (x <= 2) return 1;
	int tmp[SZ][SZ] = {
		0, 1,
		1, 1
	};
	REP(i, SZ) REP(j, SZ) func[i][j] = tmp[i][j];
	func = quick_pow(func, x - 1);
	return (func[0][0] + func[1][0]) % MOD;
}

int main(){
	int n;
	cin >> n;
	REPP(i, 1, n) {
		cin >> a[i];
	}
	LL ans = 0;
	REPP(i, 1, n) {
		ans = gcd(ans, a[i]);
	}
//	cout << ans << endl;
	cout << fibnacci(ans) << endl;
	
	return 0;
}

