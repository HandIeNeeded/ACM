#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

const int N = (int) (2e5 + 5) << 2;
const int INF = 0x7fffffff;
int mi[N], mx[N], tmi[N], tmx[N], tadd[N], a[N];
int ql, qr, qd, ansl, ansr, ty;

void maintain(int x, int l, int r) {
	mi[x] = min(mi[L], mi[R]);
	mx[x] = max(mx[L], mx[R]);
}

void build(int x, int l, int r) {
	if (l == r) {
		mi[x] = mx[x] = a[l];
		tmi[x] = tmx[x] = tadd[x] = INF;
	}
	else {
		build(LC), build(RC);
		maintain(x, l, r);
		tmi[x] = tmx[x] = tadd[x] = INF;
	}
}

void push_add(int x, int l, int r) {
	
}

void push_min(int x, int l, int r) {

}

void push_max(int x, int l, int r) {

}

void push(int x, int l, int r) {
	if (tadd[x] != INF) {
		push_add(x, l, r);
	}
	if (tmi[x] != INF) {
		push_min(x, l, r);
	}
	if (tmx[x] != INF) {
		push_max(x, l, r);
	}
}

void query(int x, int l, int r) {

}

void update_min(int x, int l, int r) {

}

void update_max(int x, int l, int r) {

}

void modify(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		if (l != r) push(x, l, r);
		mi[x] += qd, mx[x] += qd;
	}
	else {
		push(x, l, r);
		if (ql <= MID) modify(LC);
		if (qr > MID) modify(RC);
		maintain(x, l, r);
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	REPP(i, 1, n) scanf("%d", a + i);
	build(1, 1, n);
	REPP(i, 1, m) {
		scanf("%d%d%d", &ty, &ql, &qr);
		if (ty <= 3) {
			scanf("%d", &qd);
			if (ty == 1) {
				modify(1, 1, n);
			}
			else if (ty == 2) {
				update_min(1, 1, n);
			}
			else {
				update_max(1, 1, n);
			}
		}
		else {
			ansl = INF, ansr = -INF;
			query(1, 1, n);
			cout << ansl << ' ' << ansr << endl;
		}
	}
	return 0;
}
