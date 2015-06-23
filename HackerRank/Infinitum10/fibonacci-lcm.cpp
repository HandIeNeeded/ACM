#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2;
const int MO = 1e9 + 7;
vector<int> a;

int pow_mod(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = 1LL * ans * a % MO;
		b >>= 1;
		a = 1LL * a * a % MO;
	}
	return ans;
}

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
}start, fun;

void init() {
	int tmp[2][2] = {
		0, 1,
		1, 1
	};
	REP(i, N) REP(j, N) fun[i][j] = tmp[i][j];
	start[0][0] = start[0][1] = 1;
}

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

int calc(int x) {
	if (x <= 2) return 1;
	Matrix now = start;
	now = now * pow_mod(fun, x - 2);
	return now[0][1];
}

map<vector<int>, int> mp;

int solve(vector<int> &a) {
	if (mp.count(a)) {
		return mp[a];
	}
	if (a.size() == 1) {
		return mp[a] = calc(a[0]);
	}
	else {
		vector<int> tmp = a;
		tmp.pop_back();
		int res = solve(tmp);
		tmp.clear();
		REP(i, a.size() - 1) {
			tmp.push_back(__gcd(a[i], a.back()));
		}
		int inv = solve(tmp);
		int ans = 1LL * res * calc(a.back()) % MO;
		ans = 1LL * ans * pow_mod(inv, MO - 2) % MO;
		return mp[a] = ans;
	}
}

int main() {
	ios :: sync_with_stdio(0);
	init();
	int n;
	cin >> n;
	REPP(i, 1, n) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	cout << solve(a) << endl;
	return 0;
}
