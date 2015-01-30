#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 2e5 + 5;

int go[N], add[N], cost[N], sum[N << 2], mx[N << 2];
bool fl[N << 2];
int ql, qr, qx, qd, n, q;
int ans[N], tmp[N], pos[N], height[N];
pair<int, int> p[N];

bool cmp(const int &i, const int &j) {
	return p[i] > p[j];
}

void update1(int x, int l, int r) {
	if (l == r) {
		mx[x] = qd;
	}
	else {
		if (qx <= MID) update1(LC);
		if (qx > MID) update1(RC);
		mx[x] = max(mx[L], mx[R]);
	}
}

int query1(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		return mx[x];
	}
	else {
		int ans = 0;
		if (ql <= MID) ans = max(ans, query1(LC));
		if (qr > MID) ans = max(ans, query1(RC));
		return ans;
	}
}

void push(int x, int l, int r) {
	sum[L] = sum[R] = 0;
	fl[L] = fl[R] = 1;
	fl[x] = 0;
}

void modify(int x, int l, int r) {
	if (l == r) {
		sum[x] = qd;
	}
	else {
		if (fl[x]) push(x, l, r); 
		if (qx <= MID) modify(LC);
		else modify(RC);
		sum[x] = sum[L] + sum[R];
	}
}

void update(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		fl[x] = 1;
		sum[x] = 0;
	}
	else {
		if (fl[x]) {
			push(x, l, r);
		}
		if (ql <= MID) update(LC);
		if (qr > MID) update(RC);
		sum[x] = sum[L] + sum[R];
	}
}

int query(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		return sum[x];
	}
	int ans = 0;
	if (fl[x]) push(x, l, r);
	if (ql <= MID) ans += query(LC);
	if (qr > MID) ans += query(RC);
	return ans;
}

void getans() {
	int now = n;
	REP(i, q) {
		int l = p[i].first, r = p[i].second;
		while (now >= l) {
			int tmp = upper_bound(pos + 1, pos + n + 1, pos[now] + height[now]) - pos;
			go[now] = pos[now] + height[now];
			ql = now, qr = tmp - 1;
			if (qr >= ql) {
				go[now] = max(go[now], query1(1, 1, n));
				qx = now, qd = go[now];
				update1(1, 1, n);
			}
			tmp = upper_bound(pos + 1, pos + n + 1, go[now]) - pos;
			ql = now, qr = tmp - 1;
			update(1, 1, n);
			if (tmp <= n) {
				qx = tmp, qd = pos[tmp] - go[now];
				modify(1, 1, n);
			}
			now--;
		}
		int tmp_pos = upper_bound(pos + 1, pos + n + 1, go[l]) - pos;
		if (tmp_pos - 1 >= r) {
			ans[tmp[i]] = 0;
		}
		else {
			int &res = ans[tmp[i]];
			ql = tmp_pos, qr = r;
			res += query(1, 1, n);
		}
	}
}


int main() {
	ios :: sync_with_stdio(0);
	cin >> n;
	REPP(i, 1, n) {
		cin >> pos[i] >> height[i];
	}
	cin >> q;
	REP(i, q) {
		cin >> p[i].first >> p[i].second;
	}
	REP(i, q) tmp[i] = i;
	sort(tmp, tmp + q, cmp);
	sort(p, p + q);
	reverse(p, p + q);
	getans();
	REP(i, q) cout << ans[i] << endl;

	return 0;
}
