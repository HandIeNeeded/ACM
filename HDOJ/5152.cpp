#include <cstring>
#include <iostream>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 50005;
const int MOD = 2333333;

int a[N], ql, qr, qx, qd;
int sum[N << 2], phi[19] = {MOD}, b[N][19];
long long val[N << 2];
bool flag[N << 2];

int euler(int x) {
	int ans = 1;
	for (int i = 2; i * i <= x; i ++){
		if (x % i == 0) {
			while (x % i == 0) {
				ans *= i;
				x /= i;
			}
			ans /= i;
			ans *= (i - 1);
		}
	}
	if (x > 1) {
		ans *= (x - 1);
	}
	return ans;
}

void add(int &x, int y, int id) {
	x += y;
	if (x >= phi[id]) x -= phi[id];
}

void maintain(int x, int l, int r) {
	sum[x] = sum[L];
	add(sum[x], sum[R], 0);
}

void build(int x, int l, int r) {
	if (l == r) {
		sum[x] = a[l] % MOD;
		flag[x] = false, val[x] = 0;
		REP(i, 19) {
			b[l][i] = a[l] % phi[i];
		}
	}
	else {
		build(LC), build(RC);
		flag[x] = false, val[x] = 0;
		maintain(x, l, r);
	}
}

void push(int x, int l, int r) {
	flag[L] = flag[R] = 1;
	val[L] += val[x], val[R] += val[x];
	if (l + 1 == r || l + 2 == r) {
		REP(i, 19) {
			if (l + 1 == r) add(b[l][i], val[x] % phi[i], i);
			add(b[r][i], val[x] % phi[i], i);
		}
	}
	val[x] %= MOD;
	add(sum[L], val[x] * (MID - l + 1) % MOD, 0);
	add(sum[R], val[x] * (r - MID) % MOD, 0); 
	flag[x] = false, val[x] = 0;
}

void update(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		flag[x] = 1;
		val[x] += qd;
		if (l == r) {
			REP(i, 19) {
				add(b[l][i], qd % phi[i], i);
			}
		}
		add(sum[x], 1LL * (r - l + 1) * qd % MOD, 0);
	}
	else {
		if (flag[x]) push(x, l, r);
		if (ql <= MID) update(LC);
		if (qr > MID) update(RC);
		maintain(x, l, r);
	}
}

int pow_mod(int x, int y, int MOD) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1LL * ans * x % MOD;
		y >>= 1;
		x = 1LL * x * x % MOD;
	}
	return ans;
}

void modify(int x, int l, int r) {
	if (l == r) {
		sum[x] = b[l][0] = pow_mod(2, b[l][1], phi[0]);
		REPP(i, 1, 18) {
			b[l][i] = pow_mod(2, b[l][i + 1], phi[i]);
		}
	}
	else {
		if (flag[x]) push(x, l, r);
		if (qx <= MID) modify(LC);
		else modify(RC);
		maintain(x, l, r);
	}
}

int qans;

void query(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		add(qans, sum[x], 0);
	}
	else {
		if (flag[x]) push(x, l, r);
		if (ql <= MID) query(LC);
		if (qr > MID) query(RC);
	}
}

int main() {
	REP(i, 18) {
		phi[i + 1] = euler(phi[i]); 
	}
	int n, m;
	while (scanf("%d%d", &n, &m) > 0) {
		REPP(i, 1, n) scanf("%d", a + i);
		build(1, 1, n);
		while (m--) {
			int ty;
			scanf("%d", &ty);
			if (ty == 1) {
				scanf("%d%d", &ql, &qr);
				qans = 0;
				query(1, 1, n);
				printf("%d\n", qans);
			}
			else if (ty == 2) {
				scanf("%d", &qx);
				modify(1, 1, n);
			}
			else if (ty == 3) {
				scanf("%d%d%d", &ql, &qr, &qd);
				update(1, 1, n);
			}
		}
	}
	return 0;
}

