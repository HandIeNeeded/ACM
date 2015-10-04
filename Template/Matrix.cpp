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

Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix c;
    REP(i, N) REP(j, N) REP(k, N) {
        add(c[i][j], 1LL * a[i][k] * b[k][j] % MO);
    }
    return c;
}
