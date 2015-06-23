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
int n, q, dp[N];

int main() {
	scanf("%s", s);
	n = strlen(s);
	s[n++] = '#';
	REP(i, n) SA.s[i] = s[i];
	SA.Init(n);
	REP(i, n) {
		int rank = SA.r[i];
		dp[i] = max(SA.hg[rank], SA.hg[rank + 1]);
	}
	//SA.output();
	scanf("%d", &q);
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--, r--;
		int ans = 0;
		REPP(i, l, r) {
			ans += max(r - i + 1 - dp[i], 0);
		}
		printf("%d\n", ans);
	}

    return 0;
}


