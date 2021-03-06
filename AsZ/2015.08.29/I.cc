#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
int a[N], b[N];
char c[N];
int add, now;

int get(int x, int y, char z) { //nowth operation use the xth and yth n to get a new number and append it to the add position
    a[now] = x, b[now] = y, c[now] = z;
    now++;
    return ++add;
}

int get(int a, int b, int c, const string &s) {
    int pre = 0;
    REP(i, s.size()) {
        if (i == 0) pre = get(a, b, s[i]);
        else {
            pre = get(pre, c++, s[i]);
        }
    }
    return pre;
}

void solve(int n) {
    if (n > 24) {
        if (n & 1) {
            string s;
            REP(i, 23) s += '+';
            s += '/';
            int pre = get(1, 2, 3, s);
            int now = 26;
            REP(i, (n - 25) / 2) {
                pre = get(pre, now++, '+');
                pre = get(pre, now++, '-');
            }
        }
        else {
            string s;
            REP(i, 22) s += '+';
            s += '/';
            int pre = get(1, 2, 3, s);
            int a = get(25, 26, '/');
            pre = get(pre, a, '+');
            int now = 27;
            REP(i, (n - 26) / 2) {
                pre = get(pre, now++, '+');
                pre = get(pre, now++, '-');
            }
        }
    }
    else if (n == 24) {
        int pre = get(1, 2, '+');
        pre = get(pre, 3, '/');
        int a = get(4, 5, '/');
        pre = get(pre, a, '-');
        a = get(6, 7, '/');
        pre = get(pre, a, '-');
        pre = get(pre, 8, '+');
        int now = 9;
        REP(i, 8) {
            pre = get(pre, now++, '+');
            pre = get(pre, now++, '-');
        }
    }
    else if (n >= 13 && n < 24) {
        string s;
        REP(i, 24 - n - 1) s += '+';
        s += "/+";
        int pre = get(1, 2, 3, s);
        int now = 24 - n + 3;
        REP(i, (2 * n - 26) / 2) {
            pre = get(pre, now++, '+');
            pre = get(pre, now++, '-');
        }
    }
    else if (n == 12) {
        int pre = get(1, 2, '+');
        int now = 3;
        REP(i, 5) {
            pre = get(pre, now++, '+');
            pre = get(pre, now++, '-');
        }
    }
    else if (n == 11) {
        string s = "+/++";
        int pre = get(1, 2, 3, s);
        int now = 6;
        REP(i, 3) {
            pre = get(pre, now++, '+');
            pre = get(pre, now++, '-');
        }
    }
    else if (n == 10) {
        int a[5];
        REPP(i, 1, 4) a[i] = get(2 * i - 1, 2 * i, '/');
        a[0] = get(9, 10, '+');
        int pre = get(a[0], a[1], '+');
        REP(i, 3) {
            pre = get(pre, a[i + 2], '+');
        }
    }
    else if (n == 9) {
        string s = "++/";
        int pre = get(1, 2, 3, s);  
        pre = get(5, pre, '-');
        s = "++*/";
        get(pre, 6, 7, s);
    }
    else if (n == 8) {
        int a = get(1, 2, '/');
        int b = get(3, 4, '/');
        string s = "+*+*/";
        get(a, b, 5, s);
    }
    else if (n == 7) {
        int pre = get(1, 2, '+');
        pre = get(pre, 3, '+');
        pre = get(pre, 4, '/');
        REP(i, 3) pre = get(pre, i + 5, '+');
    }
    else if (n == 6) {
        int pre = get(1, 2, '+');
        REP(i, 2) pre = get(pre, i + 3, '+');
        pre = get(pre, 5, '/'); 
        pre = get(pre, 6, '*'); 
    }
    else if (n == 5) {
        int a = get(1, 2, '/');
        int b = get(a, 3, '/');
        int c = get(4, b, '-');
        get(c, 5, '*');
    }
    else if (n == 4) {
        get(1, 2, '*');
        get(5, 3, '+');
        get(6, 4, '+');
    }
    else return ;
}

int main() {
#ifdef HOME
    freopen("I.in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) > 0) {
        //printf("%d\n", n);
        now = 1, add = n;
        if (n <= 3) {
            puts("-1");
        }
        else {
            solve(n);
            REPP(i, 1, n - 1) {
                printf("%d %c %d\n", a[i], c[i], b[i]);
            }
        }
    }
    return 0;
}

