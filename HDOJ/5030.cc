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
	
	void build(const T *str, int x) {//x 是未处理的str的长度
		n = x;
        REP(i, n) s[i] = str[i];
        s[n++] = int('$'), s[n] = 0;
		getSA(256), getHeight();
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

int *rk = SA.rank, *sa = SA.sa, *height = SA.height, n, k, mark[N];
LL cnt[N];

bool check(int head, int tail) {
    //cout << "head tail: " << head << ' ' << tail << endl;
    //for (int i = head; i < tail; i++) putchar(s[i]);
    //puts("");
    fill(mark, mark + n + 1, -1);
    mark[head] = tail - 1;
    int lcp = min(n + 1, tail - head);
    REPP(i, rk[head] + 1, n) {
        lcp = min(lcp, height[i]);
        if (lcp == 0) return 0;
        mark[sa[i]] = sa[i] + lcp - 1;
    }
    int need = n, cnt = 0;
    REP(i, n) {
        if (mark[i] >= 0) {
            need = min(need, mark[i]);
        }
        if (need == i) {
            if (i != n - 1) cnt++;
            if (cnt > k) return 0;
            need = n;
        }
    }
    return cnt < k;
}

void solve() {
    REPP(i, 1, n) cnt[i] = cnt[i - 1] + n - sa[i] - height[i];
    //REPP(i, 1, n) {
    //    cout << i << ' ' << cnt[i] << endl;
    //}
    LL lo = 0, hi = cnt[n];
    while (lo + 1 < hi) {
        LL mid = (lo + hi) >> 1;
        //cout << "hehe" << ' ' << mid << endl;
        int pos = lower_bound(cnt + 1, cnt + n + 1, mid) - cnt;
        //cout << "pos " << pos << endl;
        int head = sa[pos];
        int tail = head + height[pos] + mid - cnt[pos - 1];
        if (check(head, tail)) hi = mid;
        else lo = mid;
    }
    int pos = lower_bound(cnt + 1, cnt + n + 1, hi) - cnt;
    int head = sa[pos];
    int tail = head + height[pos] + hi - cnt[pos - 1];
    for (int i = head; i < tail; i++) putchar(s[i]);
    puts("");
}

int main() {
#ifdef HOME
    freopen("tmp.in", "r", stdin);
#endif

    //clock_t st, ed, sum;

    while (scanf("%d", &k), k) {
        scanf("%s", s);
        n = strlen(s);
        //puts(s);
        //st = clock();
        SA.build(s, n);
        //ed = clock();
        //sum += ed - st;
        //SA.print();
        solve();
    }
    //clock_t ed = clock();
    //cout << fixed << setprecision(10) << 1.0 * sum / CLOCKS_PER_SEC << endl;
    return 0;
}
