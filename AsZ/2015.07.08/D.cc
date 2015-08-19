#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define ALL(a) (a).begin(), (a).end()
#define id(a) ((a) / BLK)

using namespace std;

const int N = 2e5 + 5;

struct Query{
	int l, r, id, blk;
}q[N], Q[N];

int n, m, BLK, L, R, tot;
vector<int> num;
int cnt[N], ans[N], a[N], pre[N], pos[N];

bool cmp(Query a, Query b) {
	return a.blk < b.blk || (a.blk == b.blk && a.r < b.r);
}

bool cmp1(Query a, Query b) {
	return a.l > b.l;
}

int res;

int query(int l, int r) {
	if (id(l) != id(L)) {
		REP(i, tot) cnt[i] = 0;
		L = INT_MAX, R = INT_MIN;
		res = 0;
	}
	int bound = (l / BLK + 1) * BLK;
	for (int i = max(bound, R + 1); i <= r; i++) {
		if (cnt[a[i]] == 0) {
			res++;
		}
		cnt[a[i]]++;
	}
	int ans = res;
	for (int i = l; i < min(r + 1, bound); i++) {
		if (cnt[a[i]] == 0) {
			res++;
		}
		cnt[a[i]]++;
	}
	L = l, R = r;
	swap(ans, res);
	for (int i = l; i < min(r + 1, bound); i++) {
		cnt[a[i]]--;
	}
	return ans;
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	scanf("%d", &n);
	REP(i, n) {
		scanf("%d", a + i);
		num.push_back(a[i]);
	}
	sort(ALL(num));
	num.resize(unique(ALL(num)) - num.begin());
	tot = num.size();
	REP(i, n) a[i] = lower_bound(ALL(num), a[i]) - num.begin();
	REP(i, tot) pos[i] = -1;
	REP(i, n) {
		pre[i] = pos[a[i]];
		pos[a[i]] = i;
	}
	BLK = int(sqrt(n + 0.5)) + 1;
	scanf("%d", &m);
	REP(i, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y += x - 1;
		Q[i] = {x, y, i, 0};
	}
	sort(Q, Q + m, cmp1);
	REP(i, m) {
		int l = Q[i].l, r = Q[i].r;
		while (pre[pos[a[r]]] >= l) {
			pos[a[r]] = pre[pos[a[r]]];
		}
		q[i] = {l, pos[a[r]], Q[i].id, id(l)};
	}
	sort(q, q + m, cmp);
	L = INT_MAX, R = INT_MIN;
	REP(i, m) {
		ans[q[i].id] = query(q[i].l, q[i].r);
	}
	REP(i, m) {
		printf("%d\n", ans[i]);
	}

	return 0;
}

