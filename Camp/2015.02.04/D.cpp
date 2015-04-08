#include <bits/stdc++.h>

#define REP(i, a) for(int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for(int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 200005;

int mx[N << 2];
int ql, qr, qd, qx;

void update(int x, int l, int r) {
	if (l == r) {
		mx[x] = qd;
	}
	else {
		if (qx <= MID) update(LC);
		else update(RC);
		mx[x] = max(mx[L], mx[R]);
	}
}

int query(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		return mx[x];
	}
	else {
		int ans = -1;
		if (ql <= MID) ans = max(ans, query(LC));
		if (qr > MID) ans = max(ans, query(RC));
		return ans;
	}
}

pair<pair<int, int>, int> p[N << 2];
int tot;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	if (a.first.first == b.first.first && a.second == b.second) {
		return a.first.second < b.first.second;
	}
	else if (a.first.first == b.first.first) {
		return a.second < b.second;
	}
	else {
		return a.first.first < b.first.first;
	}
}

int main() {
	ios :: sync_with_stdio(0);

	int n;
	cin >> n;
	string str;
	REPP(i, 1, n) {
		int a, b;
		cin >> str >> a >> b;
		if (str[0] == 'A') {
			int x = a;
			int y = i - 1 - x;
			if (x >= 0 && y >= 0) {
				x++, y++;
				p[tot++] = {{x, y}, str[0] == 'A'};
			}
			x = b;
			y = i - 1 - x;
			if (x >= 0 && y >= 0) {
				x++, y++;
				p[tot++] = {{x, y}, str[0] == 'A'};
			}
		}
		else {
			int y = a;
			int x = i - 1 - y;
			if (x >= 0 && y >= 0) {
				x++, y++;
				p[tot++] = {{x, y}, str[0] == 'A'};
			}
			y = b;
			x = i - 1 - y;
			if (x >= 0 && y >= 0) {
				x++, y++;
				p[tot++] = {{x, y}, str[0] == 'A'};
			}
		}
	}
	sort(p, p + tot, cmp);
	//REP(i, tot) {
	//	cout << p[i].first.first << ' ' << p[i].first.second << ' ' << p[i].second << endl;
	//}
	n += 10;
	int ans = 0;
	REP(i, tot) {
		ql = 1, qr = p[i].first.second;
		int val = 0;
		if (ql <= qr) {
			val = query(1, 1, n);
			ans = max(ans, val + 1);
		}
		if (p[i].second) {
			qx = p[i].first.second;
			qd = val + 1;
			update(1, 1, n);
		}
		else {
			qx = p[i].first.second + 1;
			qd = val + 1;
			update(1, 1, n);
		}
	}
	cout << ans << endl;

	return 0;
}
