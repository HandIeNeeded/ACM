#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 5e5 + 5;

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
        REP(i, n) s[i] = str[i] + 10;
        s[n++] = 1, s[n] = 0;
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

char s[N];
int id[N << 2], *rk = SA.rank, *sa = SA.sa;

int add(int l, int r) {
    if (rk[l - 1] > rk[r - 1]) return l;
    else return r;
}

void build(int x, int l, int r) {
    if (l == r) {
        //cout << l << ' ' << rk[l - 1] << ' ' << sa[l - 1] << endl;
        id[x] = l;
        //cout << "id[" << x << "] " << id[x] << endl;
    }
    else {
        build(LC), build(RC);
        id[x] = add(id[L], id[R]);
        //cout << "id[" << x << "] " << "l r" << l << ' ' << r << ' ' << id[x] << endl;
    }
}

int ql, qr;

int query(int x, int l, int r) {
    if (ql <= l && qr >= r) {
        return id[x];
    }
    else {
        if (ql > MID) return query(RC);
        if (qr <= MID) return query(LC);
        int a = query(LC), b = query(RC);
        return add(a, b);
    }
}

int main() {
#ifdef HOME
    freopen("D.in", "r", stdin);
#endif

    scanf("%s", s);
    int n = strlen(s);
    SA.build(s, n);
    //SA.print();

    build(1, 1, n);
    //cout << n << endl;

    int q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &ql, &qr);
        printf("%d\n", query(1, 1, n));
    }

    return 0;
}


