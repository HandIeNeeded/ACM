#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int NN = 1000007;
const int MO = 1e9 + 7;
short sg[NN];
int cnt[NN][4];

int calc(int x) {
    if (x < 10) return sg[x] = 0;
    else if (sg[x] >= 0) return sg[x];
    else {
        int bit[10];
        int len = 0;
        int tmp = x;
        while (x) {
            bit[len++] = x % 10;
            x /= 10;
        }
        bitset<5> vis;
        REPP(i, 1, len - 1) {
            int now = 0;
            for (int j = len - 1; j > i; j--) {
                now = now * 10 + bit[j];
            }
            int d = (bit[i] + bit[i - 1]) % 10;
            now = now * 10 + d;
            for (int j = i - 2; j >= 0; j--) {
                now = now * 10 + bit[j];
            }
            vis[sg[now]] = 1;
        }
        x = tmp;
        short &ans = sg[x];
        ans = 0;
        while (vis.test(ans)) ans++;
        return ans;
    }
}

const int N = 4;
struct Matrix {
    int a[N][N];

    Matrix (bool ident = 0) {
        MST(a, 0);
        if (ident) {
            REP(i, N) a[i][i] = 1;
        }
    }

    int* operator [] (int i){
        return a[i];
    }

    const int* operator [] (int i) const {
        return a[i];
    }
};

void add(int &x, int y) {
    x += y;
    if (x >= MO) x -= MO;
}

Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix c;
    REP(i, N) REP(j, N) REP(k, N) {
        add(c[i][j], 1LL * a[i][k] * b[k][j] % MO);
    }
    return c;
}

Matrix pow_mod(Matrix a, int n) {
    Matrix ans(1);
    while (n) {
        if (n & 1) ans = ans * a;
        n >>= 1;
        a = a * a;
    }
    return ans;
}

Matrix f[4];

void init() {
    REP(i, 4) {
        f[i] = Matrix(1);
        REP(j, 4) {
            f[i][j ^ i][j]++;
        }
    }
}

int main() {
#ifdef HOME
    freopen("tmp.in", "r", stdin);
#endif
    init();
    //REP(i, 4) {
    //    REP(j, 4) {
    //        REP(k, 4) {
    //            cout << f[i][j][k] << ' ';
    //        }
    //        cout << endl;
    //    }
    //    cout << endl;
    //}
    MST(sg, -1);
    REPP(i, 0, 1000000) {
        calc(i);
    }
    REPP(i, 1, 1000000) {
        REP(j, 4) {
            cnt[i][j] = cnt[i - 1][j] + (sg[i] == j);
        }
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        int a[4];
        REP(i, 4) a[i] = cnt[n][i];
        int now = 0;
        REPP(i, 1, m) {
            int x;
            scanf("%d", &x);
            now ^= sg[x];
            a[sg[x]]--;
        }
        Matrix start(0);
        start[0][0] = 1;
        REP(i, 4) start = start * pow_mod(f[i], a[i]);
        int ans = start[0][now];
        if (now == 0) add(ans, MO - 1);
        if (ans < 0) add(ans, MO);
        printf("%d\n", ans);
    }
    return 0;
}
