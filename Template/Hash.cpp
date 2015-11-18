const int X1 = 4243;
const int MOD1 = 1e9 + 7;
const int X2 = 10007;
const int MOD2 = 42424243;
const int LEN = 3e5 + 5;

struct hash {
    int a, b;

    hash() {}
    hash(int a) : a(a), b(a) {}
    hash(int a, int b) : a(a), b(b) {}
};

bool operator < (const hash& a, const hash& b) {
    if (a.a != b.a) {
        return a.a < b.a;
    }
    return a.b < b.b;
}

bool operator == (const hash& a, const hash& b) {
    return a.a == b.a && a.b == b.b;
}

hash operator * (const hash& a, const hash& b) {
    return hash((1LL * a.a * b.a) % MOD1, (1LL * a.b * b.b) % MOD2);
}

hash operator + (const hash& a, const hash& b) {
    hash c(a.a + b.a, a.b + b.b);
    if (c.a >= MOD1) {
        c.a -= MOD1;
    }
    if (c.b >= MOD2) {
        c.b -= MOD2;
    }
    return c;
}

const hash X(X1, X2);

inline void init() {
    pw[0] = hash(1);
    for (int i = 1; i < LEN; ++i) {
        pw[i] = pw[i - 1] * X;
    }
}
