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

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define id(x) ((x) / BLK)

using namespace std;

const int N = 100005;

struct Suffix_Array {
	int s[N];
	int sa[N], t1[N], t2[N], c[N], n; 
	
	void Init(int x) { 
		n = x;
		getsa(256);
		gethg();
	}

	void getsa(int m) { 
		int *x = t1, *y = t2;
		MST(c, 0);
		REP(i, n) c[x[i] = s[i]]++; 
		REPP(i, 1, m - 1) c[i] += c[i - 1];
		for (int i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
		for(int k = 1; k <= n; k <<= 1) {
			int p = 0;
			for (int i = n - k; i < n; ++i) y[p++] = i;
			REP(i, n) if (sa[i] >= k) y[p++] = sa[i] - k;
			REP(i, m) c[i] = 0;
			REP(i, n) c[x[y[i]]]++;
			REPP(i, 1, m - 1) c[i] += c[i - 1];
			for (int i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
			swap(x, y);
			p = 1; x[sa[0]] = 0;
			REPP(i, 1, n - 1) {
				x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
			}
			if (p >= n) break;
			m = p;
		}
	}

	int r[N], hg[N]; // rank[], height[]

	void gethg(){
		REP(i, n) r[sa[i]] = i;
		int k = 0;
		REP(i, n) {
			if (k) k--;
			int j = sa[r[i] - 1];
			while (s[i + k] == s[j + k]) k++;
			hg[r[i]] = k;
		}
	}

	void output(){
		REP(i, n) cout << sa[i] << ' ';
		cout << endl;
		REP(i, n) cout << hg[i] << ' ';
		cout << endl;
	}
}SA;

char s[N];
int n, m, dp[N];
LL ans[N];
int BLK;

struct Query{
	int l, r, id;
}q[N];

bool cmp(Query a, Query b) {
	return id(a.l) < id(b.l) || (id(a.l) == id(b.l) && a.r < b.r);
}

int L, R, cnt;
LL res;
int num[N];

LL query(int l, int r) {
	if (id(l) != id(L)) {
		res = cnt = 0;
		REP(i, n) num[i] = 0;
		L = 1e7, R = -1e7;
	}
	int bound = (id(l) + 1) * BLK;
	for (int i = max(bound, R + 1); i <= r; i++) {
		num[i + dp[i] - 1]++;
		cnt += num[i - 1];
		res += cnt;
	}
	LL ans = res;
	for (int i = l; i < min(r + 1, bound); i++) {
		res += max(0, r - i + 1 - dp[i]);
	}
	swap(ans, res);
	L = l, R = r;
	//cout << ans << ' ' << res << "heh" << ' ' << cnt << endl;
	return ans;
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	s[n++] = '#';
	REP(i, n) SA.s[i] = s[i];
	SA.Init(n);
	REP(i, n) {
		int rank = SA.r[i];
		dp[i] = max(SA.hg[rank], SA.hg[rank + 1]);
		//cout << i << ' ' << dp[i] << endl;
	}
	//SA.output();
	scanf("%d", &m);
	BLK = int(sqrt(n + 0.5));
	REP(i, m) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--, r--;
		q[i] = (Query) {l, r, i};
	}
	sort(q, q + m, cmp);
	L = 1e7, R = -1e7;
	REP(i, m) {
		ans[q[i].id] = query(q[i].l, q[i].r);
	}
	REP(i, m) printf("%lld\n", ans[i]);

    return 0;
}

