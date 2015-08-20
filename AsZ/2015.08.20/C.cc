#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 55;
const int MO = 1e9 + 7;

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}

struct Matrix{
    int a[N][N];
    Matrix(int ident = 0) {
        MST(a, 0);
        if (ident) {
            REP(i, N) a[i][i] = 1;
        }
    }

    int* operator [] (int i) {
        return a[i];
    }

    const int* operator [] (int i) const {
        return a[i];
    }
};

Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix res;
    REP(i, N) {
        REP(j, N) {
            REP(k, N) {
                add(res[i][j], 1LL * a[i][k] * b[k][j] % MO);
            }
        }
    }
    return res;
}

Matrix pow_mod(Matrix a, int b) {
    Matrix res(1);
    while (b) {
        if (b & 1) {
            res = res * a;
        }
        b >>= 1;
        a = a * a;
    }
    return res;
}

string getStr(int x) {
    string s;
    if (x == 0) s = "0";
    else {
        while (x) {
            s += '0' + x % 10;
            x /= 10;
        }
        reverse(s.begin(), s.end());
    }
    return s;
}

string s[N];
char tmp[N];

int calc(const string &s, const string &r) {
    int length = min(s.size(), r.size());
    for (int i = 2; i <= length; i++) {
        if (s.substr(0, i) == r.substr(r.size() - i)) {
            return 1;
        }
    }
    return 0;
}

int main() {
#ifdef HOME
    freopen("C.in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        REP(i, n) {
            scanf("%s", tmp);
            s[i] = string(tmp);
        }
        sort(s, s + n);
        n = unique(s, s + n) - s;
        Matrix start, fun;
        REP(i, n) start[0][i] = 1;
        REP(i, n) {
            REP(j, n) {
                fun[j][i] = calc(s[i], s[j]);
            }
        }
        start = start * pow_mod(fun, m - 1);
        int ans = 0;
        REP(i, n) add(ans, start[0][i]);
        printf("%d\n", ans);
    }

    return 0;
}

