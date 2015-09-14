#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 4e4 + 5;

char s[N], r[N];
int n;

//获得字符串s的最小表示,会将字符串扩展成2倍长.
//返回值是最小表示的起始位置在原串中的最先的位置
int MSR(char *s, int type) {
	int a = 0, b = 1, c = 0;
	REP(i, n) s[i + n] = s[i];
	s[n << 1] = 0;
	while (a < n && b < n && c < n) {
		int tmp = s[a + c] - s[b + c];
		if (!tmp) c++;
		else {
			if (tmp < 0) a += c + 1; //最大表示这里改一下
			else b += c + 1;
			if (a == b) b++;
			c = 0;
		}
	}
    if (type) {
        if (c == n) {
            int d = b - a;
            a %= d;
            a = d - a;
            return n - a;
        }
    }
	return a;
}

bool cmp(int a, int b) {
    char *ts = s + a, *tr = r + b;
    REP(i, n) {
        if (*ts != *tr) {
            if (*ts > *tr) return 1;
            else return 0;
        }
        ts++, tr++;
    }
    return a <= n - 1 - b;
}

int main() {
#ifdef HOME
    freopen("6.in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%s", s);
        if (n == 1) {
            printf("1 0\n");
            continue;
        }
        for (int i = n - 1, j = 0; i >= 0; i--, j++) {
            r[j] = s[i];
        }
        REP(i, n) s[i + n] = s[i];
        REP(i, n) r[i + n] = r[i];
        s[n << 1] = r[n << 1] = 0;
        int a = MSR(s, 0);
        int b = MSR(r, 1);
        assert(a < n), assert(b < n);
        if (cmp(a, b)) {
            printf("%d %d\n", a + 1, 0);
        }
        else {
            printf("%d %d\n", n - 1 - b + 1, 1);
        }
    }
    return 0;
}

