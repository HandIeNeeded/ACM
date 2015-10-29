#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 500;

struct Suffix_Array {
	int s[N], sa[N], a[N], b[N], c[N], n;
	int r[N], hg[N]; 
	//sa[i] 0base sa[0] = n 后缀数组排名i的后缀是第几个后缀
	//rank[i] 0base 第i个后缀在后缀数组里面的排名
	//height[i] sa[i]和sa[i-1]的最长公共前缀, hg[0] = 0, hg[1] = 0;
	
	void init(int x) {
		n = x;
		getsa(256), gethg();
	}

	//m字符集大小
	void getsa(int m) {
		int *x = a, *y = b;
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
		REP(i, n) cout << sa[i] << " \n"[i == n - 1];
		REP(i, n) cout << hg[i] << " \n"[i == n - 1];
	}
}SA;

char s[N];

int main() {
	ios :: sync_with_stdio(0);
	
	int n;
	cin >> s;
	n = strlen(s);
	s[n++] = '#';
	REP(i, n) SA.s[i] = s[i];
	SA.init(n);
	//SA.output();
	int ans = 0, length = 1, begin = 0;
	REPP(i, 1, n - 1) {
		int j = i, mi = 100, start = -1;
		while (j + 1 < n && SA.hg[j + 1] > 0) {
			j++;
			if (mi > SA.hg[j]) {
				mi = SA.hg[j]; 
				start = SA.sa[j];
			}
		}
		if (j - i > ans) {
			ans = j - i;
			length = mi;
			begin = start;
		}
		i = j;
	}
	REP(i, length) {
		cout << s[begin + i];
	}
	cout << endl;

	return 0;
}

