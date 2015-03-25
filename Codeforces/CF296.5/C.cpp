#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define PII pair<int, int>

using namespace std;

const int N = 1e5 + 5;

int head[N], node;
PII p[N << 1];
pair<bool, bool> ans[N << 1];
string answer[2] = {"NO", "YES"};

struct sgt{
	int l, r, cnt;
}tr[N * 20];

int New_Node() {
	tr[node].l = tr[node].r = tr[node].cnt = 0;
	return node++;
}

void update(int &now, int pre, int num, int l, int r) {
	now = New_Node();
	if (l == r) {
		tr[now].cnt = tr[pre].cnt + 1;
		return ;
	}
	int mid = (l + r) >> 1;
	if (num <= mid) {
		update(tr[now].l, tr[pre].l, num, l, mid);
		tr[now].r = tr[pre].r;
	}
	else {
		update(tr[now].r, tr[pre].r, num, mid + 1, r);
		tr[now].l = tr[pre].l;
	}
	tr[now].cnt = tr[tr[now].l].cnt + tr[tr[now].r].cnt;
}

bool query(int now, int pre, int l, int r, int ql, int qr) {
	if (ql <= l && qr >= r) {
		return tr[now].cnt - tr[pre].cnt == r - l + 1;
	}
	int mid = (l + r) >> 1;
	bool ans = 1;
	if (ql <= mid) ans &= query(tr[now].l, tr[pre].l, l, mid, ql, qr);
	if (ans && qr > mid) ans &= query(tr[now].r, tr[pre].r, mid + 1, r, ql, qr);
	return ans;
}

struct Query{
	PII a, b;
	int id;
};

vector<Query> Q[2][N];
int len[2], pre[N];

void add(int x, int d) {
	while (x < N) {
		s[x] += d;
		x += LB(x);
	}
}

int query(int x, int d) {
	int ans = 0;
	while (x) {
		ans += s[x];
		x -= LB(x);
	}
	return ans;
}

void solve(int k) {
	REP(j, 2) {
		sort(p + 1, p + k + 1);
		int now = 1;
		REPP(i, 1, len[j ^ 1]) pre[i] = 0;
		REPP(i, 1, len[j]) {
			while (now <= k && p[now].first == i) {
				if (pre[p[now].second]) {
					add(pre[p[now].second], -1);
				}
				pre[p[now++].second] = i;
				add(i, 1);
			}
			if (j == 0) {
				for (auto tmp: Q[j][i]) {
					ans[tmp.id].first = query(head[tmp.b.first], head[tmp.a.first - 1], 1, len[j ^ 1], tmp.a.second, tmp.b.second);
					ans[tmp.id].first = query(tmp.b.first) -  query(tmp.a.first - 1) == 
				}
			}
			else {
				for (auto tmp: Q[j][i]) {
					ans[tmp.id].second = query(head[tmp.b.second], head[tmp.a.second - 1], 1, len[j ^ 1], tmp.a.first, tmp.b.first);
				}
			}
		}
		REPP(i, 1, k) swap(p[i].first, p[i].second);
	}
}

int main() {
	freopen("C.in", "r", stdin);
	ios :: sync_with_stdio(0);
	int k, q;
	cin >> len[0] >> len[1] >> k >> q;
	REPP(i, 1, k) {
		int x, y;
		cin >> x >> y;
		p[i] = {x, y};
	}
	REP(i, q) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		Query tmp = {{a, b}, {c, d}, i};
		Q[0][c].push_back(tmp);
		Q[1][d].push_back(tmp);
	}
	solve(k);
	REP(i, q) {
		cout << answer[ans[i].first || ans[i].second] << endl;
	}

	return 0;
}

