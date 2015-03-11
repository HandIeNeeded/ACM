#include <bits/stdc++.h>
 
#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
 
#define L (x << 1)
#define R ((x << 1) | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r
 
using namespace std;
 
const int N = 1e5 + 5;
string str;
 
int a[N << 2][3], flag[N << 2];
int prefix[N];
int ql, qr, qd, qx;
 
void build(int x, int l, int r) {
	if (l == r) {
		MST(a[x], 0);
		a[x][prefix[l]] = 1;
		flag[x] = 0;
	}
	else {
		build(LC), build(RC);
		MST(a[x], 0);
		REP(i, 3) a[x][i] = a[L][i] + a[R][i];
		flag[x] = 0;
	}
}
 
void push(int x, int l, int r) {
	flag[L] += flag[x], flag[R] += flag[x];
	flag[L] %= 3, flag[R] %= 3;
	int tmp[3];
	REP(i, 3) {
		tmp[(i + flag[x]) % 3] = a[L][i];
	}
	REP(i, 3) {
		a[L][i] = tmp[i];
	}
	REP(i, 3) {
		tmp[(i + flag[x]) % 3] = a[R][i];
	}
	REP(i, 3) {
		a[R][i] = tmp[i];
	}
	flag[x] = 0;
}
 
void update(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		flag[x] += qd;
		flag[x] %= 3;
		int tmp[3];
		REP(i, 3) {
			tmp[(i + qd) % 3] = a[x][i];
		}
		REP(i, 3) a[x][i] = tmp[i];
	}
	else {
		if (flag[x]) {
			push(x, l, r);
		}
		if (ql <= MID) update(LC);
		if (qr > MID) update(RC);
		REP(i, 3) a[x][i] = a[L][i] + a[R][i];
	}
}
 
int q[3];
 
void query(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		REP(i, 3) q[i] += a[x][i];
	}
	else {
		if (flag[x]) {
			push(x, l, r);
		}
		if (ql <= MID) query(LC);
		if (qr > MID) query(RC);
	}
}
 
long long calc(int x) {
	return 1LL * x * (x - 1) / 2;
}
 
int main() {
	ios :: sync_with_stdio(0);
	//freopen("cf.in", "r", stdin);
 
	int n, m;
	cin >> n >> m;
	cin >> str;
	REPP(i, 1, n) prefix[i] = str[i - 1] - '0';
	REPP(i, 1, n) prefix[i] = (prefix[i - 1] + prefix[i]) % 3;
	build(1, 1, n);
	//REPP(i, 1, n) {
	//	cout << prefix[i] << ' ';
	//}
	//cout << endl;
	//REP(i, 3) {
	//	cout << a[1][i] << ' ';
	//}
	//cout << endl;
	while (m--) {
		int ty, x, y;
		cin >> ty >> x >> y;
		if (ty == 1) {
			qd = (y + 48 - str[x - 1]) % 3;
			str[x - 1] = y + 48;
			if (qd < 0) qd += 3;
			ql = x, qr = n;
			update(1, 1, n);
		}
		else {
			ql = x, qr = y;
			MST(q, 0);
			query(1, 1, n);
			long long ans = 0;
			//REP(i, 3) {
			//	cout << q[i] << ' ';
			//}
			//cout << endl;
			REP(i, 3) {
				ans += calc(q[i]);
			}
			int tmp[3];
			REP(i, 3) tmp[i] = q[i];
			MST(q, 0);
			if (x > 1) {
				ql = qr = x - 1;
				query(1, 1, n);
				REP(i, 3) if (q[i]) ans += tmp[i];
			}
			else ans += tmp[0];
			cout << ans << endl;
		}
	}
 
	return 0;
}
