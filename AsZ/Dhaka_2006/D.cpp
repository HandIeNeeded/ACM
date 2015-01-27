#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

#define L (x << 1)
#define R ((x << 1) | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 200005;

int sum[N << 2], a[N];
int ql, qr, qx, qd;

void build(int x, int l, int r) {
	if (l == r) {
		sum[x] = a[l];
	}
	else {
		build(LC), build(RC);
		sum[x] = sum[L] + sum[R];
	}
}

void update(int x, int l, int r) {
	if (l == r) {
		sum[x] = qd;
	}
	else {
		if (qx <= MID) update(LC);
		else update(RC);
		sum[x] = sum[L] + sum[R];
	}
}

int query(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		return sum[x];
	}
	else {
		int ans = 0;
		if (ql <= MID) ans += query(LC);
		if (qr > MID) ans += query(RC);
		return ans;
	}
}

int main() {
	int n;
	ios :: sync_with_stdio(0);
	int ca = 1;
	while (cin >> n, n) {
		if (ca > 1) cout << endl;
		REPP(i, 1, n) cin >> a[i];
		build(1, 1, n);
		cout << "Case " << ca++ << ":" << endl;
		string ty;
		while (cin >> ty) {
			if (ty[0] == 'E') {
				break;
			}
			else {
				if (ty[0] == 'M') {
					cin >> ql >> qr;
					cout << query(1, 1, n) << endl;
				}
				else {
					cin >> qx >> qd;
					update(1, 1, n);
				}
			}
		}
	}


	return 0;
}
