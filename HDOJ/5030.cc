#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
const int L = 17;

int dp[N][L];
char s[N];

// DC3算法构造后缀数组 O(n)
// sa[i] 表示排名为 i 的后缀, rank[i]表示第i个后缀的排名, height[i] 表示 sa[i] 与 sa[i - 1] 最长公共前缀
// 求出的rank, height, sa数组和倍增算法求得的完全一样
// 支持对于任意类型子序列进行求解，注意原序列中所有数据为正，原序列范围较大需要离散化
// 注意需要手动调用 getHeight()

#define N 100010
#define F(x) ((x) / 3 + ((x) % 3 == 1 ? 0 : ty))
#define G(x) ((x) < ty ? (x) * 3 + 1 : ((x) - ty) * 3 + 2)

template<typename T = char>
struct SuffixArray {
    int str[N * 3], sa[N * 3], rank[N], height[N], sz;
    int wa[N], wb[N], wv[N], ws[N];

    int &operator [](int k) { return sa[k]; }

    int size() const { return sz; }

    bool equal(const int *r, int a, int b) const {
        return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2];
    }

    bool cmp(const int *r, int a, int b, int d) const {
        if (d == 1) return (r[a] < r[b]) || (r[a] == r[b] && wv[a + 1] < wv[b + 1]);
        return (r[a] < r[b]) || (r[a] == r[b] && cmp(r, a + 1, b + 1, 1));
    }

    void rsort(const int *r, const int *a, int *b, int n, int m) {
        int i;
        fill(ws, ws + m, 0);
        for (i = 0; i < n; ++i) ++ws[wv[i] = r[a[i]]];
        for (i = 1; i < m; ++i) ws[i] += ws[i - 1];
        for (i = n - 1; ~i; --i) b[--ws[wv[i]]] = a[i];
    }

    void dc3(int *r, int *sa, int n, int m) {
        int i, j, k, *rn = r + n, *san = sa + n, tx = 0, ty = (n + 1) / 3, tz = 0;

        r[n] = r[n + 1] = 0;
        for (i = 0; i < n; ++i) {
            if (i % 3) wa[tz++] = i;
        }
        rsort(r + 2, wa, wb, tz, m);
        rsort(r + 1, wb, wa, tz, m);
        rsort(r, wa, wb, tz, m);
        for (rn[F(wb[0])] = 0, k = i = 1; i < tz; ++i) {
            rn[F(wb[i])] = equal(r, wb[i - 1], wb[i]) ? k - 1 : k++;
        }
        if (k < tz) dc3(rn, san, tz, k);
        else {
            for (i = 0; i < tz; ++i) san[rn[i]] = i;
        }
        for (i = 0; i < tz; ++i) {
            if (san[i] < ty) wb[tx++] = san[i] * 3;
        }
        if (n % 3 == 1) wb[tx++] = n - 1;
        rsort(r, wb, wa, tx, m);
        for (i = 0; i < tz; ++i) wv[wb[i] = G(san[i])] = i;
        for (i = j = k = 0; i < tx && j < tz; ++k) {
            sa[k] = cmp(r, wa[i], wb[j], wb[j] % 3) ? wa[i++] : wb[j++];
        }
        for ( ; i < tx; ++i) sa[k++] = wa[i];
        for ( ; j < tz; ++j) sa[k++] = wb[j];
    }

    void build(const T *s, int n, int m = 128) {//n 是原串长度不做任何修改 n==1没有问题
        int i;
        for (i = 0; i < n; ++i) str[i] = (int)s[i];
        str[n] = 0; sz = n + 1;
        dc3(str, sa, sz, m);
    }

    void getHeight() {
        int i, j, k = 0;
        for (i = 0; i < sz; ++i) rank[sa[i]] = i;
        for (i = 0; i < sz; height[rank[i++]] = k) {
            for(k ? --k : 0, j = sa[rank[i] - 1]; str[i + k] == str[j + k]; ++k);
        }
    }

	void print(){
		REP(i, sz) cout << sa[i] << " \n"[i == sz - 1];
		REP(i, sz) cout << rank[i] << " \n"[i == sz - 1];
		REP(i, sz) cout << height[i] << " \n"[i == sz - 1];
	}
};
SuffixArray<char> SA;
int main() {
#ifdef HOME
    freopen("tmp.in", "r", stdin);
#endif

    int k;
    while (scanf("%d", &k), k) {
        scanf("%s", s);
        int n = strlen(s);
        //puts(s);
        SA.build(s, n, 256);
        SA.getHeight();
        SA.print();
    }
    return 0;
}
