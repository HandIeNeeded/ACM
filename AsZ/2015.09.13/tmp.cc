#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
char s[N];
//获得字符串s的最小表示,会将字符串扩展成2倍长.
//返回值是最小表示的起始位置在原串中的特殊位置
int MSR(char *s, int type) {//type 0 最前的位置, 1 最后的位置
	int a = 0, b = 1, c = 0;
    int n = strlen(s);
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


int main() {
#ifdef HOME
    //freopen("in", "r", stdin);
#endif

    while (cin >> s) {
        cout << MSR(s, 0) << endl;
    }

    return 0;
}

