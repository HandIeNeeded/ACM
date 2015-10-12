#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 55;

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

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif


    return 0;
}


