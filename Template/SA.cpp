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

// DC3算法构造后缀数组 O(n)
// sa[i] 表示排名为 i 的后缀, rank[i]表示第i个后缀的排名, height[i] 表示 sa[i] 与 sa[i - 1] 最长公共前缀
// 求出的rank, height, sa数组和倍增算法求得的完全一样
// 支持对于任意类型子序列进行求解，注意原序列中所有数据为正，原序列范围较大需要离散化

#define F(x) ((x) / 3 + ((x) % 3 == 1 ? 0 : ty))
#define G(x) ((x) < ty ? (x) * 3 + 1 : ((x) - ty) * 3 + 2)

template<typename T = char>
struct SuffixArray {
    int str[N * 3], sa[N * 3], rank[N], height[N], n;
    int wa[N], wb[N], wv[N], ws[N];

    int &operator [](int k) { return sa[k]; }

    int size() const { return n; }

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

    void build(const T *s, int x, int m = 256) {//x 是原串长度不做任何修改 x==1没有问题
        int i;
        for (i = 0; i < x; ++i) str[i] = (int)s[i];
        str[x] = 0; n = x + 1;
        dc3(str, sa, n, m);
        getHeight();
    }

    void getHeight() {
        int i, j, k = 0;
        for (i = 0; i < n; ++i) rank[sa[i]] = i;
        for (i = 0; i < n; height[rank[i++]] = k) {
            for(k ? --k : 0, j = sa[rank[i] - 1]; str[i + k] == str[j + k]; ++k);
        }
    }

    void print(){
        REP(i, n) cout << sa[i] << " \n"[i == n - 1];
        REP(i, n) cout << rank[i] << " \n"[i == n - 1];
        REP(i, n) cout << height[i] << " \n"[i == n - 1];
    }
};
SuffixArray<char> SA;

