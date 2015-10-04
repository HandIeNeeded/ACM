#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
char s[N];

template<typename T = int>
struct SuffixArray {
	int s[N], sa[N], a[N], b[N], c[N], n;
	int rank[N], height[N]; 
	//sa[i] 0base sa[0] = n 后缀数组排名i的后缀是第几个后缀
	//rank[i] 0base 第i个后缀在后缀数组里面的排名
	//height[i] sa[i]和sa[i-1]的最长公共前缀, height[0] = 0, height[1] = 0;
    //结构体里的n比实际串长大1
	
	void build(const T *str, int x, int m = 256) {//x 是未处理的str的长度
		n = x;
        REP(i, n) s[i] = str[i];
        s[n++] = int('$'), s[n] = 0;
		getSA(m), getHeight();
	}

	void getSA(int m) {//m 字符集大小
		int *x = a, *y = b;
        fill(c, c + m, 0);
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

	void getHeight(){
		REP(i, n) rank[sa[i]] = i;
		int k = 0;
		REP(i, n) {
			if (k) k--;
			int j = sa[rank[i] - 1];
			while (s[i + k] == s[j + k]) k++;
			height[rank[i]] = k;
		}
	}

	void print(){
		REP(i, n) cout << sa[i] << " \n"[i == n - 1];
		REP(i, n) cout << rank[i] << " \n"[i == n - 1];
		REP(i, n) cout << height[i] << " \n"[i == n - 1];
	}
};
SuffixArray<char> SA;

int main() {
#ifdef HOME
    freopen("tmp.in", "r", stdin);
#endif

    cin >> s;
    int n = strlen(s);
    SA.build(s, n);
    SA.print();

    return 0;
}
