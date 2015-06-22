#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 1e5 + 5;
const int MO = 1e9 + 9;
const int K = 180;

int cnt[N][N / K + 5];
int mp[N][N / K + 5], g[N / K + 5][N / K + 5];//mp, g -- the number of common numbers
vector<int> a[N], b[N / K + 5];
int ty[N], Id[N];
int Small, Large, n, m, q;
int s[N << 2], flag[N << 2];
int addupStoL[N / K + 5], addupLtoL[N / K + 5], addupRtoL[N / K + 5];
int modifyL[N / K + 5];

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}

void init() {
	REP(i, Large) {
		REP(j, b[i].size()) {
			cnt[b[i][j]][i]++;
		}
	}
	REP(i, Large) {
		REP(k, b[i].size()) {
			REP(j, Large) {
				g[i][j] += cnt[b[i][k]][j];
			}
		}
	}
	REP(i, Small) {
		REP(k, a[i].size()) {
			REP(j, Large) {
				mp[i][j] += cnt[a[i][k]][j];
			}
		}
	}
}

void push(int x, int l, int r) {
	add(s[L], 1LL * (MID - l + 1) * flag[x] % MO);
	add(s[R], 1LL * (r - MID) * flag[x] % MO);
	add(flag[L], flag[x]), add(flag[R], flag[x]);
	flag[x] = 0;
}

//single
void update(int x, int l, int r, int qx, int qd) {
	if (l == r) {
		add(s[x], qd);
	}
	else {
		if (flag[x]) push(x, l, r);
		if (qx <= MID) update(LC, qx, qd);
		else update(RC, qx, qd);
		s[x] = s[L], add(s[x], s[R]);
	}
}

//range
void Update(int x, int l, int r, int ql, int qr, int qd) {
	if (ql <= l && qr >= r) {
		add(s[x], 1LL * (r - l + 1) * qd % MO);
		add(flag[x], qd);
	}
	else {
		if (flag[x]) push(x, l, r);
		if (ql <= MID) Update(LC, ql, qr, qd);
		if (qr > MID) Update(RC, ql, qr, qd);
		s[x] = s[L], add(s[x], s[R]);
	}
}

int query(int x, int l, int r, int ql, int qr) {
	if (ql <= l && qr >= r) {
		return s[x];
	}
	else {
		if (flag[x]) push(x, l, r);
		int ans = 0;
		if (ql <= MID) add(ans, query(LC, ql, qr));
		if (qr > MID) add(ans, query(RC, ql, qr));
		return ans;
	}
}

void modify1(int id, int num) {
	if (ty[id] == 0) {
		id = Id[id];
		REP(i, a[id].size()) {
			update(1, 1, n, a[id][i], num);
		}
		REP(i, Large) {
			add(addupStoL[i], 1LL * num * mp[id][i] % MO);
		}
	}
	else {
		id = Id[id];
		add(modifyL[id], num);
		REP(i, Large) {
			add(addupLtoL[i], 1LL * num * g[id][i] % MO);
		}
	}
}

void modify2(int l, int r, int num) {
	Update(1, 1, n, l, r, num);
	REP(i, Large) {
		int st = lower_bound(b[i].begin(), b[i].end(), l) - b[i].begin();
		int ed = upper_bound(b[i].begin(), b[i].end(), r) - b[i].begin();
		add(addupRtoL[i], 1LL * (ed - st) * num % MO);
	}
}

int query1(int id) {
	int ans = 0;
	if (ty[id] == 0) {
		id = Id[id];
		REP(i, a[id].size()) {
			add(ans, query(1, 1, n, a[id][i], a[id][i]));
		}
		REP(i, Large) {
			add(ans, 1LL * modifyL[i] * mp[id][i] % MO);
		}
	}
	else {
		id = Id[id];
		add(ans, addupStoL[id]);
		add(ans, addupRtoL[id]);
		add(ans, addupLtoL[id]);
	}
	return ans;
}

int query2(int l, int r) {
	int ans = query(1, 1, n, l, r);
	REP(i, Large) {
		int st = lower_bound(b[i].begin(), b[i].end(), l) - b[i].begin();
		int ed = upper_bound(b[i].begin(), b[i].end(), r) - b[i].begin();
		add(ans, 1LL * modifyL[i] * (ed - st) % MO);
	}
	return ans;
}

int in() {
	char c;
	while (c = getchar(), (c < '0' || c > '9') && (c != '-'));
	bool flag = (c == '-');
	if (flag) c = getchar();
	int x = 0;
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - 48;
		c = getchar();
	}
	return flag ? -x : x;
}

void out(int x) { //int
	if (x < 0) putchar('-'), x = -x;
	int len = 0, bit[10]; // LL  -> bit[20]
	while (x) {
		bit[len++] = x % 10;
		x /= 10;
	}
	if (!len) bit[len++] = 0;
	while (len--) putchar(bit[len] + 48);
	putchar('\n');
}

int main() {
	n = in(), m = in(), q = in();
	REPP(i, 1, m) {
		int tot = in();
		if (tot <= K) {
			ty[i] = 0, Id[i] = Small;
			REP(j, tot) {
				int tmp = in();
				a[Small].push_back(tmp);
			}
			sort(a[Small].begin(), a[Small].end());
			Small++;
		}
		else {
			ty[i] = 1, Id[i] = Large;
			REP(j, tot) {
				int tmp = in();
				b[Large].push_back(tmp);
			}
			sort(b[Large].begin(), b[Large].end());
			Large++;
		}
	}
	init();
	while (q--) {
		int type = in();
		if (type == 1) {
			int id = in(), num = in();
			modify1(id, num);
		}
		else if (type == 2) {
			int id = in();
			out(query1(id));
		}
		else if (type == 3) {
			int l = in(), r = in(), num = in();
			modify2(l, r, num);
		}
		else {
			int l = in(), r = in();
			out(query2(l, r));
		}
	}
    return 0;
}
