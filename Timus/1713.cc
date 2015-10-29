#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define next nex

using namespace std;

const int N = 111111;

struct Suffix_Array {
	int s[N], sa[N], a[N], b[N], c[N], n;
	int r[N], hg[N]; 
	//sa[i] 0base sa[0] = n 后缀数组排名i的后缀是第几个后缀
	//rank[i] 0base 第i个后缀在后缀数组里面的排名
	//height[i] sa[i]和sa[i-1]的最长公共前缀, hg[0] = 0, hg[1] = 0;
	
	void init(int x) {
		n = x;
		getsa(2048), gethg();
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

int pre[N], next[N], L[N], R[N];
int n, ans[N], id[N], start[N];
char s[N];

int main() {
	ios :: sync_with_stdio(0);
	//freopen("in", "r", stdin);

	scanf("%d", &n);
	int now = 0;
	REPP(i, 1, n) {
		scanf("%s", s);
		int length = strlen(s);
		ans[i] = length + 1;
		REP(j, length) {
			id[now] = i;
			SA.s[now++] = s[j] - 'a' + 1000;
		}
		id[now] = -i;
		SA.s[now++] = i - 1;
	}
	SA.init(now);
	int *hg = SA.hg, *sa = SA.sa;
	REPP(i, 1, now - 1) pre[i] = i - 1, L[i] = hg[i];
	for (int i = now - 1; i >= 1; i--) {
		next[i] = i + 1; 
		R[i] = hg[i + 1];
	}
	REPP(i, 1, now - 1) {
		while (pre[i] && abs(id[sa[i]]) == abs(id[sa[pre[i]]])) {
			L[i] = min(L[i], L[pre[i]]);
			pre[i] = pre[pre[i]];
		}
	}
	for (int i = now - 1; i >= 1; i--) {
		while (next[i] < now && abs(id[sa[i]]) == abs(id[sa[next[i]]])) {
			R[i] = min(R[i], R[next[i]]);
			next[i] = next[next[i]];
		}
	}
	//REPP(i, 1, now - 1) {
	//	cout << pre[i] << ' ';
	//}
	//cout << endl;
	//REPP(i, 1, now - 1) {
	//	cout << L[i] << ' ';
	//}
	//cout << endl;
	//REPP(i, 1, now - 1) {
	//	cout << next[i] << ' ';
	//}
	//cout << endl;
	//REPP(i, 1, now - 1) {
	//	cout << R[i] << ' ';
	//}
	//cout << endl;
	REPP(i, 1, n) ans[i] = N;
	//SA.output();
	REPP(i, 1, now - 1) if (id[sa[i]] >= 0) { 
		int suffix = sa[i];
		int tmp = max(L[i], R[i]) + 1;
		if (id[suffix] == id[suffix + tmp - 1] && ans[id[suffix]] > tmp) {
			ans[id[suffix]] = tmp;
			start[id[suffix]] = suffix;
		}
	}
	REPP(i, 1, n) {
		REP(j, ans[i]) {
			putchar(SA.s[start[i] + j] - 1000 + 'a');
		}
		puts("");
	}
	return 0;
}
